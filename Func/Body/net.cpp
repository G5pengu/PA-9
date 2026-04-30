#include "../Header/net.hpp"

Network::Network()
{
	for (int i = 0; i < 10; i++)
	{
		leaderboard[i].score = 0;
		leaderboard[i].user = "";
	}
	ip = "255.255.255.255";
}
Network::~Network()
{}

// UDP Send and Receive the leader board
void Network::send()
{
	IpAddress ip = *IpAddress::resolve(this->ip);
	UdpSocket sock;
	Packet pack;
	for (int i = 0; i < 10; i++)
	{
		pack << leaderboard[i].user << leaderboard[i].score;

	}

	sock.send(pack, ip, port);
	cout << "package sent\n";
}
void Network::listen()
{
	UdpSocket sock;
	Packet pack;
	string x;
	sock.bind(port);

	std::optional<sf::IpAddress> sender;
	unsigned short receiverport;

	if (sock.receive(pack, sender, receiverport) == sf::Socket::Status::Done)
	{
		Leader lead[10];
		//unpacks the Leader board  from the UDP package
		for (int i = 0; i < 10; i++)
		{

			pack >> lead[i].user >> lead[i].score;;

		}
		merge_boards(lead);
	}


}

// loads and saves the leader board to a CSV
void Network::load(string Boardfile)
{
	fstream csv;
	csv.open(Boardfile);
	int i = 0;
	while (1) {
		string user;
		string score;

		if (!getline(csv, user, ',') || i > 9)
		{
			break;
		}
		getline(csv, score);
		leaderboard[i].user = user;
		if (score=="")
		{
			leaderboard[i].score = 0;
		}
		else
		{
			leaderboard[i].score = stof(score);
		}
		i++;
	}
}
void Network::save()
{
	fstream csv;
	csv.open("LeaderBoard.Csv");
	for (int i = 0; i < 10; i++)
	{
		std::string user = leaderboard[i].user;
		float score = leaderboard[i].score;
		csv << user << ',' << score << std::endl;
	}
}

//gets and sets the leader's in Leaderboard
Leader Network::getLeader(int pos)
{
	return leaderboard[pos];
}
void Network::setLeader(int pos, Leader newLeader)
{
	for (int i = 9; i > pos; i--)
	{
		leaderboard[i] = leaderboard[i - 1];
	}
	leaderboard[pos] = newLeader;
}
void Network::addLeader(Leader newLeader)
{
	for (int i = 0; i < 10; i++)
	{
		if (newLeader.score < leaderboard[i].score)
		{
			setLeader(i, newLeader);
			return;
		}
	}
}

//Debug print function, display leaderboard will be in Menu class
void Network::print_board()
{
	for (int i = 0; i < 10; i++)
	{
		cout << leaderboard[i].user << ", " << leaderboard[i].score << endl;
	}
}
void Network::merge_boards(Leader board[10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int u = 0; u < 10; u++)
		{
			if (board[i].user == leaderboard[u].user && board[i].score == leaderboard[u].score)
			{
				break;
			}
			if (board[i].score > leaderboard[u].score)
			{
				setLeader(u, board[i]);
				break;
			}
		}
	}
	save();
}

//Test cases
void Network::netTest()
{

}
void Network::cat()// pure debug test case, UwU
{
	load("assets/LeaderBoard.csv");
	//ip = "127.0.0.1"; for loop back 
	Network m;
	m.load("assets/Test.csv");

	cout << "strating listener thread\n";
	thread listener(&Network::listen, this);

	sleep(seconds(1));

	cout << "starting sender tread";
	thread sender(&Network::send, m);

	listener.join();
	sender.join();
	print_board();
}
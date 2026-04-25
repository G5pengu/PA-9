#include "net.hpp"

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
{
}

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
		//unpacks the Leader board  from the UDP package
		for (int i = 0; i < 10; i++)
		{
			
			pack >> leaderboard[i].user >> leaderboard[i].score;;
			
		}
	}
	
}

// loads and saves the leader board to a CSV
void Network::load(string Boardfile)
{
	fstream csv;
	csv.open(Boardfile);
	int i = 0;
	while(1){
		string user;
		string score;
		
		if (!getline(csv, user,',')||i>9)
		{
			break;
		}
		getline(csv, score);
		leaderboard[i].user = user;
		leaderboard[i].score = stof(score);
		i++;
	}
	save();
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

//gets and sets the leader board
Leader Network::getLeader(int pos)
{
	return leaderboard[pos];
}
void Network::setLeader(int pos, Leader newLeader)
{
	for (int i = 9; i > pos; i--)
	{
		leaderboard[i]= leaderboard[i-1];
	}
	leaderboard[pos] = newLeader;
}

//Debug print function, display leaderboard will be in Menu class
void Network::print_board()
{
	for (int i = 0; i < 10; i++)
	{
		cout << leaderboard[i].user <<", " << leaderboard[i].score<< endl;
	}
}
void Network::merge_boards(Leader board[10]) 
{
	for (int i = 0; i < 10; i++)
	{
		for(int u = 0; u < 10; u++)
		{
			if (board[i].score>leaderboard[u].score)
			{
				setLeader(u, board[i]);
				break;
			}
		}
	}
}

//Test cases
void Network::netTest()
{

}
void Network::cat()// pure debug test case
{
	load("Test.csv");
	ip = "127.0.0.1";

	cout << "strating listener thread\n";
	thread listener(&Network::listen, this);
	sleep(seconds(1));
	cout << "starting sender tread";
	thread sender(&Network::send, this);

	listener.join();
	sender.join();
	print_board();
}
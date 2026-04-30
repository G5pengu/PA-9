#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <SFML/Network.hpp>

using namespace std;
using namespace sf;
//If net.cpp complains about port being undifined, ignore it it will still build and work
const unsigned short port = 1435;

typedef struct
{
	std::string user;
	float score;
} Leader;

class  Network
{
public:
	Network();
	~Network();

	// UDP Send and Receive the leader board
	void send();
	void listen();

	// loads and saves the leader board to a CSV
	void load(string Boardfile = "assets/LeaderBoard.Csv");
	void save();

	//gets and sets the leader board
	Leader getLeader(int pos);
	void setLeader(int pos, Leader newLeader);
	void addLeader(Leader newLeader);

	bool netTest();
	void cat();//curiosity killed the cat

	void print_board();
	void merge_boards(Leader board[10]);

private:
	//An array of 10 leaders 
	Leader leaderboard[10];//ignore the red sqiggles they mean nothing if it still builds
	// the ip address being used Tests use the loopback address(127.0.0.1) while normal opperations use the broadcast address(255.255.255.255)
	string ip;
};
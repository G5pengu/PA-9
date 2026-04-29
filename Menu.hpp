#pragma once
#include "net.hpp"
#include "SFML/Graphics.hpp"
using namespace sf;
using namespace std;

class Menu : public Network
{
public:
	Menu();
	~Menu();

	void display_leaders();
	void menu();
	void canvas_test();

	Font font;

};
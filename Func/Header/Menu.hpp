#pragma once
#include "net.hpp"
#include "SoundManager.hpp"
#include "NoteTimeCalc.hpp"
#include "Button.hpp"
#include "Arrow.hpp"
#include "Game.hpp"
#include "Test.hpp"
#include "SFML/Graphics.hpp"


class Menu : public Network , public SoundManager , public NoteTimeCalc, public Game
{
public:
	Menu();
	~Menu();

	void display_leaders();
	void menu();
	void howto();
	void canvas_test();

	sf::Font font;
	bool continuePlaying;

};
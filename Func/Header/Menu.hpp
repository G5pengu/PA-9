#pragma once
#include "net.hpp"
#include "SoundManager.hpp"
#include "NoteTimeCalc.hpp"
#include "Button.hpp"
#include "Arrow.hpp"
#include "Game.hpp"
#include "SFML/Graphics.hpp"
using namespace sf;
using namespace std;

class Menu : public Network , public SoundManager , public NoteTimeCalc, public Game
{
public:
	Menu();
	~Menu();

	void display_leaders();
	void menu();
	void canvas_test();

	Font font;

};
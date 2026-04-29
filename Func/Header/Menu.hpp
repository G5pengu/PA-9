#pragma once
#include "../Header/net.hpp"
#include "../Header/SoundManager.hpp"
#include "../Header/NoteTimeCalc.hpp"
#include "../Header/Button.hpp"
#include "SFML/Graphics.hpp"
using namespace sf;
using namespace std;

class Menu : public Network , public SoundManager , public NoteTimeCalc
{
public:
	Menu();
	~Menu();

	void display_leaders();
	void menu();
	void canvas_test();

	Font font;

};
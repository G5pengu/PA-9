#pragma once

//Name: Zac Calvert
//Date: 4/29/2026

#include <iostream>
#include <SFML/Graphics.hpp>

#include "SFML/Graphics.hpp"
#include "net.hpp"
#include "SoundManager.hpp"
#include "NoteTimeCalc.hpp"
#include "Button.hpp"
#include "Arrow.hpp"
#include "Game.hpp"


class TestCases
{
public:
	TestCases();

	bool init();
	bool net();
	bool input();
	bool win();
	bool fail();
};


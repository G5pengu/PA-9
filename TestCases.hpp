#pragma once

//Name: Zac Calvert
//Date: 4/29/2026

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Func/Header/net.hpp"
#include "Func/Header/SoundManager.hpp"
#include "Func/Header/NoteTimeCalc.hpp"
#include "Func/Header/Button.hpp"
#include "Func/Header/Arrow.hpp"
#include "Func/Header/Game.hpp"

class TestCases
{
public:
	TestCases();

	bool init();
	void net();
	bool input();
	bool arrowSpawn();
	bool fail();
};


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
#include <fstream>
#include <vector>


class TestCases : public Network
{
public:
	TestCases();

	bool init();
	void net();
	bool input();
	bool arrowSpawn();
	bool windowTest();
};
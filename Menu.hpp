#pragma once

/*
* Author: Zac Calvert
* Date: 4/28/2026
*/

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Button.hpp"

#define MAX_NUMBER_ITEMS 2 //for exit button and play button

using std::vector;

class Menu 
{
public:
	Menu(float width, float height); 
	~Menu(); 

	void draw(sf::RenderWindow& window);
	void moveUp();
	void moveDown();

	//getters and setters
	int getSelectedItemIndex() const;
	void setSelectedItemIndex(int const newSelectedItemIndex);

private:
	//variables
	int mSelectedItemIndex;
	sf::Font font;
	sf::Text* menu[MAX_NUMBER_ITEMS]; //ptr so loading is smooth
};
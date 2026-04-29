#include "Menu.hpp"

/*
* Author: Zac Calvert
* Date: 4/28/2026
*/

Menu::Menu(float width, float height)
{
	mSelectedItemIndex = 0;

	if (!font.openFromFile("assets/TruenoBlack-mBYV.otf"))
	{
		printf("File was not able to open"); //error checking
	}

	//first button
	menu[0] = new sf::Text(font, "Play", 30);
	menu[0]->setFillColor(sf::Color::Blue); //had to look up why fill color was not working and turns out it was a difference in versions
	menu[0]->setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_ITEMS + 1)));

	//second button
	menu[1] = new sf::Text(font, "Exit", 30);
	menu[1]->setFillColor(sf::Color::Red);
	menu[1]->setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_ITEMS + 1) * 2));
}

Menu::~Menu()
{
	for (int i = 0; i < MAX_NUMBER_ITEMS; i++)
	{
		delete menu[i];
	}
}

int Menu::getSelectedItemIndex() const
{
	return mSelectedItemIndex;
}

void Menu::setSelectedItemIndex(int const newSelectedItemIndex)
{
	mSelectedItemIndex = newSelectedItemIndex;
}

void Menu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_NUMBER_ITEMS; i++)
	{
		window.draw(*menu[i]);
	}
}

void Menu::moveUp()
{
	if (mSelectedItemIndex - 1 >= 0)
	{
		menu[mSelectedItemIndex]->setFillColor(sf::Color::Red);
		mSelectedItemIndex--;
		menu[mSelectedItemIndex]->setFillColor(sf::Color::Blue);
	}
}

void Menu::moveDown()
{
	if (mSelectedItemIndex + 1 < MAX_NUMBER_ITEMS)
	{
		menu[mSelectedItemIndex]->setFillColor(sf::Color::Blue);
		mSelectedItemIndex++;
		menu[mSelectedItemIndex]->setFillColor(sf::Color::Red);
	}
}
#pragma once


///*
//Button.hpp
//
//Author: Nicholas Horner
//Last Edited: 4/23/2026
//CptS 122 Sec 4
//
//*/
//
///*
//Button is an inerited class based off of sf::shape
//Button needs text, size, color, ability, position to be input
//
//*/

#include <SFML/Graphics.hpp>
#include <string>

using std::string;

// Inherit rectangle shape overall, but also include text as an input private variable
class Button : public sf::RectangleShape
{
private:
	bool _is_triggered;
	sf::Text _button_text;

public:
	// Need input position, size, color, font, and text (since text cannot be instantiated without font, need font input for _button_text)
	Button(const sf::Vector2f& input_pos, const sf::Vector2f& input_size, const sf::Color& input_color, sf::Font& input_font, string button_text, const sf::Color& border_color, const bool& set_outline);

	// Getters
	bool is_triggered() const;
	sf::Text get_text() const;

	// Setters
	void update_trigger(const bool& trigger_state);

	// Check if mouse is hovering over button if triggered (DOES NOT check for mouse click)
	bool check_mouse_overlap(sf::RenderWindow& input_window);
	void set_text(const string& input_text);
};


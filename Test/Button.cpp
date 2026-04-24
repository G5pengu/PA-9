#include "Button.hpp"



Button::Button(const sf::Vector2f& input_pos, const sf::Vector2f& input_size, const sf::Color& input_color, sf::Font& input_font, string button_text)
	: _button_text(input_font, button_text, (unsigned int)input_size.y * 0.2f)
{
	this->setSize(input_size);
	this->setPosition(input_pos);
	this->setFillColor(input_color);

	_button_text.setFillColor(sf::Color::White);
	_button_text.setPosition({input_pos.x, this->getGlobalBounds().getCenter().y});
	_is_triggered = false;
}

bool Button::is_triggered() const
{
	return _is_triggered;
}

void Button::update_trigger(const bool& trigger_state)
{
	_is_triggered = trigger_state;
}

bool Button::check_mouse_overlap(sf::RenderWindow& input_window)
{
	// Check the bounds of this rectangle and see if it contains the mouse's position when called
	return this->getGlobalBounds().contains({ (float)sf::Mouse::getPosition(input_window).x, (float)sf::Mouse::getPosition(input_window).y});
}

sf::Text Button::get_text() const
{
	return _button_text;
}



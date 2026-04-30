#include "../Header/Button.hpp"



Button::Button(const sf::Vector2f& input_pos, const sf::Vector2f& input_size, const sf::Color& input_color, sf::Font& input_font, string button_text, const sf::Color& border_color, const bool& set_outline)
	: _button_text(input_font, button_text, (unsigned int)input_size.y * 0.15f)
{
	this->setSize(input_size);
	this->setPosition(input_pos);
	this->setFillColor(input_color);


	if (set_outline)
	{
		this->setOutlineColor(border_color);
		this->setOutlineThickness(input_size.x * .1f);
	}


	_button_text.setFillColor(sf::Color::Black);
	_is_triggered = false;
	_button_text.setStyle(sf::Text::Style::Bold);
	_button_text.setStyle(sf::Text::Style::Italic);

	// Find the center of the text to align
	sf::FloatRect text_boundry = _button_text.getLocalBounds();
	_button_text.setOrigin(text_boundry.getCenter());
	_button_text.setPosition(this->getGlobalBounds().getCenter());

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
	return this->getGlobalBounds().contains({ (float)sf::Mouse::getPosition(input_window).x, (float)sf::Mouse::getPosition(input_window).y });
}

void Button::set_text(const string& input_text)
{
	_button_text.setString(input_text);
}

sf::Text Button::get_text() const
{
	return _button_text;
}


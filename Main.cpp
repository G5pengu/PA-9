#include <iostream>
#include <SFML/Graphics.hpp>

#include "Menu.hpp"

using namespace sf;

int main() 
{

	RenderWindow window(sf::VideoMode({ 1920,1080 }), "SFML TEST");

	//Menu stuff - zac
	Menu menu(1920, 1080);

	//originally I had a switch statement but then it didnt work and turns out in the 
	//newer version of SFML switch statements were removed so I asked claude to make this while loop in propper
	//3.0.2 version syntax (the change was to make button presses safer)
    while (window.isOpen())
    {
        while (const std::optional<sf::Event> event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }

            if (const auto* keyEvent = event->getIf<sf::Event::KeyReleased>())
            {
                if (keyEvent->code == sf::Keyboard::Key::Up)
                {
                    menu.moveUp();
                }
                if (keyEvent->code == sf::Keyboard::Key::Down)
                {
                    menu.moveDown();
                }
                if (keyEvent->code == sf::Keyboard::Key::Enter)
                {
                    if (menu.getSelectedItemIndex() == 0)
                    {
                        printf("Play button has been pressed");
                    }
                    if (menu.getSelectedItemIndex() == 1)
                    {
                        printf("Exit button has been pressed");
                        window.close();
                    }
                }
            }
        }

        window.clear(sf::Color::Black);
        menu.draw(window);
        window.display();
    }
}
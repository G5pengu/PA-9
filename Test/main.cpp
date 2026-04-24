#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>

#include "Button.hpp"

using std::cout;
using std::endl;

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 1600, 1000 }), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setPosition(sf::Vector2f(1200,800));
    shape.setFillColor(sf::Color::Blue);
    sf::RectangleShape shape2({ 50,20 });
    shape2.setPosition(sf::Vector2f(50, 50));
    shape2.setFillColor(sf::Color::Magenta);
    window.setFramerateLimit(60);
    sf::Font font;

    if (!font.openFromFile("C:/Windows/Fonts/arial.ttf"))
    {
        cout << "ERROR FILE PATH" << endl;
    }

    Button test_button({ 300.f, 300.f }, { 100.f,100.f }, sf::Color::Red, font, "test_button");

    shape.setOrigin({ 100.f, 100.f });
    shape2.setOrigin({ 25.f, 10.f });

    sf::Vector2f direction;
    sf::Vector2f normalized_direction;

    float rotate_angle = 0;

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();

            if (event->is<sf::Event::MouseMoved>())
            {
                shape.move(sf::Vector2f(.3f, .3f));
            }

            if (event->is<sf::Event::MouseButtonPressed>())
            {
                shape.setPosition(sf::Vector2f(200, 200));
            }

            if (event->is<sf::Event::MouseButtonPressed>() && test_button.check_mouse_overlap(window))
            {
                test_button.update_trigger(!test_button.is_triggered());

                if (test_button.is_triggered())
                {
                    test_button.setFillColor(sf::Color::Green);
                }
                else
                {
                    test_button.setFillColor(sf::Color::Red);
                }
            }

            if (event->is<sf::Event::MouseEntered>())
            {
                shape.setFillColor(sf::Color::Green);
            }
            else 
            {
                shape.setFillColor(sf::Color::Yellow);
            }



            if (event->is<sf::Event::KeyPressed>())
            {
                shape.setPosition(sf::Vector2f(1400, 800));
            }
            
        }

        direction = shape.getPosition() - shape2.getPosition();
        normalized_direction = direction.normalized();


        window.clear();
        window.draw(test_button);
        window.draw(test_button.get_text());
        window.draw(shape);
        window.draw(shape2);
        window.display();
        shape.move(sf::Vector2f((float).02, (float)0));
        shape2.move(normalized_direction * 5.f);
        shape2.setRotation(sf::degrees(rotate_angle));

        ++rotate_angle;
        if (rotate_angle > 359)
        {
            rotate_angle = 0;
        }
        
    }
}
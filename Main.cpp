#include <iostream>
#include <SFML/Graphics.hpp>
#include "net.hpp"
using namespace sf;

int main() {
	Network n;
	n.cat();
	
	

	//RenderWindow window(sf::VideoMode({ 1920,1080 }), "SFML TEST");

	////create texture / object
	//Texture dante;
	////make sure it isnt fucking stupid
	//if (!dante.loadFromFile("assets/dante.png"))
	//	std::cout << "Failed to load test image!\n";

	////create object to render it
	//Sprite spriteTest(dante);

	////scale said object so we have laws
	//auto size = dante.getSize();
	//spriteTest.setScale({
	//	1920.f / size.x, //sfml doesnt accept direct scaling like JFrame does, this is how
	//	400.f / size.y //size you want, divided by its original size !!x and y are flipped, x is virtical!!
	//	});
	////set location of objcet
	//spriteTest.setPosition({ 0,0 });

	////main window loop / frame clock
	//while (window.isOpen()) {
	//	while (const std::optional event = window.pollEvent()) {
	//		if (event->is<Event::Closed>())
	//			window.close();
	//	}

	//	window.clear();
	//	window.draw(spriteTest);
	//	window.display();
	//}

	//todo: inputs
}
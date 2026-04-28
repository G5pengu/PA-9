#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace sf;

int main() {
	RenderWindow window(sf::VideoMode({ 1920,1080 }), "SFML TEST");

	sf::CircleShape NewCircle(100.f, 20U);
	NewCircle.setFillColor(sf::Color::Magenta);
	NewCircle.setPosition({ 250, -200 });

	float y_target = 800;

	/*
		float velocity = (total Y Distance) / Beats * (60 / BPM) == pixels / seconds

		Beats = Beats in the song (quarter note is 1 beat)
		BPM = Beats per minute (fight song is 170)

		Need to convert BPM to beats per second, so BPS = 170 / 1 min * 1 min / 60 = 170 / 60

		Inverting gives 60 / 170 == seconds per beat
		
		Beats * Seconds per beat = seconds (yay)

		To simplify, can just write (beats * 60 / BPM)

		Y - Distance = Target - Start (Start will usually be a negative (like 200)

		THEN convert velocity (pixels/second) to pixels/frame

		so velocity * seconds/frame = velocity / FPS = pixels / frame

		(Divide by FPS since / FPS == * SPF

	
		///////////////////////////////////////

	
		To spawn a new song, need to calculate the time between beats

		170 BPM * 1 M/ 60s = 170 / 60 = 2.8333 B/s

		Inverse: The whole process is 60 / 170 (60 / BPM)

		Then multiply by # of beats

		So Time = (60 / 170) * Beats OR  (60 / BPM) * Beats


		** Likely will need a switch? to get the note pattern
		*** Each spawned note pushes the timer to the next note

	*/

	float BPM = 170.0;

	float velocity = (y_target - NewCircle.getPosition().y) / (1 * 60 / BPM); // 1 Beat

	velocity = velocity / (60);



	window.setFramerateLimit(60);

	//main window loop / frame clock
	while (window.isOpen()) {
		while (const std::optional event = window.pollEvent()) {
			if (event->is<Event::Closed>())
				window.close();
		}

		window.clear();
		window.draw(NewCircle);

		if (NewCircle.getPosition().y < 800)
		{
			NewCircle.move({ 0, velocity });
		}

		window.display();
	}

	//todo: inputs
}
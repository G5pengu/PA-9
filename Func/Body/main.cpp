#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Header/SoundManager.hpp"
#include "../Header/NoteTimeCalc.hpp"



int main() {
    sf::RenderWindow window(sf::VideoMode({ 1920,1080 }), "SFML TEST");

    sf::CircleShape circle1(100.f, 20U);
    sf::RectangleShape line({ 1000, 2 });

    NoteTimeCalc note_time(160.f, 1.5);

    // Setup
    circle1.setFillColor(sf::Color::Magenta);
    circle1.setOrigin({ 100.f, 100.f });
    circle1.setPosition({ 250, -200 });

    line.setFillColor(sf::Color::White);
    line.setPosition({ 250, 800 });

    float startY = -200.f;
    float targetY = 800.f;

    // All notes travel for the same time, so set travelTime
    float travelTime = 1.5f;

    // Compute velocity (constant ideally for all notes, difficulty setting)
    float velocity = (targetY - startY) / travelTime;

    float beat = 0.f; // Beat is per note (see class)
    float spawnTime = note_time.beatToTime(beat) - travelTime;
   
    sf::Clock songClock;
    sf::Clock frameClock;

    /*
        When using an actual song, use music.play() to make sure the song is aligned
        music.play();
        songClock.restart();
        float offset = 0.0f;
    
    */

    SoundManager test;
    // test.get_music_stream().getPlayingOffset().asSeconds() Example of Sound Manager implementation
    int x = 4;
    switch (x)
    {
        case 4: cout << "Test" << endl;
    } 

    window.setFramerateLimit(60);

    while (window.isOpen()) {

        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        float songTime = songClock.getElapsedTime().asSeconds() - note_time.get_offset_time();
        //float songTime = music.getPlayingOffset().asSeconds() - note_time.get_offset_time(); In audio manager, instead of using a clock use the music stream itself

        float elapsed = songTime - spawnTime;

        if (elapsed < 0.f)
        {
            // do nothing at all (note is not active)
        }
        else
        {
            // Basically calculate the next time position of the note, t is a normalized (0 - 1) multiplication value
            float t = elapsed / travelTime;

            if (t > 1.f)
                t = 1.f;
            
            // Then update position based off of normal t * offset
            float y = startY + (targetY - startY) * t;

            // Update position directly, do not use move
            circle1.setPosition({ 250.f, y });
        }

        window.clear();
        window.draw(circle1);
        window.draw(line);
        window.display();
    }
}
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>

#include "SoundManager.hpp"

using std::cout;
using std::endl;

// Note: Music files are installed in Project Folder Name/Solution Name/
// ^ With the hpp and cpp files in file explorer, need to also add extensions correctly when calling (.wav, .mp3, etc.)

int main()
{

    // In final program, need to take note of which index contains which sound (they are inserted in order)
    // IE: Here sound_test is index 0, sound_test2 is index 1
    // Music string filepaths and soundbuffers have their own lists/vectors and thus their own indexes
    
    // Create the two sound buffer inputs (these should throw errors if they fail)
    sf::SoundBuffer sound_test("file_example_WAV_1MG.wav");
    sf::SoundBuffer sound_test2("sample-3s.wav");
    
    // Manager object
    SoundManager sound_manager_test;

    // Input the buffers directly, and input the music by path
    sound_manager_test.input_sound(sound_test);
    sound_manager_test.input_sound(sound_test2);
    sound_manager_test.input_music("sample-speech-1m.wav");

    // Index, volume (0-100 float), is_looped true/false :: NOTE: music will through error if play_music tries to play an invalid path
    sound_manager_test.play_music(0, 20.f, true);

    sf::RenderWindow window(sf::VideoMode({ 1600, 1000 }), "SFML works!");

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();


            if (event->is<sf::Event::MouseButtonPressed>())
            {
                // Sound has index and audio (0 - 100 float)
                sound_manager_test.play_sound(0, 80.f);
            }

            if (event->is<sf::Event::KeyPressed>())
            {
                sound_manager_test.play_sound(1, 40.f);
            }
            
        }


        window.clear();
        window.display();
        
    }
}
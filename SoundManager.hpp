#ifndef SOUNDMANAGER_hpp
#define SOUNDMANAGER_hpp

/*

SoundManager.hpp

Author: Nicholas Horner
Last Edited: 4/28/2026
CptS 122 Sec 4

Sound Manager is essentially a dynamic vector array of soundbuffer and music classes
^ User can load songs into the vector, and just use index instead of calling each individual song
^^ Sounds and music

** Note: Since Music is a stream, need to store the filepath/name rather than the stream itself (storing the stream would be bad), soundbuffer is fine since external sound is needed
*		 Use std::list to not have to remake a linked list

*/

#include <SFML/Audio.hpp>
#include <vector>
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class SoundManager
{
	private:

		std::list<sf::SoundBuffer> _SoundBufferList; // Vector to store the buffers for the sounds, in a list for memory movement issues
		std::list<sf::Sound> _SoundList; // NOTE: list does not move around in memory vs vectors (since vectors are simultaneous, it moves everything and Sound streams get pissed off if they move while a sound is running)
		std::vector<string> _MusicPathVector; // Vector to store the strings of music file paths
		sf::Music _musicStream; // Music stream to play a song (only 1 song can play at a time)

	public:

		SoundManager(); // Sets sounds and music to 0

		void input_sound(const sf::SoundBuffer& soundBufferInput); // Input a sound buffer, and it gets pushed into soundvector, make sure sound buffer loads

		void input_music(const string& MusicPathInput); // Input a music stream file path, so that a music stream can pull from it

		void remove_sound(const int& index); // Removes a sound from vector if index is valid

		void remove_music(const int& index); // Removes a sound from vector if index is valid

		int get_sound_num() const; // Return the number of sounds stored

		int get_music_num() const; // Return number of music stored

		sf::Music& get_music_stream(); // Return the music stream (for timing with the song loop)

		void play_sound(const int& sound_index, const float& volume);
		
		void play_music(const int& music_index, const float& volume, const bool& is_looped);


};


#endif
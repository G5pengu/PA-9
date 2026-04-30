#include "../Header/SoundManager.hpp"


SoundManager::SoundManager()
{
	// Don't need to do anything
}

void SoundManager::input_sound(const sf::SoundBuffer& soundBufferInput)
{
	_SoundBufferList.push_back(soundBufferInput); // soundBufferInput should be confirmed

	sf::Sound temp(_SoundBufferList.back());

	_SoundList.push_back(temp);
}

// Input a music STRING filepath into vector (note: that filepath call may fail after input)
void SoundManager::input_music(const string& MusicPathInput)
{
	_MusicPathVector.push_back(MusicPathInput); // MusicPathInput only cares about string input
}

// Remove a sound from both lists by index
void SoundManager::remove_sound(const int& index)
{

	std::list<sf::Sound>::iterator list_ptr_sound = _SoundList.begin(); // New thing, an iterator is essentially like a universal head pointer, it's needed to traverse the std::list
	std::list<sf::SoundBuffer>::iterator list_ptr_buffer = _SoundBufferList.begin();

	if (index >= 0 && _SoundList.size())
	{

		// Run a for loop to find the correct spot in the list
		for (int node = 0; node < index; ++node)
		{
			list_ptr_sound++; // Increment the iterator to point to the next node
			list_ptr_buffer++;
		}

		list_ptr_sound->stop(); // Need to stop just in case sound is playing

		_SoundList.erase(list_ptr_sound); // Erase at the location of list_ptr
		_SoundBufferList.erase(list_ptr_buffer);

	}
	else
	{
		cout << "Out of range index input for remove sound!" << endl;
	}
}


void SoundManager::remove_music(const int& index)
{
	std::vector<string>::iterator vector_ptr = _MusicPathVector.begin(); // Vectors also need iterators unlike strings

	if (index >= 0 && _MusicPathVector.size())
	{

		_musicStream.stop(); // Stop playing to be safe, mainly if the stream is playing the current index to be removed

		// Run a for loop to find correct spot
		for (int node = 0; node < index; ++node)
		{
			vector_ptr++;
		}

		_MusicPathVector.erase(vector_ptr);
	}
	else
	{
		cout << "Out of range index input for remove music!" << endl;
	}
}


int SoundManager::get_sound_num() const
{
	return _SoundBufferList.size(); // SoundBufferVector and SoundList should be the same size
}

int SoundManager::get_music_num() const
{
	return _MusicPathVector.size();
}

sf::Music& SoundManager::get_music_stream()
{
	return _musicStream;
}


// Volume is a range from 0 to 100, default is 50
void SoundManager::play_sound(const int& sound_index, const float& volume)
{
	std::list<sf::Sound>::iterator list_ptr = _SoundList.begin(); // Need the iterator to cycle through list_ptr

	if (sound_index >= 0 && sound_index < _SoundList.size())
	{
		for (int node = 0; node < sound_index; ++node)
		{
			list_ptr++; // Again, use iterator to find the target point in the list
		}

		if (volume >= 0 && volume <= 100)
		{
			list_ptr->setVolume(volume);
		}
		else
		{
			list_ptr->setVolume(50.f);
		}

		list_ptr->play();
	}
	else
	{
		cout << "Out of range index input for play sound!" << endl;
	}

}


void SoundManager::play_music(const int& music_index, const float& volume, const bool& is_looped)
{
	_musicStream.stop();

	if (music_index >= 0 && music_index < _MusicPathVector.size())
	{
		// Since it's just a vector of strings, can go immediately to needed file path

		if (volume >= 0 && volume <= 100)
		{
			_musicStream.setVolume(volume);
		}
		else
		{
			_musicStream.setVolume(50.f);
		}

		if (is_looped)
		{
			_musicStream.setLooping(true);
		}
		else
		{
			_musicStream.setLooping(false);
		}

		if (_musicStream.openFromFile(_MusicPathVector[music_index])) // Returns a bool
		{
			_musicStream.play();
		}
		else
		{
			cout << "Music player failed to load from provided stream at index " << music_index << "!" << endl;
		}
	}
	else
	{
		cout << "Out of range index input for play music!" << endl;
	}
}





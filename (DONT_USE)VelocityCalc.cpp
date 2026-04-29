#include "VelocityCalc.hpp"

// Construct velocity with object start and target, BPM, FPS, # song beats, and whether object is moving towards (0,0) or away (single direction)
// Note: This will calculate the object velocity for the object to traverse distance in a # beats input
// PRECONDITION: beat_num and BPM cannot be 0
VelocityManager::VelocityManager(float target_distance, float start_distance, float BPM, float FPS, float beat_num, bool towards_origin)
{
	/*
		
		Velocity is pixels / frame <--- pixels / second 

		Numerator is pixels, denominator is calculated seconds converted to frames

		Beats = Beats in the song (quarter note is 1 beat)
		BPM = Beats per minute (fight song is 170)

		Need to convert BPM to beats per second (to be usable), so BPS = 170 / 1 min * 1 min / 60 = 170 / 60

		Inverting gives 60 / 170 == seconds per beat

		Beats * Seconds per beat = seconds (yay)

		To simplify, can just write (beats * 60 / BPM)

		Y - Distance = Target - Start (Start will usually be a negative (like 200)

		THEN convert velocity (pixels/second) to pixels/frame

		so velocity * seconds/frame = velocity / FPS = pixels / frame

		(Divide by FPS since / FPS == * SPF)

		float velocity = (total Y Distance) / Beats * (60 / BPM) == pixels / seconds

	*/

	if (BPM == 0 || beat_num == 0)
	{
		_velocity = 0;
	}
	else if (towards_origin) // Inverse velocity, since it needs to be negative
	{
		_velocity = -((target_distance - start_distance) / (beat_num * (60 / BPM)));
	}
	else // Non-inverse
	{
		_velocity = ((target_distance - start_distance) / (beat_num * (60 / BPM)));
	}
}

// Just copy the velocity lmao
VelocityManager::VelocityManager(const VelocityManager& input_manager)
{
	_velocity = input_manager._velocity;
}

// Same as copy constructor, and return *this
VelocityManager& VelocityManager::operator=(const VelocityManager& rhs)
{
	_velocity = rhs._velocity;

	return *this;
}

// Do nothing
VelocityManager::~VelocityManager()
{}


float VelocityManager::getVelocity() const
{
	return _velocity;
}

void VelocityManager::updateVelocity(float target_distance, float start_distance, float BPM, float FPS, float beat_num, bool towards_origin)
{
	// See constructor for math methods

	if (towards_origin) // Inverse velocity, since it needs to be negative
	{
		_velocity = -((target_distance - start_distance) / (beat_num * (60 / BPM)));
	}
	else // Non-inverse
	{
		_velocity = ((target_distance - start_distance) / (beat_num * (60 / BPM)));
	}
}


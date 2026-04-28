#include "TimeCalc.hpp"

// Use song beats per minute and num_beats to calculate when to spawn the next object
// PRECONDITION: BPM cannot be 0
TimeCalc::TimeCalc(float BPM, float num_beats)
{
	/*
		To spawn a new song, need to calculate the time between beats

		Convert BPM to seconds: Get BPS, inverse, multiply by beats

		BPM --> BPS = BPM * 1/60
		
		Then inverse, 1/BPS = SPB

		Then multiply by beats (SPB * beats) = seconds

		To simplify (1/(BPS)) = 1/(BPM * 1/60) == 60 / BPM

		Which simplifies to (60 / BPM) * beats == seconds

	*/

	if (BPM != 0)
	{
		_time = (60 / BPM) * num_beats;
	}
	else
	{
		_time = 0;
	}
}

// Copy time
TimeCalc::TimeCalc(const TimeCalc& input_time)
{
	_time = input_time._time;
}

// Copy assignment (still copy time)
TimeCalc& TimeCalc::operator=(const TimeCalc& rhs)
{
	_time = rhs._time;

	return *this;
}

// Repeat what is used in constructor
// PRECONDITION: BPM cannot be 0
void TimeCalc::calc_new_time(float BPM, float num_beats)
{
	if (BPM != 0)
	{
		_time = (60 / BPM) * num_beats;
	}
	else
	{
		_time = 0;
	}
}

// Return time
float TimeCalc::get_time() const
{
	return _time;
}


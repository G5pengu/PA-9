#ifndef TIMECALC_HPP
#define TIMECALC_HPP

/*

Author: Nicholas Horner
Last Edited: 4/27/2026
CptS 122 Sec 4

Time calculation to calculate the time to the next note

*/

class TimeCalc
{
	private:

		float _time;

	public:

		// Need the Beats per minute and the num of beats to calculate when to spawn the next object
		TimeCalc(float BPM, float num_beats);

		// Copy time constructor
		TimeCalc(const TimeCalc& input_time);

		// Copy ssignment operator
		TimeCalc& operator=(const TimeCalc& rhs);

		// Calculate new time
		void calc_new_time(float BPM, float num_beats);

		// Return time
		float get_time() const;

};

#endif

#ifndef VELOCITYCALC_HPP
#define VELOCITYCALC_HPP

/*

Author: Nicholas Horner
Last Edited: 4/27/2026
CptS 122 Sec 4

Velocity manager for managing object spawning velocity
NOTE: Time is managed already by either clock or another function

*/

class VelocityManager // Not an inheritance
{
	private:
		float _velocity; // Single direction velocity

	public:
		// Construct velocity with object start and target, BPM, FPS, # song beats, and whether object is moving towards (0,0) or away (single direction)
	// Note: This will calculate the object velocity for the object to traverse distance in a # beats input
		VelocityManager(float target_distance, float start_distance, float BPM, float FPS, float beat_num, bool towards_origin);

		VelocityManager(const VelocityManager& input_manager); // Copy constructor
		VelocityManager& operator=(const VelocityManager& rhs); // Copy assignment constructor

		~VelocityManager();

		// Get the velocity
		float getVelocity() const;

		// Same thing as constructor, but update the velocity
		void updateVelocity(float target_distance, float start_distance, float BPM, float FPS, float beat_num, bool towards_origin);

};





#endif 

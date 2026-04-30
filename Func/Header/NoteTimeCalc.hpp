#ifndef NOTETIMECALC_HPP
#define NOTETIMECALC_HPP

#include <SFML/System.hpp>

/*

Author: Nicholas Horner
Last Edited: 4/27/2026
CptS 122 Sec 4

Time calculation to calculate the time of when to play/spawn a note, and the offset (to make sure that a note doesn't spawn too late)
^ Notes need time to move, that's why offset is needed

*/

class NoteTimeCalc
{
    private:

        float _BPM;
        float _song_offset_time;

        // Seconds per beat from BPM (mainly a helper)
        float secondsPerBeat();

    public:

        NoteTimeCalc(float BPM=0.0, float song_offset=0.0);

        float get_BPM() const;
        float get_offset_time() const;

        void set_BPM(const float& BPM);
        void set_offset_time(const float& song_offset);

        // Calculate the absolute time (note scoresheet position in seconds)
        // Ie 8th beat in a song is songBeatIndex 8
        float beatToTime(float songBeatIndex);
};

#endif
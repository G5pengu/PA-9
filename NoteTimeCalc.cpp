#include "NoteTimeCalc.hpp"


float NoteTimeCalc::secondsPerBeat()
{
    // BPM = Beats/Minute * 1/60 = BPM/60, so SPB = 60/BPM
    return (60 / _BPM);
}

// Input the song's BPM and when to go back in time (the offset)
// ^ offset is so notes can appear offscreen instead of being forced to cut their duration time
NoteTimeCalc::NoteTimeCalc(float BPM, float song_offset)
{
    _BPM = BPM;
    _song_offset_time = song_offset;
}

float NoteTimeCalc::get_BPM() const
{
    return _BPM;
}

float NoteTimeCalc::get_offset_time() const
{
    return _song_offset_time;
}

void NoteTimeCalc::set_BPM(const float& BPM)
{
    _BPM = BPM;
}

void NoteTimeCalc::set_offset_time(const float& song_offset)
{
    _song_offset_time = song_offset;
}

// Calculate the time in which the beat of the song is
// IE a half note that is the 5th beat in a song has a songBeatIndex of 5
// ^ This would be used to find the absolute time
float NoteTimeCalc::beatToTime(float songBeatIndex)
{
    return songBeatIndex * secondsPerBeat();
}

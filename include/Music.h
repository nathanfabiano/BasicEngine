#ifndef MUSIC_H
#define MUSIC_H

#define INCLUDE_SDL_MIXER
#include "SDL_include.h"
#include <iostream>

class Music
{
private:
	Mix_Music* m_music;
public:
	Music();
	Music(std::string file);
	~Music();
	void Play(int times);
	void Stop(int msToStop);
	void Open(std::string file);
	bool IsOpen();
};

#endif
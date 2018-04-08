 
#include "Music.h"
 #define INCLUDE_SDL
 #define INCLUDE_SDL_MIXER
 #include "SDL_include.h"
 #include <iostream>

Music::Music() : m_music(nullptr)
{

}

Music::Music(std::string file)
{
	Music();
	Open(file);
}

void Music::Open(std::string file)
{
	if (IsOpen())
	{
		//delete m_music;
		Mix_FreeMusic(m_music);
	}
	
	m_music = Mix_LoadMUS(file.c_str());
	if (!IsOpen())
	{
		std::cout << "Unable to load music: " << SDL_GetError();
        SDL_Log("Unable to load music: %s", SDL_GetError());
        //return 1;
	}
}

void Music::Play(int times=-1)
{
	if (IsOpen())
	{
		Mix_PlayMusic(m_music, times); //times: -1 = loop infinito, 0 = nao toca
	}
}

void Music::Stop(int msToStop=1500)
{
	Mix_FadeOutMusic(msToStop);
}

bool Music::IsOpen()
{
	if (m_music == nullptr)
	{
		return false;
	}
	else
	{
		return true;
	}
}

Music::~Music()
{
	Stop(0);
	Mix_FreeMusic(m_music);
}
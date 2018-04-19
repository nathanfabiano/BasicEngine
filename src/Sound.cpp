#include "Sound.h"
#include "GameObject.h"
#include "Component.h"
#include "Game.h"
#include <iostream>
 #define INCLUDE_SDL
 #define INCLUDE_SDL_MIXER
 #include "SDL_include.h"

Sound::Sound(GameObject& associated) : Component(associated), m_chunk(nullptr)
{

}

Sound::Sound(GameObject& associated, std::string file) : Component(associated), m_chunk(nullptr)
{
	Open(file);
}

Sound::~Sound()
{
	/*if (IsOpen())
	{
		Stop();
		Mix_FreeChunk(m_chunk);
	}*/
}

void Sound::Open(std::string file)
{
	Game* game = Game::GetInstance();
	m_chunk = game->resources.GetSound(file);
	//m_chunk = Mix_LoadWAV(file.c_str());
	if (!IsOpen())
	{
		std::cout << "Unable to load sound: " << SDL_GetError();
        SDL_Log("Unable to load sound: %s", SDL_GetError());
	}
}

void Sound::Play(int times)
{
	if (IsOpen())
	{
		std::cout << "Play Boom!" << std::endl;
		m_channel = Mix_PlayChannel(-1, m_chunk, times-1);
		printf("%d %s\n", m_channel, SDL_GetError());
	}
}

void Sound::Stop()
{
	if (IsOpen())
	{
		Mix_HaltChannel(10);
	}
}

bool Sound::IsOpen()
{
	if (m_chunk == nullptr)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Sound::Update(float dt)
{
	//???
}

void Sound::Render()
{
	//???
}

bool Sound::Is(std::string type)
{
	if ((type == "sound")||(type == "Sound")||(type == "SOUND"))
	{
		return true;
	}
	else
	{
		return false;
	}
}

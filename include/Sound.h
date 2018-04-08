#ifndef SOUND_H
#define SOUND_H

#include <iostream>
#include "GameObject.h"
#include "Component.h"

#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL
#include "SDL_include.h"

class Sound : public Component
{
private:
	Mix_Chunk* m_chunk;
	int m_channel;
public:
	Sound(GameObject& associated);
	Sound(GameObject& associated, std::string file);
	~Sound();

	void Play(int times=1);
	void Stop();
	void Open(std::string file);
	bool IsOpen();

	void Update(float dt);
	void Render();
	bool Is(std::string type);
};

#endif
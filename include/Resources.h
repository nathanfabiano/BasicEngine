#ifndef RESOURCES_H
#define RESOURCES_H

#define INCLUDE_SDL
#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL_IMAGE
#include "SDL_include.h"
#include <iostream>
#include <unordered_map>

class Resources
{
private:
	std::unordered_map<std::string, SDL_Texture*> m_imageTable;
	std::unordered_map<std::string, Mix_Music*> m_musicTable;
	std::unordered_map<std::string, Mix_Chunk*> m_soundTable;

public:
	SDL_Texture* GetImage(std::string file);
	void ClearImages();

	Mix_Music* GetMusic(std::string file);
	void ClearMusics();

	Mix_Chunk* GetSound(std::string file);
	void ClearSounds();
};

#endif
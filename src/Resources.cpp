#include "Resources.h"
#include "Game.h"
#define INCLUDE_SDL
#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL_IMAGE
#include "SDL_include.h"
#include <iostream>
#include <unordered_map>

Resources::Resources()
{
	m_imageTable.emplace("zero", nullptr);
	m_imageTable.emplace("one", nullptr);
}

SDL_Texture* Resources::GetImage(std::string file)
{
	std::unordered_map<std::string, SDL_Texture*>::iterator img_ptr = m_imageTable.find(file);
	//auto img_ptr = m_imageTable.find(file);

	if (img_ptr == m_imageTable.end())
	{
		Game* game = Game::GetInstance();
		std::pair<std::string, SDL_Texture*> newImage(file, IMG_LoadTexture(game->GetRenderer(), file.c_str()));
		//std::pair<std::string, SDL_Texture*> imgPair("assets/img/penguinface.png", img_ptr->second);
		m_imageTable.insert(newImage);
		return m_imageTable.find(file)->second;
	}
	else
	{
		//Achou
		return img_ptr->second;
	}
}

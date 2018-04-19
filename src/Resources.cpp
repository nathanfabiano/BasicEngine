#include "Resources.h"
#include "Game.h"
#define INCLUDE_SDL
#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL_IMAGE
#include "SDL_include.h"
#include <iostream>
#include <unordered_map>

SDL_Texture* Resources::GetImage(std::string file)
{
	std::unordered_map<std::string, SDL_Texture*>::iterator img_ptr = m_imageTable.find(file);
	//auto img_ptr = m_imageTable.find(file);

	if (img_ptr == m_imageTable.end())
	{
		std::cout << "Criou " << file << std::endl;
		Game* game = Game::GetInstance();
		std::pair<std::string, SDL_Texture*> newImage(file, IMG_LoadTexture(game->GetRenderer(), file.c_str()));
		//std::pair<std::string, SDL_Texture*> imgPair("assets/img/penguinface.png", img_ptr->second);
		m_imageTable.insert(newImage);
		return m_imageTable.find(file)->second;
	}
	else
	{
		//Achou
		std::cout << "Achou " << file << std::endl;
		return img_ptr->second;
	}
}

void Resources::ClearImages()
{
	for (auto it = m_imageTable.begin(); it != m_imageTable.end(); ++it)
	{
		SDL_DestroyTexture(it->second);
	}
	m_imageTable.erase( m_imageTable.begin(), m_imageTable.end());
}
//----------------------------------------------------------------------------------------------------------------

Mix_Music* Resources::GetMusic(std::string file)
{
	std::unordered_map<std::string, Mix_Music*>::iterator music_ptr = m_musicTable.find(file);

	if (music_ptr == m_musicTable.end()) //não achou, então cria uma nova music
	{
		std::pair<std::string, Mix_Music*> newMusic(file, Mix_LoadMUS(file.c_str())); //cria a variavel newMusic com key 'file' e value apontado para a musica (load)
		m_musicTable.insert(newMusic);
		return m_musicTable.find(file)->second;
	}
	else
	{
		//Achou
		return music_ptr->second;
	}
}

void Resources::ClearMusics()
{
	for (auto it = m_musicTable.begin(); it != m_musicTable.end(); ++it)
	{
		Mix_FreeMusic(it->second);
	}
	m_musicTable.erase( m_musicTable.begin(), m_musicTable.end());
}
//----------------------------------------------------------------------------------------------------------------

Mix_Chunk* Resources::GetSound(std::string file)
{
	std::unordered_map<std::string, Mix_Chunk*>::iterator sound_ptr = m_soundTable.find(file);

	if (sound_ptr == m_soundTable.end()) //não achou, então cria uma nova music
	{
		std::pair<std::string, Mix_Chunk*> newSound(file, Mix_LoadWAV(file.c_str())); //cria a variavel newSound com key 'file' e value apontado para o som (load)
		m_soundTable.insert(newSound);
		return m_soundTable.find(file)->second;
	}
	else
	{
		//Achou
		return sound_ptr->second;
	}
}

void Resources::ClearSounds()
{
	for (auto it = m_soundTable.begin(); it != m_soundTable.end(); ++it)
	{
		Mix_FreeChunk(it->second);
	}
	m_soundTable.erase( m_soundTable.begin(), m_soundTable.end());
}
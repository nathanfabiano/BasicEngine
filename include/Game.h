#ifndef GAME_H
#define GAME_H

#include "State.h"
#include "Resources.h"
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL
#include "SDL_include.h"
#include <iostream> 

class Game
{
 private:

 	std::string m_title;
 	int m_width;
 	int m_height;
 	SDL_Window* m_window;
 	SDL_Renderer* m_renderer;
 	State* m_state;

	static Game* s_instance;
 	Game(std::string title, int width, int height);

 public:
 	Resources resources;

 	~Game();
 	void Run();
	static Game* GetInstance();
	State* GetState(){ return m_state; };
	SDL_Renderer* GetRenderer(){ return m_renderer; };
};

#endif
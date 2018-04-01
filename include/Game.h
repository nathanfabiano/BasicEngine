#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL
#include "SDL_include.h"
#include <iostream>

#ifndef GAME_H
#define GAME_H 

/*
---------------------------------------------------------
Game: A Estrutura Básica da Engine
Game
 - Game        (title  : string, 
                width  : int, 
                height : int) 
 + ~Game       () 
 + Run         () : void 
 + GetRenderer () : SDL_Renderer* 
 + GetState    () : State&
 + GetInstance () : Game&
 - instance   : Game*
 - window     : SDL_Window* 
 - renderer   : SDL_Renderer* 
 - state      : State* 
---------------------------------------------------------
State
+ State()
+ QuitRequested () : bool
+ LoadAssets() : void
+ Update(dt : float) : void
+ Render() : void

- bg : Sprite
- music : Music
- quitRequested : bool
---------------------------------------------------------
Sprite
+ Sprite()
+ Sprite(file : string)
+ ~Sprite()
+ Open(file : string) : void
+ SetClip(x : int, y : int, w : int, h : int) : void
+ Render(x : int, y : int) : void
+ GetWidth() : int
+ GetHeight() : int
+ IsOpen() : bool

- texture : SDL_Texture*
- width: int
- height: int
- clipRect : SDL_Rect
---------------------------------------------------------
Music
+ Music()
+ Music(file : std::string)
+ Play (times : int = -1) : void
+ Stop (msToStop : int = 1500) : void
+ Open (file : std::string) : void
+ IsOpen () : bool

- music : Mix_Music*
 */

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

class Sprite
{
private:
	SDL_Texture* m_texture;
	int m_width;
	int m_height;
	SDL_Rect m_clipRect;
public:
	Sprite();
	Sprite(std::string file);
	~Sprite();
	void Open(std::string file);
	void SetClip(int x, int y, int w, int h);
	void Render(int x, int y);
	bool IsOpen();

	int GetWidth(){ return m_width; };
	int GetHeight(){ return m_height; };

};

class State
{
private:
	Sprite m_bg;
	Music m_music;
	bool m_quitRequest;

public:
	State();
	void LoadAssets();
	void Update(float dt);
	void Render();

	bool QuitRequest(){ return m_quitRequest; };
	
};


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

 	~Game();
 	void Run();
	static Game* GetInstance();
	State* GetState(){ return m_state; };
	SDL_Renderer* GetRenderer(){ return m_renderer; };
};



#endif
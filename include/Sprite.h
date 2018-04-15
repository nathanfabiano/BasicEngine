#ifndef SPRITE_H
#define SPRITE_H

#define INCLUDE_SDL_IMAGE
#include "SDL_include.h"
#include <iostream>
#include "GameObject.h"
#include "Component.h"

class Sprite : public Component
{
private:
	SDL_Texture* m_texture;
	int m_width;
	int m_height;
	SDL_Rect m_clipRect;
public:
	Sprite(GameObject& associated);
	Sprite(GameObject& associated, std::string file);
	~Sprite();
	void Open(std::string file);
	void SetClip(int x, int y, int w, int h); //Usado fora de GameObjects
	void SetClip(); //Usado em GameObjects
	bool IsOpen();

	void Render();
	void Render(int x, int y, int w, int h);
	void Update(float dt);
	bool Is(std::string type);

	int GetWidth(){ return m_width; };
	int GetHeight(){ return m_height; };
};

#endif
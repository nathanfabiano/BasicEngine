#include "Sprite.h"
#include "Game.h"
#include "GameObject.h"
#include "Resources.h"
 #define INCLUDE_SDL
 #define INCLUDE_SDL_IMAGE
 #include "SDL_include.h"
 #include <iostream>

Sprite::Sprite(GameObject& associated) : Component(associated), m_texture(nullptr)
{

}

Sprite::Sprite(GameObject& associated, std::string file) : Component(associated), m_texture(nullptr)
{
	Open(file);
}

Sprite::~Sprite()
{

}

void Sprite::Open(std::string file)
{
	Game* game = Game::GetInstance();

	//m_texture = IMG_LoadTexture(game->GetRenderer(), file.c_str());
	m_texture = game->resources.GetImage(file);
	if (!IsOpen())
	{
		std::cout << "Unable to load texture: " << SDL_GetError();
        SDL_Log("Unable to load texture: %s", SDL_GetError());
	}
	SDL_QueryTexture(m_texture, nullptr, nullptr, &m_width, &m_height);

	SetClip();
}


void Sprite::SetClip(int x, int y, int w, int h) //Parametros (x,y,w,h) retirados! Usa o associated.box
{
	m_clipRect.x = x;
	m_clipRect.y = y;
	m_clipRect.w = w;
	m_clipRect.h = h;
}

void Sprite::SetClip() //Parametros (x,y,w,h) retirados! Usa o associated.box
{
	m_associated.box.w = (float)m_width;
	m_associated.box.h = (float)m_height;

	m_clipRect.x = 0;
	m_clipRect.y = 0;
	m_clipRect.w = (int)m_associated.box.w;
	m_clipRect.h = (int)m_associated.box.h;

	m_associated.box.x = m_associated.box.x - (m_associated.box.w/2);
	m_associated.box.y = m_associated.box.y - (m_associated.box.h/2);
}

bool Sprite::IsOpen()
{
	if (m_texture == nullptr)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Sprite::Update(float dt)
{
	//???
}

void Sprite::Render()
{
	Game* game = Game::GetInstance();
	if (m_associated.GetComponent("Parallax") == nullptr)
	{
		Render((int)(m_associated.box.x - game->GetState()->camera.pos.x) , (int)(m_associated.box.y - game->GetState()->camera.pos.y), (int)m_associated.box.w, (int)m_associated.box.h);
	}
	else
	{
		Component* parallax = m_associated.GetComponent("Parallax");
		Render((int)(m_associated.box.x - parallax->GetCameraPos().x) , (int)(m_associated.box.y - parallax->GetCameraPos().y), (int)m_associated.box.w, (int)m_associated.box.h);
	}
	
}

void Sprite::Render(int x, int y, int w, int h)
{
	Game* game = Game::GetInstance();
	SDL_Rect clipRectDest;
	clipRectDest.x = x;
	clipRectDest.y = y;
	clipRectDest.w = w;
	clipRectDest.h = h;
	if (IsOpen())
	{
		SDL_RenderCopy(game->GetRenderer(), m_texture, &m_clipRect, &clipRectDest);
	}
}

bool Sprite::Is(std::string type)
{
	if ((type == "sprite")||(type == "Sprite")||(type == "SPRITE"))
	{
		return true;
	}
	else
	{
		return false;
	}
}

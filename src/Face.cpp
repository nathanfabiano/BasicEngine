#include "Face.h"
#include "GameObject.h"
#include "Component.h"
#include "Game.h"
#include "InputManager.h"
#include <iostream>

Face::Face(GameObject& associated) : Component(associated), m_hitpoints(10)
{
	//HP inicializado com 30
}

void Face::Damage(int damage)
{
	m_hitpoints -= damage;
	if (m_hitpoints <= 0)
	{
		m_associated.GetComponent("Sound")->Play(1);
		m_associated.RequestDelete();	
	}
}

void Face::Update(float dt)
{
	//DA DANO NO PENGUIN
	Game* game = Game::GetInstance();
	InputManager& input = InputManager::GetInstance();
	if ((input.MousePress(1))&&(m_associated.box.Contains((float)(input.GetMouseX() + game->GetState()->camera.pos.x), (float)(input.GetMouseY() + game->GetState()->camera.pos.y))))
	{
		this->Damage(std::rand() % 10 + 10);
	}
}

void Face::Render()
{

}

void Face::Open(std::string file)
{
	//
}

bool Face::Is(std::string type)
{
	if ((type == "face")||(type == "Face")||(type == "FACE"))
	{
		return true;
	}
	else
	{
		return false;
	}
}

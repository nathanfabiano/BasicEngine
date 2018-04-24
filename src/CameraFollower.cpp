#include "CameraFollower.h"
#include "Game.h"
#include <iostream>

CameraFollower::CameraFollower(GameObject& associated) : Component(associated)
{

}

void CameraFollower::Update(float dt)
{
	Game* game = Game::GetInstance();
	m_associated.box.x = game->GetState()->camera.pos.x;
	m_associated.box.y = game->GetState()->camera.pos.y;
}

void CameraFollower::Render()
{

}

bool CameraFollower::Is(std::string type)
{
	if ((type == "camerafollower")||(type == "CameraFollower")||(type == "CAMERAFOLLOWER"))
	{
		return true;
	}
	else
	{
		return false;
	}
}

#include "Parallax.h"
#include "GameObject.h"
#include "Game.h"


Parallax::Parallax(GameObject& associated, int depth, bool parallaxX, bool parallaxY) : Component(associated), m_depth(depth), m_parallaxX(parallaxX), m_parallaxY(parallaxY)
{
	// MAX Depth = 100
	// MIN Depth = -100
	CalculateSpeedMulti();
	Game* game = Game::GetInstance();
	m_cameraPos = game->GetState()->camera.pos;
}

void Parallax::CalculateSpeedMulti()
{
	//Clamp -100 ~ 100
	if (m_depth > 100)
	{
		m_depth = 100;
	}
	else
	{
		if (m_depth < -100)
		{
			m_depth = -100;
		}
	}

	int complement = 100 - m_depth;
	if (m_parallaxX)
	{
		m_speedMultiplicator.x = ((float)complement)/100.0f;
	}
	else
	{
		m_speedMultiplicator.x = 0.0f;
	}
	if (m_parallaxY)
	{
		m_speedMultiplicator.y = ((float)complement)/100.0f;
	}
	else
	{
		m_speedMultiplicator.y = 0.0f;
	}
}

void Parallax::Update(float dt)
{
	Game* game = Game::GetInstance();
	m_cameraPos = m_cameraPos + ((game->GetState()->camera.speed * m_speedMultiplicator) * dt);
}

void Parallax::Render()
{

}

bool Parallax::Is(std::string type)
{
	if ((type == "parallax")||(type == "Parallax")||(type == "PARALLAX"))
	{
		return true;
	}
	else
	{
		return false;
	}
}




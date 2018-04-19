#include "Face.h"
#include "GameObject.h"
#include "Component.h"
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
		//m_associated.GetComponent("Sound")->Play(1);
		m_associated.RequestDelete();	
	}
}

void Face::Update(float dt)
{

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

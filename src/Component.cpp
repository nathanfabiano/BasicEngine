#include "Component.h"
#include "GameObject.h"


Component::Component(GameObject &associated) : m_associated(associated)
{

}

Component::~Component()
{
	//
}

void Component::Start()
{
	std::cout << "Component Started" << std::endl;
}

void Component::Open(std::string file)
{
	// Usado para o sprite background
}

void Component::Play(int times)
{
	// Usado para o Sound
}

void Component::OpenTileImg(std::string file)
{
	
}

Vec2 Component::GetCameraPos()
{
	return Vec2(0, 0);
}
#include "GameObject.h"
#include "Component.h"
#include "Rect.h"
#include <iostream>

GameObject::GameObject(float posX, float posY) : m_isDead(false)
{
	box.x = posX;
	box.y = posY;
}

GameObject::~GameObject()
{
	//Component *cpt;
	const int size = m_components.size() - 1;
	for (int i = size; i >= 0 ; --i)
	{
		delete m_components[i]; //???
	}
	m_components.clear();
}

void GameObject::Update(float dt)
{
	const int size = m_components.size();
	for (int i = 0; i < size ; ++i)
	{
		m_components[i]->Update(dt); //???
	}
}

void GameObject::Render()
{
	const int size = m_components.size();
	for (int i = 0; i < size ; ++i)
	{
		m_components[i]->Render(); //???
	}
}

bool GameObject::IsDead()
{
	return m_isDead;
}

void GameObject::RequestDelete()
{
	m_isDead = true;
}

void GameObject::AddComponent(Component* cpt)
{
	m_components.insert(m_components.end(), cpt);
}

void GameObject::RemoveComponent(Component* cpt)
{
	const int size = m_components.size();
	for (int i = 0; i < size ; ++i)
	{
		if(m_components[i] == cpt) // encontra o componente desejado no vector de Component????
		{
			// deleta component
			delete m_components[i];
			//reajusta vector para nao ter espaço vazio
			while(i < size-1)
			{
				m_components[i] = m_components[i+1];
			}
			m_components.erase(m_components.end());
		}
	}
}

Component* GameObject::GetComponent(std::string type)
{
	for (int i = 0; i < (int)m_components.size() ; ++i)
	{
		if(m_components[i]->Is(type)) // encontra o componente desejado no vector de Component????
		{
			//printf("type found: %s\n", type.c_str());
			return m_components[i];
		}
	}
	return nullptr;
}

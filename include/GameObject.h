#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <iostream>
#include <vector>
#include "Rect.h"
class Component;

class GameObject
{
private:
	std::vector <Component*> m_components;
	bool m_isDead;
public:
	Rect box;

	GameObject(float posX, float posY);
	~GameObject();
	void Update(float dt);
	void Render();
	bool IsDead();
	void RequestDelete();
	void AddComponent(Component* cpt);
	void RemoveComponent(Component* cpt);
	Component* GetComponent(std::string type);
};


#endif
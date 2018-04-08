#ifndef FACE_H
#define FACE_H

#include <iostream>
#include "GameObject.h"
#include "Component.h"


class Face : public Component
{
private:
	int m_hitpoints;
public:
	Face(GameObject& associated);
	void Damage(int damage);
	void Damage(float damage);

	void Update(float dt);
	void Render();
	bool Is(std::string type);

	void Open(std::string file);
};

#endif
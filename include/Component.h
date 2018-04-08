#ifndef COMPONENT_H
#define COMPONENT_H

#include <iostream>
#include "GameObject.h"


class Component //Abstract
{
protected:
	GameObject& m_associated;
public:
	Component(GameObject& associated);
	virtual ~Component();
	virtual void Update(float dt) = 0;
	virtual void Render() = 0;
	virtual bool Is(std::string type) = 0;

	virtual void Open(std::string file); //usado no sprite
};

#endif
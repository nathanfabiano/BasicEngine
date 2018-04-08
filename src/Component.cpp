#include "Component.h"
#include "GameObject.h"

Component::Component(GameObject &associated) : m_associated(associated)
{

}

Component::~Component()
{
	//ae
}

void Component::Open(std::string file)
{
	//
}
//Destructor
//O resto é pure virtual
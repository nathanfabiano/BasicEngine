#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <vector>
#include <memory>
#include "GameObject.h"
#include "Sprite.h"
#include "Music.h"

class State
{
private:
	Music m_music;
	bool m_quitRequest;
	std::vector<std::unique_ptr<GameObject>> m_objectArray;

public:
	State();
	~State();
	void LoadAssets();
	void Update(float dt);
	void Render();
	void Input();
	void AddObject(int mouseX, int mouseY);
	GameObject* GetGameObject(int indice);

	bool QuitRequest(){ return m_quitRequest; };
};

#endif
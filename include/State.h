#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <vector>
#include <memory>
#include "GameObject.h"
#include "Sprite.h"
#include "Music.h"
#include "Camera.h"

class State
{
private:
	Music m_music;
	bool m_quitRequest;
	bool m_started;
	std::vector<std::shared_ptr<GameObject>> m_objectArray;
	
public:
	Camera camera;
	
	State();
	~State();
	void LoadAssets();
	void Update(float dt);
	void Render();
	//void Input();
	void AddObject(int mouseX, int mouseY);
	std::weak_ptr<GameObject> AddObject(GameObject* go);
	std::weak_ptr<GameObject> GetObjectPtr(GameObject* go);
	GameObject* GetGameObject(int indice);

	void Start();

	Music* GetMusic() { return &m_music; }; 
	bool QuitRequest(){ return m_quitRequest; };
};

#endif
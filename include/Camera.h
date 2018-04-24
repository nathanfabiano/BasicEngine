#ifndef CAMERA_H
#define CAMERA_H

#include "GameObject.h"
#include "Vec2.h"

class Camera
{
private:
	GameObject* m_focus;
public:
	Vec2 speed;
	Vec2 pos;

	Camera();
	void Follow(GameObject* newFocus);
	void Unfollow();
	void Update(float dt);
};

#endif
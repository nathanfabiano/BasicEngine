#ifndef CAMERA_H
#define CAMERA_H

#include "GameObject.h"
#include "Vec2.h"

class Camera
{
private:
	GameObject* m_focus;

	float CalculateSpeedMulti(int depth);
public:
	Vec2 speed;
	Vec2 pos;

	Camera();
	void Follow(GameObject* newFocus);
	void Unfollow();
	void Update(float dt);
	
	Vec2 GetParallaxPos(int depth);
};

#endif
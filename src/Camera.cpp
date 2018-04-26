#include "Camera.h"
#include "GameObject.h"
#include "InputManager.h"

Camera::Camera() : m_focus{}, speed(300, 300), pos(0, 0)
{
	// speed em pixels/segundo
}

void Camera::Follow(GameObject* newFocus)
{
	m_focus = newFocus;
}

void Camera::Unfollow()
{
	m_focus = nullptr;
}

void Camera::Update(float dt)
{
	if (m_focus == nullptr)
	{
		// Camera Unfollow
		InputManager& input = InputManager::GetInstance();
		if(input.IsKeyDown(206)) // right arrow
		{
			pos.x = pos.x + (speed.x*dt);
		}
		if(input.IsKeyDown(207)) // left arrow
		{
			pos.x = pos.x - (speed.x*dt);
		}
		if(input.IsKeyDown(208)) // bottom arrow
		{
			pos.y = pos.y + (speed.y*dt);
		}
		if(input.IsKeyDown(209)) // top arrow
		{
			pos.y = pos.y - (speed.y*dt);
		}
	}
	else
	{
		// Camera Follow
		pos = m_focus->box.GetPosition();
	}
}

Vec2 Camera::GetParallaxPos(int depth)
{
	float coefficient = CalculateSpeedMulti(depth);

	return Vec2(pos.x * coefficient, pos.y * coefficient);
}

float Camera::CalculateSpeedMulti(int depth)
{
	//Clamp -100 ~ 100
	if (depth > 100)
	{
		depth = 100;
	}
	else
	{
		if (depth < -100)
		{
			depth = -100;
		}
	}
	int complement = 100 - depth;
	
	return (((float)complement)/100.0f);
}
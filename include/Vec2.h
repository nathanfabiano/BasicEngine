#ifndef VEC2_H
#define VEC2_H

#include <iostream>

class Vec2
{
public:
	float x, y;
	Vec2();
	Vec2(float X, float Y);
	Vec2(int X, int Y);

	Vec2 GetRotated(float radian); //em radianos
	friend Vec2 operator+(Vec2 v1, Vec2 v2);
};

#endif
#ifndef VEC2_H
#define VEC2_H

#include "Rect.h"
#include <iostream>

class Vec2
{
public:
	float x, y;

	Vec2(); //Vec(0, 0)
	Vec2(float X, float Y);
	Vec2(int X, int Y);

	Vec2 GetRotated(float radian); //em radianos
	Vec2 GetRotatedDegree(float degree); //em graus
	Vec2 Normalize();

	float Magnitude();
	float Distance(Vec2 v1);
	float GetAngle();
	float GetAngleDegree();

	friend float GetInclination();
	friend float GetInclinationDegree();

	friend Vec2 operator+(Vec2 v1, Vec2 v2);
	friend Vec2 operator-(Vec2 v1, Vec2 v2);

	friend Vec2 operator*(Vec2 v1, int escalar);
	friend Vec2 operator*(int escalar, Vec2 v1);
	friend Vec2 operator*(Vec2 v1, float escalar);
	friend Vec2 operator*(float escalar, Vec2 v1);
	friend Vec2 operator*(Vec2 v1, Vec2 v2);
	
	friend Vec2 operator/(Vec2 v1, int escalar);
	friend Vec2 operator/(Vec2 v1, float escalar);
};

#endif
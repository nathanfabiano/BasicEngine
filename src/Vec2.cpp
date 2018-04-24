#include "Vec2.h"
#include <math.h>
#include "Rect.h"

#define PI 3.1415
    //IMPLEMENTAR GetRotated, operator+
Vec2::Vec2() : x(0), y(0)
{

}

Vec2::Vec2(float X, float Y) : x(X), y(Y)
{

}

Vec2::Vec2(int X, int Y)
{
	x = (float)X;
	y = (float)Y;
}

Vec2 Vec2::GetRotated(float radian)
{
	// --- Matriz de Rotação ---
	//■ x’ = x * cosθ - y * sinθ
	//■ y’ = y * cosθ + x * sinθ

	Vec2 rotatedVec;
	rotatedVec.x = (x * cos(radian)) - (y * sin(radian));
	rotatedVec.y = (y * cos(radian)) + (x * sin(radian));

	return rotatedVec;
}

Vec2 Vec2::GetRotatedDegree(float degree)
{
	return GetRotated(degree*PI/180.0f);
}

float Vec2::Magnitude()
{
	float magnitude = (x*x) + (y*y);
	return sqrt(magnitude);
}

Vec2 Vec2::Normalize()
{
	float magnitude = this->Magnitude();

	return Vec2(x/magnitude, y/magnitude);
}

float Vec2::Distance(Vec2 v1)
{
	return Vec2(x - v1.x, y - v1.y).Magnitude();
}

float Vec2::GetAngle() //???
{
	return atan2(y, x);
}

float Vec2::GetAngleDegree() //???
{
	return (atan2(y, x)*PI/180.0f);
}

float GetInclination(Vec2 v1, Vec2 v2)
{
	Vec2 v3 = v2 - v1;

	return v3.GetAngle();
}

float GetInclinationDegree(Vec2 v1, Vec2 v2)
{
	Vec2 v3 = v2 - v1;

	return v3.GetAngleDegree();
}
//------------------------ OPERATORS ------------------------------
Vec2 operator+(Vec2 v1, Vec2 v2)
{
	return Vec2(v1.x + v2.x, v1.y + v2.y);
}

Vec2 operator-(Vec2 v1, Vec2 v2)
{
	return Vec2(v1.x - v2.x, v1.y - v2.y);
}

Vec2 operator*(Vec2 v1, int escalar)
{
	return Vec2(v1.x * (float)escalar, v1.y * (float)escalar);
}

Vec2 operator*(int escalar, Vec2 v1)
{
	return Vec2(v1.x * (float)escalar, v1.y * (float)escalar);
}

Vec2 operator*(Vec2 v1, float escalar)
{
	return Vec2(v1.x * escalar, v1.y * escalar);
}

Vec2 operator*(float escalar, Vec2 v1)
{
	return Vec2(v1.x * escalar, v1.y * escalar);
}

Vec2 operator/(Vec2 v1, int escalar)
{
	return Vec2(v1.x / (float)escalar, v1.y / (float)escalar);
}

Vec2 operator/(Vec2 v1, float escalar)
{
	return Vec2(v1.x / escalar, v1.y / escalar);
}

Rect operator+(Rect r, Vec2 v)
{
	r.x += v.x;
	r.y += v.y;
	
	return r;
}

Rect operator-(Rect r, Vec2 v)
{
	r.x -= v.x;
	r.y -= v.y;
	
	return r;
}

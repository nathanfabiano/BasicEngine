#include "Vec2.h"
#include <math.h>

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

	//x = rotatedVec.x;
	//y = rotatedVec.y;
	return rotatedVec;
}

Vec2 operator+(Vec2 v1, Vec2 v2)
{
	return Vec2(v1.x + v2.x, v1.y + v2.y);
}

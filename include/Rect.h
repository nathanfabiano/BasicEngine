#ifndef RECT_H
#define RECT_H

#include "Vec2.h"
#include <iostream>

class Vec2;

class Rect
{
public:
	float x, y, w, h;

	Rect();
	Rect(float X, float Y, float W, float H);
	Rect(int X, int Y, int W, int H);

	bool Contains(float x, float y);
	Vec2 GetPosition(); //Vec(x, y)
	Vec2 GetCenter();

	friend Rect operator+(Rect r, Vec2 v);
	friend Rect operator-(Rect r, Vec2 v);
};

#endif
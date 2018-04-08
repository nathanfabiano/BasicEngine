#ifndef RECT_H
#define RECT_H

#include <iostream>

class Rect
{
public:
	float x, y, w, h;
	bool Contains(float x, float y);
};

#endif
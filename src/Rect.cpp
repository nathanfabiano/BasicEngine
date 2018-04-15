#include "Rect.h"
#include "Vec2.h"


Rect::Rect() : x(0.0f), y(0.0f), w(0.0f), h(0.0f)
{

}

Rect::Rect(float X, float Y, float W, float H) : x(X), y(Y), w(W), h(H)
{

}

Rect::Rect(int X, int Y, int W, int H)
{
	x = (float)X;
	y = (float)Y;
	w = (float)W;
	h = (float)H;
}

bool Rect::Contains(float posX, float posY)
{
	if ((posX >= x)&&(posX <= x + w))
	{
		if ((posY >= y)&&(posY <= y + h))
		{
			return true;
		}
	}
	return false;
}

Vec2 Rect::GetPosition()
{
	return Vec2(x, y);
}

Vec2 Rect::GetCenter()
{
	return Vec2(x + w/2, y + h/2);
}

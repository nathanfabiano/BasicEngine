#include "Rect.h"

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
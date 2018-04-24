#ifndef PARALLAX_H
#define PARALLAX_H

#include "GameObject.h"
#include "Component.h"
#include "Vec2.h"
#include <iostream>

class Parallax : public Component
{
private:
	Vec2 m_speedMultiplicator;
	int m_depth;
	bool m_parallaxX;
	bool m_parallaxY;
	Vec2 m_cameraPos;
	// Depth Maxima = 100 (objeto no fundo, no infinito / parado / speedMultiplicator = 0)
	// Depth Padrao = 0 (objeto no plano principal / speedMultiplicator = 1)
	// Depth Minima = -100 (objeto na frente, bem proximo da camera / speedMultiplicator = 2)

	void CalculateSpeedMulti();
public:
	Parallax(GameObject& associated, int depth, bool parallaxX=true, bool parallaxY=true);
	Vec2 GetSpeedMulti();

	void Update(float dt);
	void Render();
	bool Is(std::string type);

	Vec2 GetCameraPos() { return m_cameraPos; };
};

#endif
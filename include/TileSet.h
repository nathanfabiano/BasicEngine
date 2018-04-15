#ifndef TILESET_H
#define TILESET_H

#include "Sprite.h"
#include "Vec2.h"
#include "GameObject.h"
#include <iostream>

class TileSet
{
private:
	Sprite m_tileSet;
	
	int m_rows;
	int m_columns;

	int m_tileWidth;
	int m_tileHeight;
	int m_scale;
public:
	TileSet(GameObject& associated, int tileWidth, int tileHeight, std::string file);
	void Open(std::string file);
	void RenderTile(unsigned index, float x, float y);
	void RenderTile(unsigned index, Vec2 pos);
	
	int GetTileWidth() { return m_tileWidth; };
	int GetTileHeight() { return m_tileHeight; };

	int GetScale() { return m_scale; };
	void SetScale(int scale) { m_scale = scale; };
};

#endif
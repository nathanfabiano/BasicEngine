#ifndef TILEMAP_H
#define TILEMAP_H

#include "Component.h"
#include "TileSet.h"
#include <iostream>

class TileMap : public Component
{
private:
	std::vector<int> m_tileMatrix;
	TileSet* m_tileSet;
	int m_mapWidth;
	int m_mapHeight;
	int m_mapDepth;
public:
	TileMap(GameObject& associated, std::string file, TileSet* tileSet);
	void Load(std::string file);
	void SetTileSet(TileSet *tileSet);
	void OpenTileImg(std::string file);
	int At(int x, int y, int z=0);
	Vec2 GetTilePosition(int index);

	void Render();
	void RenderLayer(int layer, int cameraX=0, int cameraY=0);
	void Update(float dt);
	bool Is(std::string type);

	int GetWidth() { return m_mapWidth; };
	int GetHeight() { return m_mapHeight; };
	int GetDepth() { return m_mapDepth; };
};

#endif
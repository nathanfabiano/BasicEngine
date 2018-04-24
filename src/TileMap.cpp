#include "TileMap.h"
#include "GameObject.h"
#include "TileSet.h"
#include "Game.h"
//#include <stdio>


TileMap::TileMap(GameObject& associated, std::string file, TileSet* tileSet) : Component(associated), m_tileSet(tileSet)
{
	Load(file);
}

void TileMap::OpenTileImg(std::string file)
{
	m_tileSet->Open(file);
}

void TileMap::Load(std::string file)
{
 	FILE *pFile;
 	int i = 0;
 	int aux;
 	printf("ae1\n");
 	pFile = fopen("assets/map/tileMap.txt","r");
 	printf("ae2\n");
 	fscanf (pFile, "%d,%d,%d,", &m_mapWidth, &m_mapHeight, &m_mapDepth);
 	printf("ae3 %d %d %d\n", m_mapWidth, m_mapHeight, m_mapDepth);

 	while(fscanf(pFile, "%d,", &aux) != EOF)
 	{
 		//m_components.insert(m_components.end(), cpt)
 		m_tileMatrix.insert(m_tileMatrix.end(), aux);
 		i++;
 	}

 	fclose(pFile);
}

void TileMap::SetTileSet(TileSet *tileSet)
{
	m_tileSet = tileSet;
}

int TileMap::At(int x, int y, int z)
{
	if ((x >= m_mapWidth)||(y >= m_mapHeight)||(z > m_mapDepth))
	{
		printf("Erro! Index ( %d, %d, %d) não existe.\n", x, y, z);
	}
	//int index = x + y*m_mapWidth + m_mapWidth*m_mapHeight*z;
	return (x + y*m_mapWidth + m_mapWidth*m_mapHeight*z);
}

void TileMap::RenderLayer(int layer, int cameraX, int cameraY)
{
	int index;
	int tileWidth = m_tileSet->GetTileWidth();
	int tileHeight = m_tileSet->GetTileHeight();
	m_tileSet->SetScale(1);

	for (int y = 0; y < m_mapHeight; ++y)
	{
		for (int x = 0; x < m_mapWidth; ++x)
		{
			index = At(x, y, layer);
			if(m_tileMatrix[index] != 0)
			{	// Render Tile com correção da camera aplicada
				m_tileSet->RenderTile((m_tileMatrix[index]-1), ((x*tileWidth/m_tileSet->GetScale()) - cameraX), ((y*tileHeight/m_tileSet->GetScale()) - cameraY));
			}
		}
	}
}

void TileMap::Render()
{
	Game* game = Game::GetInstance();
	for (int i = 0; i < m_mapDepth; ++i)
	{
		RenderLayer(i, game->GetState()->camera.pos.x, game->GetState()->camera.pos.y);
	}
}

void TileMap::Update(float dt)
{

}

bool TileMap::Is(std::string type)
{
	if ((type == "tilemap")||(type == "TileMap")||(type == "TILEMAP")||(type == "tileMap"))
	{
		return true;
	}
	else
	{
		return false;
	}
}

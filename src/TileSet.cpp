#include "TileSet.h"
//#include "Sprite.h"
#include "GameObject.h"
#include <iostream>

//class Sprite;

TileSet::TileSet(GameObject& associated, int tileWidth, int tileHeight, std::string file) : m_tileSet(associated), m_tileWidth(tileWidth), m_tileHeight(tileHeight), m_scale(1)
{
	// file nao utilizado para evitar recursividade na inicializacao de State::State()
	//
}

void TileSet::Open(std::string file)
{
	m_tileSet.Open(file);
	if (m_tileSet.IsOpen())
	{
		m_rows = m_tileSet.GetHeight() / m_tileHeight;
		m_columns = m_tileSet.GetWidth() / m_tileWidth;
	}
}

void TileSet::RenderTile(unsigned index, float x, float y)
{	
	int  indexRows, indexColumns;
	if (index >= (unsigned)(m_rows * m_columns))
	{
		std::cout << "Invalid Index! Index " << index << " not between 0 and " << (m_rows * m_columns) << std::endl;
	}
	else
	{
		indexRows = index / m_columns;
		indexColumns = index - (indexRows * m_columns);

		m_tileSet.SetClip(indexColumns*m_tileWidth, indexRows*m_tileHeight, m_tileWidth, m_tileHeight);
		//Correção de camera
		m_tileSet.Render(x, y, m_tileWidth/m_scale, m_tileHeight/m_scale);
	}
}

void TileSet::RenderTile(unsigned index, Vec2 pos)
{
	RenderTile(index, pos.x, pos.y);
}
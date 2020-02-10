#include "stdafx.h"
#include "TileManager.h"
#include "Game/Object/Tile/Node/TileNode.h"

POINT TileManager::mapSize = defaultMapSize;
D2DPOINTF TileManager::tileSize = { 0.f,0.f };
D2DPOINTF TileManager::pivotPos = { 0.f,0.f };

void TileManager::SetMapInfo(POINT tileMax, D2D1_POINT_2F size, D2D1_POINT_2F mapPivot)
{
	mapSize = tileMax;
	tileSize = size;
	pivotPos = mapPivot;
}

TileManager::TileManager()
{
}


TileManager::~TileManager()
{
}

void TileManager::Initialize()
{
}

void TileManager::Release()
{
}

void TileManager::Update()
{
}

void TileManager::Render()
{
}

void TileManager::CreateMap()
{
	ReleaseMap();

	for (int i = 0; i < mapSize.x * mapSize.y; ++i)
	{
		float x = (i % mapSize.x) * (tileSize.x) + pivotPos.x;
		float y = (i / mapSize.x) * (tileSize.y) + pivotPos.y;

		std::string tempName = "TileNode" + std::to_string(i);

		TileNode* newTile = new TileNode(tempName,D2D1::Point2F(x,y),defaultTileSize);

		mapTiles.push_back(newTile);
	}
}

void TileManager::HighLightOn()
{
}

void TileManager::SaveMap(std::string mapName)
{
	
}

void TileManager::LoadMap(std::string mapName)
{
}

int TileManager::LoadMapData(std::vector<std::string> input)
{
	return 0;
}

TileNode * TileManager::Tile(int x, int y)
{
	return nullptr;
}

void TileManager::ReleaseMap()
{
}

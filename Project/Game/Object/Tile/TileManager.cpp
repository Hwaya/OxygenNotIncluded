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
	ofstream saveOut;
	saveOut.open(ResourcePath + L"/MapData/" + mapName + L".map");

	saveOut << "[MapSize]" << endl;
	saveOut << to_string(mapSize.x) + "," + to_string(mapSize.y) << endl;
	saveOut << "[TileSize]" << endl;
	saveOut << to_string(tileSize.x) + "," + to_string(tileSize.y) << endl;
	saveOut << "[PivotPosition]" << endl;
	saveOut << to_string(pivotPos.x) + "," + to_string(pivotPos.y) << endl;
	saveOut << "[PlayerSpawn]" << endl;
	saveOut << to_string(playerSpawn.x) + "," + to_string(playerSpawn.y) << endl << endl;

	for (int i = 0; i < mapTiles.size(); ++i)
	{
		TileNode* tempTile = mapTiles[i];
		string interpolation = "";
		if (i < 1000) interpolation = "0";
		if (i < 100) interpolation = "00";
		if (i < 10) interpolation = "000";
		saveOut << "[TileNode" + interpolation + to_string(i) + "]" << endl;
		saveOut << "TextureKey:" + tempTile->GetTextureKey() << endl;
		saveOut << "Attribute:" + to_string(tempTile->GetAttribute()) << endl;
		saveOut << "ObjectContainer:";

		unordered_map<ObjectType, vector<GameObject*>> tempStorage = mapTiles[i]->GetStorage();
		unordered_map<ObjectType, vector<GameObject*>>::iterator tempIter = tempStorage.begin(), tempEnd = tempStorage.end();
		for (; tempIter != tempEnd; ++tempIter)
		{
			if ((*tempIter).first != ObjectPlayer)
			{
				vector<GameObject*> tempVector = (*tempIter).second;
				vector<GameObject*>::iterator vectorIter = tempVector.begin(), vectorEnd = tempVector.end();
				if (tempVector.size() > 0)
				{
					saveOut << endl;
				}
				for (; vectorIter != vectorEnd; ++vectorIter)
				{
					saveOut << (*vectorIter)->Name();
				}
			}
		}
		saveOut << endl;
	}
	saveOut.close();
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

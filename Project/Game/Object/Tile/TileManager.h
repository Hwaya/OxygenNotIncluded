#pragma once
#include "TileInfo.h"

class TileNode;

class TileManager
{
	static POINT mapSize;
	static D2D1_POINT_2F tileSize;
	static D2D1_POINT_2F pivotPos;

	static void SetMapInfo(POINT tileMax, D2D1_POINT_2F size, D2D1_POINT_2F mapPivot);
public:
	TileManager();
	~TileManager();

	void Initialize();
	void Release();
	void Update();
	void Render();

	void CreateMap();

	void HighLightOn();

	void SaveMap(std::string mapName);
	void LoadMap(std::string mapName);
	int LoadMapData(std::vector<std::string> input);

	TileNode* Tile(int x, int y);

	POINT GetMapSize() { return mapSize; }
	D2DPOINTF GetTileSize() { return tileSize; }
	D2DPOINTF GetPivotPos() { return pivotPos; }

private:
	std::vector<TileNode*> tileStorage;
	typedef std::vector<TileNode*>::iterator VecIter;

	void ReleaseMap();

	void SetMapSize(POINT input)
	{
		ReleaseMap();
		mapSize = input;
		CreateMap();

	}
	void SetTileSize(D2DPOINTF input)
	{
		ReleaseMap();
		tileSize = input;
		CreateMap();
	}
	void SetPivotPos(D2DPOINTF input)
	{
		ReleaseMap();
		pivotPos = input;
		CreateMap();
	}
};


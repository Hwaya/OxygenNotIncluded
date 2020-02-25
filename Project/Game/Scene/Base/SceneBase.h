#pragma once

#include "./Game/Object/Tile/TileManager.h"
#include "./Game/Object/ObjectManager.h"
#include "./Game/GameData.h"

class TileManager;
class ObjectManager;
class AstarComponent;

class SceneBase
{
protected:
	
public:
	static TileManager* tileManager;
	static ObjectManager* objectManager;
	static AstarComponent* astar;
	static GameData* gameData;
	static TileManager* GetTileManager();
	static ObjectManager* GetObjectManager();
	static AstarComponent* GetAstar();
	static GameData* GetData();

public:
	SceneBase();
	~SceneBase();

	virtual void Initialize();
	virtual void Release();
	virtual void Update();
	virtual void Render();
	
	virtual void ImageLoad();


};

#define TILE SceneBase::GetTileManager()
#define OBJECT SceneBase::GetObjectManager()
#define ASTAR SceneBase::GetAstar()
#define DATA SceneBase::GetData()
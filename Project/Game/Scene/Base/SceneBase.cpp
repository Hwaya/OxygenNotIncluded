#include "stdafx.h"
#include "SceneBase.h"


TileManager* SceneBase::tileManager = nullptr;
ObjectManager* SceneBase::objectManager = nullptr;
AstarComponent* SceneBase::astar = nullptr;
GameData* SceneBase::gameData = nullptr;

SceneBase::SceneBase()
{
}

SceneBase::~SceneBase()
{
}

void SceneBase::Initialize()
{
	objectManager = new ObjectManager;
	objectManager->Initialize();
	tileManager = new TileManager;
	tileManager->Initialize();
	astar = new AstarComponent;
	astar->Initialize();
	gameData = new GameData;
	//gameData->Initialize();
}

void SceneBase::Release()
{
	tileManager->Release();
	objectManager->Release();
}

void SceneBase::Update()
{
	tileManager->Update();
	objectManager->Update();
}

void SceneBase::Render()
{
	tileManager->Update();
	objectManager->Render();
}

void SceneBase::ImageLoad()
{
}

TileManager * SceneBase::GetTileManager()
{
	return tileManager;
}

ObjectManager * SceneBase::GetObjectManager()
{
	return objectManager;
}

AstarComponent * SceneBase::GetAstar()
{
	return astar;
}

GameData * SceneBase::GetData()
{
	return gameData;
}

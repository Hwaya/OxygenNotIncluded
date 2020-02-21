#include "stdafx.h"
#include "SceneBase.h"
#include "./Game/Object/Tile/TileManager.h"
#include "./Game/Object/ObjectManager.h"

TileManager* SceneBase::tileManager = nullptr;
ObjectManager* SceneBase::objectManager = nullptr;

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

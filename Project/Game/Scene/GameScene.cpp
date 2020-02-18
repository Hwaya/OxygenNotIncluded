#include "stdafx.h"
#include "GameScene.h"
#include "./Game/Object/Tile/TileManager.h"
#include "./Game/Object/Tile/Node/TileNode.h"

class TileNode;

GameScene::GameScene()
{
	ImageLoad();
	tile = new TileManager;
}

GameScene::~GameScene()
{
}

void GameScene::Initialize()
{
	tile->SetMapInfo({ 10,10 }, D2DPOINTF(50.f, 50.f), D2DPOINTF(25.f, 25.f));
	tile->CreateMap();

	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			tile->Tile(j, i)->SetIsSolid(true);
			tile->Tile(j, i)->SetSolid(SolidRock);
		}
	}
	RENDER.AddFont("±¼¸²", 20.f);
}

void GameScene::Release()
{
}

void GameScene::Update()
{
	CAMERA.Update();
}

void GameScene::Render()
{
	IMAGE.Find("Background")->Render(WINSIZEX / 2.f, WINSIZEY / 2.f, 3000, 3000);

	OBJECT.Render();
}

void GameScene::ImageLoad()
{
	IMAGE.Add("Background", _ResourcePath + "BackGround/BGfrozen.png");

	IMAGE.Add("Solid_Dirt", _ResourcePath + _TilePath + _SolidPath + "Dirt.png");
	IMAGE.Add("Solid_Metal", _ResourcePath + _TilePath + _SolidPath + "Metal.png");
	IMAGE.Add("Solid_Rock", _ResourcePath + _TilePath + _SolidPath + "Rock.png");
}
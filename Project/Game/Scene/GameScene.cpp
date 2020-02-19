#include "stdafx.h"
#include "GameScene.h"

GameScene::GameScene()
{
}

GameScene::~GameScene()
{
}

void GameScene::Initialize()
{
	OBJECT.Initialize();
	ImageLoad();

	/* Tile Initialize */
	tile = new TileManager;
	tile->SetMapInfo({ 30,30 }, D2DPOINTF(100.f, 100.f), D2DPOINTF(0.f, 0.f));
	tile->CreateMap();

	for (int i = 0; i < tile->GetMapSize().y; ++i)
	{
		for (int j = 0; j < tile->GetMapSize().x; ++j)
		{
			tile->Tile(j, i)->SetIsSolid(true);
			tile->Tile(j, i)->SetSolid(SolidRock);
		}
	}
	for (int i = 3; i < 5; ++i)
	{
		for (int j = 3; j < 10; ++j)
		{
			tile->Tile(j, i)->SetIsSolid(false);
			tile->Tile(j, i)->SetSolid(SolidNone);
		}
	}

	/* TestClone */
	OBJECT.NewObject<Clone>(
		"TestClone",
		IndexToPos(2,2, D2DPOINTF(100.f, 100.f), D2DPOINTF(0.f, 0.f)),
		D2DPOINTF(50.f, 50.f)
		);
}

void GameScene::Release()
{
}

void GameScene::Update()
{
	OBJECT.Update();
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
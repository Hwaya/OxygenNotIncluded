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

	D2DPOINTF cameraLoca = CAMERA.GetView().GetPosition();
	D2DPOINTF mouseLoca = D2DPOINTF(MOUSE.GetPosition().x, MOUSE.GetPosition().y);

	RENDER.Text(
		std::to_string(mouseLoca.x) + "," + std::to_string(mouseLoca.y),
		"±¼¸²",
		MakeRect(mouseLoca.x, mouseLoca.y + 30, 500, 100),
		MakeColor(200, 100, 100),
		0.f
	);

	RENDER.Text(
		std::to_string(cameraLoca.x) + "," + std::to_string(cameraLoca.y),
		"±¼¸²",
		MakeRect(mouseLoca.x, mouseLoca.y + 80, 500, 100),
		MakeColor(100, 200, 100)
	);

	RENDER.Text(
		std::to_string(mouseLoca.x) + "," + std::to_string(mouseLoca.y),
		"±¼¸²",
		MakeRect(100, 100, 500, 100)
	);
}

void GameScene::ImageLoad()
{
	IMAGE.Add("Background", _ResourcePath + "BackGround/BGfrozen.png");

	IMAGE.Add("Solid_Dirt", _ResourcePath + _TilePath + _SolidPath + "Dirt.png");
	IMAGE.Add("Solid_Metal", _ResourcePath + _TilePath + _SolidPath + "Metal.png");
	IMAGE.Add("Solid_Rock", _ResourcePath + _TilePath + _SolidPath + "Rock.png");
}
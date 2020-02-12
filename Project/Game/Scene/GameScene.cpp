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
	tile->SetMapInfo({ 10,10 },D2D1::Point2F(50.f,50.f),D2D1::Point2F(100.f,100.f));
	tile->CreateMap();
	tile->Tile(5, 5)->SetIsSolid(true);
	tile->Tile(5, 5)->SetSolid(SolidRock);
	tile->Tile(4, 4)->SetIsSolid(true);
	tile->Tile(4, 4)->SetSolid(SolidMetal);
	tile->Tile(3, 3)->SetIsSolid(true);
	tile->Tile(3, 3)->SetSolid(SolidDirt);
}

void GameScene::Release()
{
}

void GameScene::Update()
{
	
}

void GameScene::Render()
{
	IMAGE.Find("Background")->Render(WINSIZEX / 2.f, WINSIZEY / 2.f, 3000, 3000);
	tile->Tile(5, 5)->Render();
	tile->Tile(4, 4)->Render();
	tile->Tile(3, 3)->Render();
}

void GameScene::ImageLoad()
{
	IMAGE.Add("Background", _ResourcePath + "BackGround/BGfrozen.png");
	
	std::string tilePath = "Tile/";
	std::string solidPath = "Solid/";
	IMAGE.Add("Solid_Dirt", _ResourcePath + tilePath + solidPath + "Dirt.png");
	IMAGE.Add("Solid_Metal", _ResourcePath + tilePath + solidPath + "Metal.png");
	IMAGE.Add("Solid_Rock", _ResourcePath + tilePath + solidPath + "Rock.png");
}
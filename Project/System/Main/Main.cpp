#include "stdafx.h"
#include "Main.h"
#include "./Game/Object/Base/Object.h"
#include "./Game/Scene/Base/SceneBase.h"
#include "./Game/Scene/GameScene.h"

Main::Main()
{

}

Main::~Main()
{
}

HRESULT Main::Initialize()
{
	SCENEMANAGER.AddScene("TestScene", new SceneBase());
	SCENEMANAGER.AddScene("GameScene", new GameScene());
	SCENEMANAGER.SwapScene("GameScene");

	return S_OK;
}

void Main::Release()
{
	SCENE->Release();
}

void Main::Update()
{
	SCENE->Update();
}

void Main::Render()
{
	RENDER.DebugMode(true);
	SCENE->Render();
}

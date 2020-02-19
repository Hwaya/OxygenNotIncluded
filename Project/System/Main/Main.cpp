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
	debugMode = false;
	
	LoadResources();
	CAMERA.Initialize();

	return S_OK;
}

void Main::Release()
{
	SCENE->Release();
}

void Main::Update()
{
	CAMERA.Update();
	SCENE->Update();
}

void Main::Render()
{
	SCENE->Render();

	if (KEYBOARD.Down(VK_F1))
	{
		debugMode = !debugMode;
		RENDER.DebugMode(debugMode);
	}
	if (KEYBOARD.Down(VK_ESCAPE))
	{
		PostQuitMessage(0);
	}

	if (RENDER.IsDebugMode())
	{
		D2DPOINTF cameraLoca = CAMERA.GetView().GetPosition();
		D2DPOINTF mouseLoca = D2DPOINTF(MOUSE.GetPosition().x, MOUSE.GetPosition().y);
		
		RENDER.Text(
			"Debug Mode",
			"±¼¸²20",
			MakeRect(250, 50, 500, 100),
			MakeColor(200.f, 100.f, 100.f),
			0.f
		);

		//Mouse Location
		RENDER.Text(
			std::to_string(mouseLoca.x) + "," + std::to_string(mouseLoca.y),
			"±¼¸²20",
			MakeRect(mouseLoca.x + 150 , mouseLoca.y + 100, 500, 100),
			MakeColor(200, 100, 100),
			0.f
		);
		//Camera Location
		RENDER.Text(
			std::to_string(cameraLoca.x) + "," + std::to_string(cameraLoca.y),
			"±¼¸²20",
			MakeRect(mouseLoca.x + 150 , mouseLoca.y + 150, 500, 100),
			MakeColor(100, 200, 100)
		);
		//Wheel Value
		RENDER.Text(
			std::to_string(MOUSE.GetWheelValue()), 
			"±¼¸²20", 
			MakeRect(mouseLoca.x + 150 , mouseLoca.y + 200, 500, 100),
			MakeColor(100, 100, 100), 0.f);
	}



}

void Main::LoadResources()
{
	/* Images */
	

	/* Font */
	RENDER.AddFont("±¼¸²20", 20.f);
	RENDER.AddFont("±¼¸²10", 10.f);

	/* Scene */
	SCENEMANAGER.AddScene("TestScene", new SceneBase());
	SCENEMANAGER.AddScene("GameScene", new GameScene());
	SCENEMANAGER.SwapScene("GameScene");

	/* Test */
	IMAGE.Add("Test", _ResourcePath + "Test/FrameTest.png", 16, 1);
}

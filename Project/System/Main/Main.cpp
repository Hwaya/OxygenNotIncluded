#include "stdafx.h"
#include "Main.h"
#include "./Game/Object/Base/Object.h"
#include "./Game/Scene/Base/SceneBase.h"

Bedrock::Bedrock()
{

}

Bedrock::~Bedrock()
{
}

HRESULT Bedrock::Initialize()
{
	IMAGE.Add("Test", _ResourcePath + "Test/Test.png");

	SCENEMANAGER.AddScene("TestScene", new SceneBase());
	SCENEMANAGER.SwapScene("TestScene");

	return S_OK;
}

void Bedrock::Release()
{
}

void Bedrock::Update()
{
}

void Bedrock::Render()
{
	IMAGE.Find("Test")->Render(100, 100, 100, 100, 1);
}

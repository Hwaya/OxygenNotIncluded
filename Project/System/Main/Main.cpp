#include "stdafx.h"
#include "Main.h"
#include "./Game/Object/Base/Object.h"

Bedrock::Bedrock()
{

}

Bedrock::~Bedrock()
{
}

HRESULT Bedrock::Initialize()
{
	IMAGEMANAGER.Add("Test", _ResourcePath + "Test/Test.png");
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
	IMAGEMANAGER.Find("Test")->Render(100, 100, 100, 100, 1);
}

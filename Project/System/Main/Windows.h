#pragma once

#include "../Base/Resource.h"

void SingletonCreate()
{
	Renderer::Create();
	ImageManager::Create();
	SceneManager::Create();
	ObjectManager::Create();
}
void SingletonInitialize()
{
	RENDER.Initialize();
	IMAGE.Initialize();
	SCENEMANAGER.Initialize();
	OBJECT.Initialize();
}

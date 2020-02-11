#pragma once

#include "../Base/Resource.h"

void SingletonCreate()
{
	Renderer::Create();
	ImageManager::Create();
	SceneManager::Create();
}
void SingletonInitialize()
{
	RENDER.Initialize();
	IMAGE.Initialize();
	SCENEMANAGER.Initialize();
}

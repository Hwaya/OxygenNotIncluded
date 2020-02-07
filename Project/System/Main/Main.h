#pragma once

#include "../Base/Resource.h"

void SingletonCreate()
{
	Renderer::Create();
	ImageManager::Create();
}
void SingletonInitialize()
{
	RENDER.Initialize();
	IMAGEMANAGER.Initialize();
}

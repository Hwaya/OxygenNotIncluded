#pragma once

#include "../Base/Resource.h"

void CreateSingleton()
{
	Renderer::Create();
	ImageManager::Create();
}

#define RENDERER Renderer::Get()
#define IMAGEMANAGER ImageManager::Get()

int cnt = 0;
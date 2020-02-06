#pragma once

#include "../Base/Resource.h"

void CreateSingleton()
{
	Renderer::Create();
	Renderer::Get().Initialize();
	ImageManager::Create();
	ImageManager::Get().Initialize();
}

#define RENDERER Renderer::Get();
#define IMAGEMANAGER ImageManager::Get();
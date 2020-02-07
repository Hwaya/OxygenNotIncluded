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
float rot = 0.f;
float alp = 0.f;
#pragma once

#include "../Base/Resource.h"

void SingletonCreate()
{
	Renderer::Create();
	ImageManager::Create();
	Mouse::Create();
	Keyboard::Create();

	SceneManager::Create();
	ObjectManager::Create();
}

void SingletonInitialize()
{
	RENDER.Initialize();
	IMAGE.Initialize();
	MOUSE.Initialize();
	KEYBOARD.Initialize();

	SCENEMANAGER.Initialize();
	OBJECT.Initialize();
}

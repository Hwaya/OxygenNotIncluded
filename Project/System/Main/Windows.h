#pragma once

#include "../Base/Resource.h"

void SingletonCreate()
{
	Renderer::Create();
	ImageManager::Create();
	Mouse::Create();
	Keyboard::Create();
	Camera::Create();

	SceneManager::Create();
}

void SingletonInitialize()
{
	RENDER.Initialize();
	IMAGE.Initialize();
	MOUSE.Initialize();
	KEYBOARD.Initialize();
	CAMERA.Initialize();

	SCENEMANAGER.Initialize();
}

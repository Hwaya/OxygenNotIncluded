#include "stdafx.h"
#include "SceneManager.h"
#include "Base/SceneBase.h"

SINGLETONCPP(SceneManager)

SceneBase* SceneManager::currentScene = nullptr;

SceneBase * SceneManager::GetCurrentScene()
{
	return currentScene;
}

void SceneManager::Initialize()
{
}

SceneBase* SceneManager::AddScene(std::string key, SceneBase * scene)
{
	MapIter finder = mapScene.find(key);
	if (finder == mapScene.end())
	{
		scene->Initialize();
		mapScene.insert(make_pair(key, scene));
		return mapScene[key];
	}
	else
	{
		return finder->second;
	}
}

SceneBase* SceneManager::FindScene(std::string key)
{
	MapIter finder = mapScene.find(key);
	if (finder != mapScene.end())
	{
		return finder->second;
	}
	else
	{
		return nullptr;
	}
}

void SceneManager::DeleteScene(std::string key)
{
	MapIter finder = mapScene.find(key);
	if (finder != mapScene.end())
	{
		mapScene.erase(finder);
	}
}

void SceneManager::SwapScene(std::string key)
{
	MapIter finder = mapScene.find(key);
	if (finder != mapScene.end())
	{
		currentScene = finder->second;
	}
}

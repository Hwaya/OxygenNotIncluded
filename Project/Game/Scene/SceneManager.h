#pragma once

class SceneBase;

//SceneBase* SceneManager::currentScene = nullptr;

class SceneManager
{
	SINGLETONHEADER(SceneManager)
public:
	static SceneBase* currentScene;
	static SceneBase* GetCurrentScene();
private:
	std::unordered_map < std::string, SceneBase*> mapScene;
	typedef std::unordered_map <std::string, SceneBase*>::iterator MapIter;

public:
	void Initialize();

	SceneBase* AddScene(std::string key, SceneBase* scene);
	SceneBase* FindScene(std::string key);
	void DeleteScene(std::string key);
	void SwapScene(std::string key);
};

#define SCENEMANAGER SceneManager::Get()
#define SCENE SceneManager::GetCurrentScene()
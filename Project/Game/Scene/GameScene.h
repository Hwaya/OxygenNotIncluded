#pragma once
#include "Base/SceneBase.h"

class TileManager;

class GameScene : public SceneBase
{
private:
	TileManager* tile;
public:
	GameScene();
	~GameScene();

	virtual void Initialize();
	virtual void Release();
	virtual void Update();
	virtual void Render();
	virtual void ImageLoad();
};


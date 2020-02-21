#pragma once
#include "Base/SceneBase.h"
#include "./Game/Object/Clone/Clone.h"
#include "./Game/Object/Tile/Node/TileNode.h"

class GameScene : public SceneBase
{
private:
	
public:
	GameScene();
	~GameScene();

	virtual void Initialize();
	virtual void Release();
	virtual void Update();
	virtual void Render();
	virtual void ImageLoad();
};


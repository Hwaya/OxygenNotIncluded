#pragma once
#include "Base/SceneBase.h"
#include "./Game/Object/Clone/Clone.h"
#include "./Game/Object/Tile/Node/TileNode.h"
#include "./Game/UI/UIButton.h"

class GameScene : public SceneBase
{
private:
	PickMode currentPickMode;

	bool newInput;
	D2DPOINTF oldPoint;
	D2DRECTF selectRect;
public:
	GameScene();
	~GameScene();

	virtual void Initialize();
	virtual void Release();
	virtual void Update();
	virtual void Render();
	virtual void ImageLoad();
};


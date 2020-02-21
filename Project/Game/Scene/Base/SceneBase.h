#pragma once

class TileManager;
class ObjectManager;

class SceneBase
{
protected:
	
public:
	static TileManager* tileManager;
	static ObjectManager* objectManager;
	static TileManager* GetTileManager();
	static ObjectManager* GetObjectManager();

public:
	SceneBase();
	~SceneBase();

	virtual void Initialize();
	virtual void Release();
	virtual void Update();
	virtual void Render();
	
	virtual void ImageLoad();


};

#define TILE SceneBase::GetTileManager()
#define OBJECT SceneBase::GetObjectManager()
#pragma once
class SceneBase
{
private:

public:
	SceneBase();
	~SceneBase();

	virtual void Initialize();
	virtual void Release();
	virtual void Update();
	virtual void Render();
	
	virtual void ImageLoad();
};
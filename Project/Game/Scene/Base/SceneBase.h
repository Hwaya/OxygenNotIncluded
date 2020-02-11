#pragma once
class SceneBase
{
public:
	SceneBase();
	~SceneBase();

	virtual void Initialize();
	virtual void Release();
	virtual void Update();
	virtual void Render();
};
#pragma once
class Main
{
private:
	bool debugMode;

	int fx, fy;
public:
	Main();
	~Main();

	HRESULT Initialize();
	void Release();
	void Update();
	void Render();

	void LoadResources();
};


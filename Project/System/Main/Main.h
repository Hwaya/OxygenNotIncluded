#pragma once
class Main
{
private:

public:
	Main();
	~Main();

	HRESULT Initialize();
	void Release();
	void Update();
	void Render();
};


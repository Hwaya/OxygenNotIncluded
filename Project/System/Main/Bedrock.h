#pragma once
class Bedrock
{
private:

public:
	Bedrock();
	~Bedrock();

	HRESULT Initialize();
	void Release();
	void Update();
	void Render();
};


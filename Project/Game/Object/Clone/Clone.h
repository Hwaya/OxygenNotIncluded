#pragma once
#include "./Game/Object/Clone/State/StateManager.h"

class Clone : public Object
{
private:
	CloneInfo info;
	CloneInfo oldInfo;
	StateManager* state;
public:
	Clone(std::string name, D2DPOINTF pos, D2DPOINTF size, bool ui, float rotation);
	~Clone();

	virtual void Initialize();
	virtual void Release();
	virtual void Update();
	virtual void Render();
	
	CloneInfo& GetInfo() { return info; }
	CloneInfo& GetOldInfo() { return oldInfo; }
};


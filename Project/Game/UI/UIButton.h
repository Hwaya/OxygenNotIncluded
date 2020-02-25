#pragma once
#include "Game/UI/Base/UIBase.h"

class UIButton : public UIBase
{
private:
	MessageData* msg;

	
	std::string imgKey; 
public:
	UIButton(std::string inputName, D2DPOINTF pos, D2DPOINTF size, bool ui, float rotation);
	virtual ~UIButton();

	virtual void Initialize();
	virtual void Release();
	virtual void Update();
	virtual void Render();

	void SetIcon(std::string key);


};


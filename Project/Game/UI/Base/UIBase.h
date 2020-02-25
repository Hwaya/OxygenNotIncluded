#pragma once
class UIBase : public Object
{
private:

protected:
	bool isMouseOn;
	bool isSelected;

public:
	UIBase(std::string inputName, D2DPOINTF pos, D2DPOINTF size, bool ui, float rotation);
	virtual ~UIBase();

	virtual void Initialize();
	virtual void Release();
	virtual void Update();
	virtual void Render();

	bool GetMouseOn() { return isMouseOn; }
	bool IsSelected() { return isSelected; }
};


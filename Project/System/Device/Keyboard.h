#pragma once

#define KEYMAX 255

enum KEYSTATE
{
	KEYSTATE_NONE = 0,
	KEYSTATE_DOWN,
	KEYSTATE_UP,
	KEYSTATE_STAY
};

class Keyboard
{
	SINGLETONHEADER(Keyboard)
private:
	BYTE keyState[KEYMAX];
	BYTE keyOldState[KEYMAX];
	BYTE keyMap[KEYMAX];

public:
	void Initialize();
	void Update();

	bool Down(DWORD key)
	{
		return keyMap[key] == KEYSTATE_DOWN;
	}
	bool Up(DWORD key)
	{
		return keyMap[key] == KEYSTATE_UP;
	}
	bool Stay(DWORD key)
	{
		return keyMap[key] == KEYSTATE_STAY;
	}
};

#define KEYBOARD Keyboard::Get()
#include "stdafx.h"
#include "Keyboard.h"

SINGLETONCPP(Keyboard)

void Keyboard::Initialize()
{
	ZeroMemory(keyState, sizeof(keyState));
	ZeroMemory(keyOldState, sizeof(keyOldState));
	ZeroMemory(keyMap, sizeof(keyMap));
}

void Keyboard::Update()
{
	int a = 0;
	memcpy(keyOldState, keyState, sizeof(keyOldState));

	ZeroMemory(keyState, sizeof(keyState));
	ZeroMemory(keyMap, sizeof(keyMap));

	GetKeyboardState(keyState);

	for (DWORD i = 0; i < KEYMAX; ++i)
	{
		BYTE key = keyState[i] & 0x80;
		keyState[i] = key ? 1 : 0;

		int oldState = keyOldState[i];
		int state = keyState[i];

		if (oldState == 0 && state == 1)
		{
			keyMap[i] = KEYSTATE_DOWN;
		}
		else if (oldState == 1 && state == 0)
		{
			keyMap[i] = KEYSTATE_UP;
		}
		else if (oldState == 1 && state == 1)
		{
			keyMap[i] = KEYSTATE_STAY;
		}
		else
		{
			keyMap[i] = KEYSTATE_NONE;
		}
	}
}

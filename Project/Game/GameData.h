#pragma once
#include "./Game/Object/Clone/State/Base/StateBase.h"

struct CloneInfo
{
	float o2Efficiency;
	float co2Efficiency;
	int peeEfficiency;
	float structEfficiency;
	float miningEfficiency;
	float speed;
	CloneInfo()
	{
		Initialize();
	}
	void Initialize()
	{
		o2Efficiency = _o2Rate;
		co2Efficiency = _co2Rate;
		peeEfficiency = _peeRate;
		structEfficiency = _structSpeed;
		miningEfficiency = _miningSpeed;
		speed = _speed;
	}
};

class GameData
{
};


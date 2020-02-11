#pragma once
#include "./Game/Object/Tile/TileInfo.h"

enum ProcessType
{
	ProcessBegin = 0,
	ProcessNone,
	ProcessAdd,
	ProcessSubstract,
	ProcessEnd
};

enum DirectionType
{
	DirectionBegin = 0,
	DirectionNone,
	DirectionLeft,
	DirectionUp,
	DirectionRight,
	DirectionDown,
	DirectionEnd
};

class MessageData
{
public:
	MessageData();
	~MessageData();

	ProcessType process;
	DirectionType direction;

	std::unordered_map <GasType, float> mapGas;
	std::unordered_map <FluidType, float> mapFluid;
};


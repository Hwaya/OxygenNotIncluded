#pragma once
#include "./Game/Object/Tile/TileInfo.h"

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

	DirectionType direction;
	float processTime;
	float polution;

	std::unordered_map <GasType, float> mapGas;
	typedef std::unordered_map<GasType, float>::iterator GasIter;
	std::unordered_map <FluidType, float> mapFluid;
	typedef std::unordered_map<FluidType, float>::iterator FluidIter;
};


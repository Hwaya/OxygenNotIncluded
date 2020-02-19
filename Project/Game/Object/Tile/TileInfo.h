#pragma once
#include "stdafx.h"

/* info */

enum AttributeType
{
	AttributeStart = 0,
	AttributeNone,
	AttributeLock,
	AttributeEnd
};

enum GasType
{
	GasStart = 0,
	GasNone,
	GasOxygen,
	GaspollutedOxtgen,
	GasCarbonDioxide,
	GasEnd
};

enum FluidType
{
	FluidStart = 0,
	FluidNone,
	FluidWater,
	FluidPollutedWater,
	FluidEnd
};

enum SolidType
{
	SolidStart = 0,
	SolidNone,
	SolidDirt,
	SolidRock,
	SolidMetal,
	SolidStructure,
	SolidEnd
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

struct TileInfo
{
	DirectionType direction;
	AttributeType attribute;

	float life;
	float pollution;
	float temperature;

	bool isSolid;
	SolidType solidType;

	std::unordered_map<GasType, float> mapGas;
	typedef std::unordered_map<GasType, float>::iterator GasIter;
	std::unordered_map<FluidType, float> mapFluid;
	typedef std::unordered_map<FluidType, float>::iterator FluidIter;
	
	TileInfo() 
	{
		direction = DirectionNone;
		attribute = AttributeNone;

		life = 0.f;
		pollution = 0.f;
		temperature = 0.f;

		isSolid = false;
		solidType = SolidNone;

		for (int a = GasStart; a != GasEnd; ++a)
		{
			if (a != GasStart && a != GasEnd)
			{
				mapGas.insert(std::make_pair((GasType)a, 0.f));
			}
		}
		for (int a = FluidStart; a != FluidEnd; ++a)
		{
			if (a != FluidStart && a != FluidEnd)
			{
				mapFluid.insert(std::make_pair((FluidType)a, 0.f));
			}
		}
	}
};

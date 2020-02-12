#include "stdafx.h"
#include "MessageData.h"


MessageData::MessageData()
{	
	direction = DirectionNone;

	for (int i = GasStart; i != GasEnd; ++i)
	{
		if (i != GasStart && i != GasEnd)
		{
			mapGas.insert(std::make_pair((GasType)i, 0.f));
		}
	}
	for (int i = FluidStart; i != FluidEnd; ++i)
	{
		if (i != FluidStart && i != FluidEnd)
		{
			mapFluid.insert(std::make_pair((FluidType)i, 0.f));
		}
	}	
}

MessageData::~MessageData()
{
}

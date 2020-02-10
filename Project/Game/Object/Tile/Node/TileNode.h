#pragma once
#include "../TileInfo.h"

class TileNode : public Object
{
private:
	TileInfo info;

public:
	TileNode(std::string name, D2D1_POINT_2F pos, D2D1_POINT_2F size, float rotation= 0.f);
	virtual ~TileNode();

	virtual void Initialize();
	virtual void Release();
	virtual void Update();
	virtual void Render();

	AttributeType& GetAttribute() { return info.attribute; }
	float& GetPollution() { return info.pollution; }
	bool& IsSolid() { return info.isSolid; }
	SolidType GetSolid() { return info.solidType; }
	float& GetGas(GasType type) { return info.mapGas[type]; }
	float& GetFluid(FluidType type) { return info.mapFluid[type]; }

	void SetAttribute(AttributeType inputType) { info.attribute = inputType; }
	void SetPollution(float inputValue) { info.pollution = inputValue; }
	void SetIsSolid(bool input) { info.isSolid = input; }
	void SetSolid(SolidType type) { info.solidType = type; }
	void SetGas(GasType type, float value) { info.mapGas[type] = value; }
	void SetFluid(FluidType type, float value) { info.mapFluid[type] = value; }
};

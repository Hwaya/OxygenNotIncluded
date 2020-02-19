#include "stdafx.h"
#include "TileNode.h"
#include "./System/Message/MessageData.h"

class MessageData;

TileNode::TileNode(std::string name, D2D1_POINT_2F pos, D2D1_POINT_2F size, float rotation )
	:Object(name,pos,size,rotation)
{
	debugToggle = false;
}

TileNode::~TileNode()
{
}

void TileNode::Initialize()
{
	AddCallBack("SetData", [&](MessageData msg) 
	{
		MessageData::GasIter giter = msg.mapGas.begin();
		for (; giter != msg.mapGas.end(); ++giter)
		{
			if (giter->second != 0.f)
			{
				info.mapGas[giter->first] += giter->second;
			}
		}
		MessageData::FluidIter fiter = msg.mapFluid.begin();
		for (; fiter != msg.mapFluid.end(); ++fiter)
		{
			if (fiter->second != 0.f)
			{
				info.mapFluid[fiter->first] += fiter->second;
			}
		}
		info.pollution += msg.polution;
	});
	AddCallBack("Extract", [&](MessageData msg)
	{
		if (info.isSolid)
		{
			info.life -= msg.damage;
		}
	});
}

void TileNode::Release()
{
}

void TileNode::Update()
{
	if (info.life < 0)
	{

	}

	if (RENDER.IsDebugMode())
	{
		if (KEYBOARD.Down(VK_F2))
		{
			debugToggle = !debugToggle;
		}
	}
}

void TileNode::Render()
{
	if (info.isSolid)
	{
		std::string tempKey;
		switch (info.solidType)
		{
		case SolidDirt:
			tempKey = "Solid_Dirt";
			break;
		case SolidRock:
			tempKey = "Solid_Rock";
			break;
		case SolidMetal:
			tempKey = "Solid_Metal";
			break;
		case SolidStructure:
			break;
		}
		Matrix renderMat = RENDER.RenderSet(*transform, true, true);

		IMAGE.Find(tempKey)->Render(
			renderMat.GetPosition().x,
			renderMat.GetPosition().y,
			renderMat.GetScale().x,
			renderMat.GetScale().y);
	}
	else
	{

	}

	Matrix renderMat = RENDER.RenderSet(*transform, true, true);
	D2DRECTF tempRc = MakeRect(
		renderMat.GetPosition().x,
		renderMat.GetPosition().y,
		renderMat.GetScale().x,
		renderMat.GetScale().y
	);
	if (PointInRect(MOUSE.GetPosition().x, MOUSE.GetPosition().y, tempRc))
	{
		RENDER.DrawRectangle(tempRc, D2D1::ColorF(250, 100, 100), 5);
	}

	Object::Render();
	if (RENDER.IsDebugMode() && PointInRect(MOUSE.GetPosition().x, MOUSE.GetPosition().y, tempRc))
	{
		if (!debugToggle) 
		{
			for (int i = GasStart; i != GasEnd; ++i)
			{
				if ((GasType)i != GasStart || (GasType)i != GasEnd)
				{
					RENDER.Text("GType" + std::to_string(i) + " : " + std::to_string(info.mapGas[(GasType)i]),
						"±¼¸²10",
						MakeRect(renderMat.GetPosition().x + 150, renderMat.GetPosition().y - 150 + i * 10, 500.f, 10.f),
						MakeColor(200.f, 200.f, 200.f)
					);
				}
			}
		}
		else
		{
			for (int i = SolidStart; i != SolidEnd; ++i)
			{
				if ((FluidType)i != FluidStart || (FluidType)i != FluidEnd)
				{
					RENDER.Text("FType" + std::to_string(i) + " : " + std::to_string(info.mapFluid[(FluidType)i]),
						"±¼¸²10",
						MakeRect(renderMat.GetPosition().x + 150, renderMat.GetPosition().y + - 150 + i * 10, 500, 10),
						MakeColor(200.f, 200.f, 200.f)
					);
				}
			}
		}
	}
}

void TileNode::ProcessDestroy()
{
	//¹Ù´Ú¿¡ ÅÛ±ò¸®´Â°Å.
}


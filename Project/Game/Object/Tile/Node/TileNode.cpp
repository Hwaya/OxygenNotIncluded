#include "stdafx.h"
#include "TileNode.h"
#include "./System/Message/MessageData.h"

class MessageData;

TileNode::TileNode(std::string name, D2D1_POINT_2F pos, D2D1_POINT_2F size, float rotation )
	:Object(name,pos,size,rotation)
{
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
}

void TileNode::ProcessDestroy()
{
	//¹Ù´Ú¿¡ ÅÛ±ò¸®´Â°Å.
}


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
	Object::Render();

	if (info.isSolid)
	{
		switch (info.solidType)
		{
		case SolidDirt:
			IMAGE.Find("Solid_Dirt")->Render(
				transform->GetPosition().x, transform->GetPosition().y,
				transform->GetScale().x, transform->GetScale().y);
			break;
		case SolidRock:
			IMAGE.Find("Solid_Rock")->Render(
				transform->GetPosition().x, transform->GetPosition().y,
				transform->GetScale().x, transform->GetScale().y);
			break;
		case SolidMetal:
			IMAGE.Find("Solid_Metal")->Render(
				transform->GetPosition().x, transform->GetPosition().y,
				transform->GetScale().x, transform->GetScale().y);
			break;
		case SolidStructure:
			break;
		}
	}
	else
	{

	}
}

void TileNode::ProcessDestroy()
{
	//¹Ù´Ú¿¡ ÅÛ±ò¸®´Â°Å.
}


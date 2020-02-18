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
		Matrix renderMat = *transform * CAMERA.GetInvertView();
		/*
		IMAGE.Find(tempKey)->Render(
			transform->GetPosition().x, 
			transform->GetPosition().y,
			transform->GetScale().x, 
			transform->GetScale().y);
			*/
			
		Matrix temp = CAMERA.GetView();
			renderMat.GetPosition().x;
			renderMat.GetPosition().y;
			transform->GetScale().x;
			transform->GetScale().y;

		IMAGE.Find(tempKey)->Render(
			renderMat.GetPosition().x,
			renderMat.GetPosition().y,
			transform->GetScale().x,
			transform->GetScale().y);
	}
	else
	{

	}
}

void TileNode::ProcessDestroy()
{
	//¹Ù´Ú¿¡ ÅÛ±ò¸®´Â°Å.
}


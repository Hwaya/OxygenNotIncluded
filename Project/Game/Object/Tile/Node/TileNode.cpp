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
	AddCallBack("SetData", [&](MessageData msg) {
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
}

void TileNode::Release()
{
}

void TileNode::Update()
{
}

void TileNode::Render()
{
}

void TileNode::ProcessExtract()
{
}

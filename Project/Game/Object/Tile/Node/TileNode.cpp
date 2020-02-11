#include "stdafx.h"
#include "TileNode.h"


TileNode::TileNode(std::string name, D2D1_POINT_2F pos, D2D1_POINT_2F size, float rotation )
	:Object(name,pos,size,rotation)
{
}

TileNode::~TileNode()
{
}

void TileNode::Initialize()
{
	/*AddCallBack("Extract", [&]() {
		ProcessExtract();
	});*/
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

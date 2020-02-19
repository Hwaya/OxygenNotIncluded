#include "stdafx.h"
#include "Clone.h"


Clone::Clone(std::string name, D2DPOINTF pos, D2DPOINTF size, float rotation)
	:Object(name,pos,size,rotation)
{
}

Clone::~Clone()
{
}

void Clone::Initialize()
{
	state = new StateManager(static_cast<Object*>(this));
}

void Clone::Release()
{
}

void Clone::Update()
{
}

void Clone::Render()
{

	Object::Render();
}

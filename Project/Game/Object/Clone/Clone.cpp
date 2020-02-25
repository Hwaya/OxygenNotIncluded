#include "stdafx.h"
#include "Clone.h"


Clone::Clone(std::string name, D2DPOINTF pos, D2DPOINTF size, bool ui = false, float rotation = 0.f)
	:Object(name,pos,size,ui, rotation)
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

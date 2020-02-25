#include "stdafx.h"
#include "UIBase.h"

UIBase::UIBase(std::string inputName, D2DPOINTF pos, D2DPOINTF size, bool ui = false, float rotation = 0.f)
	:Object(inputName, pos, size, ui, rotation)
{
}

UIBase::~UIBase()
{
}

void UIBase::Initialize()
{
}

void UIBase::Release()
{
}

void UIBase::Update()
{
}

void UIBase::Render()
{
}

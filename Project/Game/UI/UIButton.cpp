#include "stdafx.h"
#include "UIButton.h"
#include "Game/Message/Base/MessageData.h"

UIButton::UIButton(std::string inputName, D2DPOINTF pos, D2DPOINTF size, bool ui = false, float rotation = 0.f)
	:UIBase(inputName, pos, size, ui, rotation)
{
}

UIButton::~UIButton()
{
}

void UIButton::Initialize()
{
	imgKey = "";
}

void UIButton::Release()
{
}

void UIButton::Update()
{
	if (PointInRect(MOUSE.GetPosition().x, MOUSE.GetPosition().y, rect))
	{
		isMouseOn = true;
	}
	else
	{
		isMouseOn = false;
	}
}

void UIButton::Render()
{
	Object::Render();
	IMAGE.Find("ButtonBase")->Render(
		transform->GetPosition().x,
		transform->GetPosition().y,
		transform->GetScale().x,
		transform->GetScale().y,
		1.0f,
		M_PI / 4.f);

	if (imgKey != "")
	{
		IMAGE.Find(imgKey)->Render(
			transform->GetPosition().x,
			transform->GetPosition().y,
			transform->GetScale().x / 2.f,
			transform->GetScale().y / 2.f
		);
	}
	else
	{
		IMAGE.Find(name)->Render(
			transform->GetPosition().x,
			transform->GetPosition().y,
			transform->GetScale().x / 2.f,
			transform->GetScale().y / 2.f
		);
	}
	transform;
	int a = 0;
	int c = name.length();
	int b = 0;
	std::string substr;
	if (name.substr(6, 6) == "Struct")
	{
		substr = name.substr(12, name.length());
	}
	else
	{
		substr = name.substr(6, name.length());
	}
	RENDER.TextWithInstanceFont(substr, "±¼¸²", 9,
		MakeRect(transform->GetPosition().x + substr.length() * 9 / 2.f
			- substr.length() * 9 / 4.f,
			transform->GetPosition().y + 30, substr.length() * 9, 10),
		MakeColor(1, 1, 1));
}

void UIButton::SetIcon(std::string key)
{
	imgKey = key;
}

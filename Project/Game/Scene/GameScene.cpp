#include "stdafx.h"
#include "GameScene.h"

GameScene::GameScene()
	:currentPickMode(PickNone)
{
}

GameScene::~GameScene()
{
}

void GameScene::Initialize()
{
	SceneBase::Initialize();

	ImageLoad();

	/* Tile Initialize */
	TILE->SetMapInfo({ 30,30 }, D2DPOINTF(100.f, 100.f), D2DPOINTF(0.f, 0.f));
	TILE->CreateMap();
	
	for (int i = 0; i < TILE->GetMapSize().y; ++i)
	{
		for (int j = 0; j < TILE->GetMapSize().x; ++j)
		{
			TILE->Tile(j, i)->SetIsSolid(true);
			TILE->Tile(j, i)->SetSolid(SolidRock);
		}
	}
	for (int i = 3; i < 5; ++i)
	{
		for (int j = 3; j < 10; ++j)
		{
			TILE->Tile(j, i)->SetIsSolid(false);
			TILE->Tile(j, i)->SetSolid(SolidNone);
		}
	}

	/* TestClone */
	OBJECT->NewObject<Clone>(
		"TestClone",
		IndexToPos(5, 5, TILE->GetTileSize(), TILE->GetPivotPos()), D2DPOINTF(50.f, 50.f));

	/* TestButton */
	/* function Button */
	Object* digButton = OBJECT->NewObject<UIButton>("ButtonDig",D2DPOINTF(WINSIZEX - 200.f,WINSIZEY - 100.f), D2DPOINTF(30.f, 30.f));
	digButton->SetUI(true);
	digButton->AddCallBack("Click", [&](MessageData msg = *(new MessageData)) {
		DATA->SetPickMode(PickDig);
	});

	Object* cancelButton = OBJECT->NewObject<UIButton>("ButtonCancel",	D2DPOINTF(WINSIZEX - 150.f, WINSIZEY - 100.f), D2DPOINTF(30.f, 30.f));
	cancelButton->SetUI(true);
	digButton->AddCallBack("Click", [&](MessageData msg = *(new MessageData)) {
		DATA->SetPickMode(PickCancel);
	});

	Object* deconstructButton = OBJECT->NewObject<UIButton>("ButtonDeconstruct", D2DPOINTF(WINSIZEX - 100.f, WINSIZEY - 100.f), D2DPOINTF(30.f, 30.f));
	deconstructButton->SetUI(true);
	digButton->AddCallBack("Click", [&](MessageData msg = *(new MessageData)) {
		DATA->SetPickMode(PickDeconstruct);
	});
	
	/* struct buttonr */
	Object* structBaseButton = OBJECT->NewObject<UIButton>("ButtonStructBase", D2DPOINTF(50.f, WINSIZEY - 100.f), D2DPOINTF(30.f, 30.f));
	structBaseButton->SetUI(true);

	Object* structElectricButton = OBJECT->NewObject<UIButton>("ButtonStructElectric", D2DPOINTF(100.f, WINSIZEY - 100.f), D2DPOINTF(30.f, 30.f));
	structElectricButton->SetUI(true);

	Object* structFoodButton = OBJECT->NewObject<UIButton>("ButtonStructFood", D2DPOINTF(150.f, WINSIZEY - 100.f), D2DPOINTF(30.f, 30.f));
	structFoodButton->SetUI(true);

	Object* structOxygenButton = OBJECT->NewObject<UIButton>("ButtonStructOxygen", D2DPOINTF(200.f, WINSIZEY - 100.f), D2DPOINTF(30.f, 30.f));
	structOxygenButton->SetUI(true);

	Object* structPipeButton = OBJECT->NewObject<UIButton>("ButtonStructPipe", D2DPOINTF(250.f, WINSIZEY - 100.f), D2DPOINTF(30.f, 30.f));
	structPipeButton->SetUI(true);

	newInput = false;
}

void GameScene::Release()
{
	SceneBase::Release();
}

void GameScene::Update()
{
	OBJECT->Update();

	/*if (KEYBOARD.Down(MK_LBUTTON))
	{
		if (!MOUSE.IsOnUI())
		{
			if (currentPickMode != PickBegin && currentPickMode != PickNone && currentPickMode != PickEnd)
			{
				POINT mouseIndex = PosToIndex(MOUSE.GetPosition(), TILE->GetTileSize(), TILE->GetPivotPos());
				if (TILE->Tile(mouseIndex.x, mouseIndex.y)->IsSolid())
				{
					
				}
			}
		}
	}*/

	if (KEYBOARD.Stay(MK_LBUTTON))
	{
		if (!newInput)
		{
			newInput = true;
			oldPoint = MOUSE.GetPosition();
		}
		float minX, maxX, minY, maxY;
		if (oldPoint.x < MOUSE.GetPosition().x)
		{
			minX = oldPoint.x;
			maxX = MOUSE.GetPosition().x;
		}
		else
		{
			minX = MOUSE.GetPosition().x;
			maxX = oldPoint.x;
		}
		if (oldPoint.y < MOUSE.GetPosition().y)
		{
			minY = oldPoint.y;
			maxY = MOUSE.GetPosition().y;
		}
		else
		{
			minY = MOUSE.GetPosition().y;
			maxY = oldPoint.y;
		}
		
		POINT tempLT = PosToIndex(D2DPOINTF(minX, minY), TILE->GetTileSize(), TILE->GetPivotPos());
		POINT tempRB = PosToIndex(D2DPOINTF(maxX, maxY), TILE->GetTileSize(), TILE->GetPivotPos());

		Matrix renderMat = RENDER.RenderSet(*TILE->Tile(tempLT.x, tempLT.y)->GetTransform(), true, true);
		D2DRECTF tempLTRC = MakeRect(
			renderMat.GetPosition().x,
			renderMat.GetPosition().y,
			renderMat.GetScale().x,
			renderMat.GetScale().y
		);
		renderMat = RENDER.RenderSet(*TILE->Tile(tempRB.x, tempRB.y)->GetTransform(), true, true);
		D2DRECTF tempRBRC = MakeRect(
			renderMat.GetPosition().x,
			renderMat.GetPosition().y,
			renderMat.GetScale().x,
			renderMat.GetScale().y
		);

		selectRect = MakeRectWithPoint(
			tempLTRC.left,
			tempLTRC.top,
			tempRBRC.right,
			tempRBRC.bottom
		);
	}

	if (KEYBOARD.Up(MK_LBUTTON))
	{
		newInput = false;
		oldPoint = { 0.f,0.f };
		selectRect = MakeRectWithPoint(0.f,0.f,0.f,0.f);
	}

	/* is Mouse on UI? */
	std::vector<Object*> temp = OBJECT->GetArray("UIButton");
	std::vector<Object*>::iterator vecIter = temp.begin(), vecEnd = temp.end();
	int counter = 0;
	for (; vecIter != vecEnd; ++vecIter)
	{
		if (static_cast<UIBase*>(*vecIter)->GetMouseOn())
		{
			counter++;
		}
	}
	if (counter > 0)
	{
		MOUSE.SetIsOnUI(true);
	}
}

void GameScene::Render()
{
	SceneBase::Render();

	IMAGE.Find("Background")->Render(WINSIZEX / 2.f, WINSIZEY / 2.f, 3000, 3000);

	OBJECT->Render();

	if (selectRect.right - selectRect.left > 0.f && selectRect.bottom - selectRect.top > 0.f)
	{
		RENDER.DrawRectangle(selectRect, MakeColor(0.5f, 0.8f, 0.1f), 2.f);
	}
}

void GameScene::ImageLoad()
{
	IMAGE.Add("Background", _ResourcePath + "BackGround/BGfrozen.png");

	IMAGE.Add("Solid_Dirt", _ResourcePath + _TilePath + _SolidPath + "Dirt.png");
	IMAGE.Add("Solid_Metal", _ResourcePath + _TilePath + _SolidPath + "Metal.png");
	IMAGE.Add("Solid_Rock", _ResourcePath + _TilePath + _SolidPath + "Rock.png");


	/* UI */
	//Button
	IMAGE.Add("ButtonBase", _ResourcePath + "UI/Button/ButtonBase.png");
	IMAGE.Add("ButtonBaseSelected", _ResourcePath + "UI/Button/ButtonBaseSelected.png");
	IMAGE.Add("ButtonCancel", _ResourcePath + "UI/button/ButtonCancel.png");
	IMAGE.Add("ButtonDig", _ResourcePath + "UI/button/ButtonDig.png");
	IMAGE.Add("ButtonDeconstruct", _ResourcePath + "UI/button/ButtonDeconstruct.png");
	//ButtonStruct
	IMAGE.Add("ButtonStructBase", _ResourcePath + "UI/button/ButtonStructBase.png");
	IMAGE.Add("ButtonStructElectric", _ResourcePath + "UI/button/ButtonStructElectric.png");
	IMAGE.Add("ButtonStructFood", _ResourcePath + "UI/button/ButtonStructFood.png");
	IMAGE.Add("ButtonStructOxygen", _ResourcePath + "UI/button/ButtonStructOxygen.png");
	IMAGE.Add("ButtonStructPipe", _ResourcePath + "UI/button/ButtonStructPipe.png");
	//TileIcon
	IMAGE.Add("TileIconChoose", _ResourcePath + "UI/Tile/Choose.png");
	IMAGE.Add("TileIconCancel", _ResourcePath + "UI/Tile/Cancel.png");
	IMAGE.Add("TileIconDig", _ResourcePath + "UI/Tile/Dig.png");
	IMAGE.Add("TileIconCleanUp", _ResourcePath + "UI/Tile/Cleanup.png");
}
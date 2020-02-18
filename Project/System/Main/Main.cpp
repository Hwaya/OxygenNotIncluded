#include "stdafx.h"
#include "Main.h"
#include "./Game/Object/Base/Object.h"
#include "./Game/Scene/Base/SceneBase.h"
#include "./Game/Scene/GameScene.h"

Main::Main()
{

}

Main::~Main()
{
}

HRESULT Main::Initialize()
{
	SCENEMANAGER.AddScene("TestScene", new SceneBase());
	SCENEMANAGER.AddScene("GameScene", new GameScene());
	SCENEMANAGER.SwapScene("GameScene");
	debugMode = false;
	IMAGE.Add("Test", _ResourcePath + "Test/FrameTest.png", 16, 1);
	return S_OK;
}

void Main::Release()
{
	SCENE->Release();
}

void Main::Update()
{
	SCENE->Update();
}

void Main::Render()
{
	SCENE->Render();

	if (KEYBOARD.Down(VK_F1))
	{
		debugMode = !debugMode;
		RENDER.DebugMode(debugMode);
	}
	if (KEYBOARD.Down(VK_ESCAPE))
	{
		PostQuitMessage(0);
	}

	if (RENDER.IsDebugMode())
	{
		D2DPOINTF cameraLoca = CAMERA.GetView().GetPosition();
		D2DPOINTF mouseLoca = D2DPOINTF(MOUSE.GetPosition().x, MOUSE.GetPosition().y);
		
		RENDER.Text(
			"Debug Mode",
			"굴림",
			MakeRect(250, 50, 500, 100),
			MakeColor(200.f, 100.f, 100.f),
			0.f
		);


		//Mouse Location
		RENDER.Text(
			std::to_string(mouseLoca.x) + "," + std::to_string(mouseLoca.y),
			"굴림",
			MakeRect(mouseLoca.x, mouseLoca.y + 30, 500, 100),
			MakeColor(200, 100, 100),
			0.f
		);
		//Camera Location
		RENDER.Text(
			std::to_string(cameraLoca.x) + "," + std::to_string(cameraLoca.y),
			"굴림",
			MakeRect(mouseLoca.x, mouseLoca.y + 80, 500, 100),
			MakeColor(100, 200, 100)
		);
		//Wheel Value
		RENDER.Text(
			std::to_string(MOUSE.GetWheelValue()), 
			"굴림", 
			MakeRect(mouseLoca.x, mouseLoca.y + 100, 500, 100),
			MakeColor(100, 100, 100), 0.f);
	}



	/*Geometry Test*/
	// 선분 조각들로 구성된 경로 기하를 생성.
	ID2D1PathGeometry* mp_path_geometry = NULL;
	RENDER.GetFactory()->CreatePathGeometry(&mp_path_geometry);

	// 경로 기하에 조각들을 기록하기 위해서 기하 싱크를 얻음.
	ID2D1GeometrySink* mp_sink = NULL;
	mp_path_geometry->Open(&mp_sink);

	// 피겨의 시작.(피겨의 시작점, 채우기 or 비우기)
	mp_sink->BeginFigure(D2D1::Point2F(0, 0), D2D1_FIGURE_BEGIN_FILLED);
	// 조각 추가.
	D2D1_POINT_2F points[3] = { D2D1::Point2F(100, 0), D2D1::Point2F(200, 100), D2D1::Point2F(100, 100) };
	mp_sink->AddLines(points, 3);
	// 피겨의 끝.
	mp_sink->EndFigure(D2D1_FIGURE_END_CLOSED);
	mp_sink->Close();

	// 렌더타겟에 경로 기하 그리기.
	ID2D1SolidColorBrush* newBrush;
	RENDER.GetRenderTarget()->CreateSolidColorBrush(D2D1::ColorF(250.f, 10.f, 10.f), &newBrush);
	RENDER.GetRenderTarget()->SetTransform(D2D1::Matrix3x2F::Translation(10, 10));
	RENDER.GetRenderTarget()->DrawGeometry(mp_path_geometry, newBrush, 2.f, 0);

	ID2D1BitmapBrush* abc;

	fx++;
	if (fx > 15) fx = 0;

	IMAGE.Find("Test")->Render(100, 100, 100, 100, 1.f, 0.f, fx, 0);
	ID2D1Bitmap* bbb = IMAGE.Find("Test")->GetBitmap();
	bbb->CopyFromRenderTarget(&D2D1::Point2U(100.f, 100.f), RENDER.GetRenderTarget(), &D2D1::RectU(100, 100, 100, 100));

	RENDER.GetRenderTarget()->CreateBitmapBrush(bbb, &abc);

	RENDER.GetRenderTarget()->FillGeometry(mp_path_geometry, abc);
}

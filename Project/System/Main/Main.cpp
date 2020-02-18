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
			"����",
			MakeRect(250, 50, 500, 100),
			MakeColor(200.f, 100.f, 100.f),
			0.f
		);


		//Mouse Location
		RENDER.Text(
			std::to_string(mouseLoca.x) + "," + std::to_string(mouseLoca.y),
			"����",
			MakeRect(mouseLoca.x, mouseLoca.y + 30, 500, 100),
			MakeColor(200, 100, 100),
			0.f
		);
		//Camera Location
		RENDER.Text(
			std::to_string(cameraLoca.x) + "," + std::to_string(cameraLoca.y),
			"����",
			MakeRect(mouseLoca.x, mouseLoca.y + 80, 500, 100),
			MakeColor(100, 200, 100)
		);
		//Wheel Value
		RENDER.Text(
			std::to_string(MOUSE.GetWheelValue()), 
			"����", 
			MakeRect(mouseLoca.x, mouseLoca.y + 100, 500, 100),
			MakeColor(100, 100, 100), 0.f);
	}



	/*Geometry Test*/
	// ���� ������� ������ ��� ���ϸ� ����.
	ID2D1PathGeometry* mp_path_geometry = NULL;
	RENDER.GetFactory()->CreatePathGeometry(&mp_path_geometry);

	// ��� ���Ͽ� �������� ����ϱ� ���ؼ� ���� ��ũ�� ����.
	ID2D1GeometrySink* mp_sink = NULL;
	mp_path_geometry->Open(&mp_sink);

	// �ǰ��� ����.(�ǰ��� ������, ä��� or ����)
	mp_sink->BeginFigure(D2D1::Point2F(0, 0), D2D1_FIGURE_BEGIN_FILLED);
	// ���� �߰�.
	D2D1_POINT_2F points[3] = { D2D1::Point2F(100, 0), D2D1::Point2F(200, 100), D2D1::Point2F(100, 100) };
	mp_sink->AddLines(points, 3);
	// �ǰ��� ��.
	mp_sink->EndFigure(D2D1_FIGURE_END_CLOSED);
	mp_sink->Close();

	// ����Ÿ�ٿ� ��� ���� �׸���.
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

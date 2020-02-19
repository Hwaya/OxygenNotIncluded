#pragma once
#include "stdafx.h"

/* Window Setting */
extern HWND _hWnd;
extern HINSTANCE _hInstance;
#define WINNAME L"Oxygen Not Included"
#define WINSIZEX 1024
#define WINSIZEY 768
#define WINPOSX 100
#define WINPOSY 100

/* Resource */
static const std::string _ResourcePath = "../_Resource/";
static const std::string _TilePath = "Tile/";
static const std::string _SolidPath = "Solid/";

/* D2D */
#define D2DPOINT(num1, num2)  D2D1::Point2U((num1), (num2))
#define D2DPOINTF(num1, num2)  D2D1::Point2F((num1), (num2))
#define D2DCOLORF(r, g, b) D2D1::ColorF((r),(g),(b))

typedef D2D1_POINT_2U D2DPOINTU;
typedef D2D1_POINT_2F D2DPOINTF;
typedef D2D1_RECT_F D2DRECTF;
typedef D2D1_ELLIPSE D2DELLIPSE;
typedef D2D1_COLOR_F D2DCOLOR;

/* Camera */
static const D2DPOINTF _maxCamera = { -1000.f, - 1000.f};
static const float _maxZoom = 150.f;
static const float _zoomSpeed = 10.f;

/* Tile */
static const POINT defaultMapSize = { 10, 10 };
static const D2D1_POINT_2F defaultTileSize = { 50.f, 50.f };


/* Not Using */
static const int _DefaultPoolSize = 100;

/* Default Clone Status */
static const float _o2Rate = 10.f;
static const float _co2Rate = 10.f;
static const int _peeRate = 1;
static const float _structSpeed = 5.f;
static const float _miningSpeed = 5.f;
static const float _speed = 5.f;
static const int _stateSlot = 5;
enum StateKind
{
	StateBegin = 0,
	StateActivity,
	StatePositive,
	StateNegative,
	StateBuff1,
	StateBuff2,
	StateBuff3,
	StateBuff4,
	StateBuff5,
	StateEnd
};
enum Activity
{
	ActivityBegin = 0,
	ActivityIdle,
	ActivityMove,
	ActivityStruct,
	ActivitySleep,
	ActivityPee,
	ActivityEat,
	ActivityEnd
};
enum Positive
{
	PositiveBegin = 0,
	PositiveNone,
	PositiveO2,
	PositiveMining,
	PositiveSpeed,
	PositiveEnd
};
enum Negative
{
	NegativeBegin = 0,
	NegativeNone,
	NegativeO2,
	NegativePee,
	NegativeSpeed,
	NegativeEnd
};
enum Buff
{
	BuffBegin = 0,
	BuffNone,
	BuffDirty,
	BuffCold,
	BuffHot,
	BuffSick,
	BuffEnd
};



//  direct2d geometry 테스트 하던 것
//	/*Geometry Test*/
//	// 선분 조각들로 구성된 경로 기하를 생성.
//	ID2D1PathGeometry* mp_path_geometry = NULL;
//	RENDER.GetFactory()->CreatePathGeometry(&mp_path_geometry);
//
//	// 경로 기하에 조각들을 기록하기 위해서 기하 싱크를 얻음.
//	ID2D1GeometrySink* mp_sink = NULL;
//	mp_path_geometry->Open(&mp_sink);
//
//	// 피겨의 시작.(피겨의 시작점, 채우기 or 비우기)
//	mp_sink->BeginFigure(D2D1::Point2F(0, 0), D2D1_FIGURE_BEGIN_FILLED);
//	// 조각 추가.
//	D2D1_POINT_2F points[3] = { D2D1::Point2F(100, 0), D2D1::Point2F(200, 100), D2D1::Point2F(100, 100) };
//	mp_sink->AddLines(points, 3);
//	// 피겨의 끝.
//	mp_sink->EndFigure(D2D1_FIGURE_END_CLOSED);
//	mp_sink->Close();
//
//	// 렌더타겟에 경로 기하 그리기.
//	ID2D1SolidColorBrush* newBrush;
//	RENDER.GetRenderTarget()->CreateSolidColorBrush(D2D1::ColorF(250.f, 10.f, 10.f), &newBrush);
//	RENDER.GetRenderTarget()->SetTransform(D2D1::Matrix3x2F::Translation(10, 10));
//	RENDER.GetRenderTarget()->DrawGeometry(mp_path_geometry, newBrush, 2.f, 0);
//
//	ID2D1BitmapBrush* abc;
//
//	fx++;
//	if (fx > 15) fx = 0;
//
//	IMAGE.Find("Test")->Render(100, 100, 100, 100, 1.f, 0.f, fx, 0);
//	ID2D1Bitmap* bbb = IMAGE.Find("Solid_Metal")->GetBitmap();
//	bbb->CopyFromRenderTarget(&D2D1::Point2U(100.f, 100.f), RENDER.GetRenderTarget(), &D2D1::RectU(100, 100, 100, 100));
//	bbb->CopyFromBitmap(&D2D1::Point2U(50.f, 100.f), IMAGE.Find("Test")->GetBitmap(), &D2D1::RectU(0, 0, 10, 10));
//
//	RENDER.GetRenderTarget()->CreateBitmap(D2D1::SizeU(100,100),
//
//
//	RENDER.GetRenderTarget()->CreateBitmapBrush(bbb, &abc);
//
//	RENDER.GetRenderTarget()->FillGeometry(mp_path_geometry, abc);
//
//	
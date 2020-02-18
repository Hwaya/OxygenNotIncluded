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
static const float _zoomSpeed = 3.f;

/* Not Using */
static const int _DefaultPoolSize = 100;
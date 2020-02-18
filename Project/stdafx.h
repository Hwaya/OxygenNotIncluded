#pragma once

/* Default Headers */
#include <windows.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

/* STL */
#include <vector>
#include <unordered_map>
#define _USE_MATH_DEFINES
#include <math.h>
#include <string>
#include <assert.h> 
#include <functional>
//USES_CONVERSION
#include <comdef.h>
#include <CRTDBG.H>
#include <atlconv.h>

/* D2D Library, Headers */
#pragma comment(lib, "d2d1.lib")
#pragma comment(lib, "WindowsCodecs.lib")
#pragma comment(lib, "dwrite.lib")
#include <wincodec.h>
#include <d2d1.h>
#include <d2d1helper.h>
#include <dwrite.h>

/* Window Setting */
extern HWND _hWnd;
extern HINSTANCE _hInstance;
#define WINNAME L"Oxygen Not Included"
#define WINSIZEX 1024
#define WINSIZEY 768
#define WINPOSX 100
#define WINPOSY 100

/* Macros */
template <typename T>
inline void SafeRelease(T* &p)
{
	if (NULL != p)
	{
		p->Release();
		p = NULL;
	}
}

template <typename T>
inline void SafeDelete(T* &p)
{
	if (NULL != p)
	{
		delete(p);
		p = NULL;
	}
}

template <typename T>
inline void SafeDeleteArray(T* &p)
{
	if (NULL != p)
	{
		delete[](p);
		p = NULL;
	}
}

inline std::wstring StringToWstring(const std::string& input)
{
	USES_CONVERSION;
	return std::wstring(A2W(input.c_str()));
};

inline std::string WstringToString(const std::wstring& input)
{
	USES_CONVERSION;
	return std::string(W2A(input.c_str()));
};

/* Singleton Macro */
#define LOCK_COPY(ClassName)				\
private:									\
	ClassName(const ClassName&);			\
	ClassName& operator=(const ClassName&);	

#define SINGLETONHEADER(ClassName)			\
	LOCK_COPY(ClassName)					\
	private:								\
		ClassName() {}						\
		static ClassName* instance;			\
	public:									\
		static ClassName& Get();			\
		static void Create();				\
		static void Delete();

#define SINGLETONCPP(ClassName)				\
ClassName* ClassName::instance = 0;			\
ClassName& ClassName::Get()					\
{											\
	if (instance != 0)						\
	{										\
		return *instance;					\
	}										\
}											\
void ClassName::Create()					\
{											\
	if (instance == 0)						\
	{										\
		instance = new ClassName();			\
	}										\
}											\
void ClassName::Delete()					\
{											\
	if (instance != 0)						\
	{										\
		SafeDelete(instance);				\
	}										\
}



/* Define */
static const std::string _ResourcePath = "../_Resource/";
static const std::string _TilePath = "Tile/";
static const std::string _SolidPath = "Solid/";

typedef D2D1_POINT_2U D2DPOINTU;
typedef D2D1_POINT_2F D2DPOINTF;
typedef D2D1_RECT_F D2DRECTF;
typedef D2D1_ELLIPSE D2DELLIPSE;
typedef D2D1_COLOR_F D2DCOLOR;

inline D2DCOLOR MakeColor(float r, float g, float b)
{
	return D2D1::ColorF(r, g, b);
}
inline D2D1_RECT_F MakeRect(float x, float y, float width, float height)
{
	return D2D1::RectF(x - width / 2.f, y - height / 2.f, x + width / 2.f, y + height / 2.f);
}

#define D2DPOINT(num1, num2)  D2D1::Point2U((num1), (num2))
#define D2DPOINTF(num1, num2)  D2D1::Point2F((num1), (num2))
#define D2DCOLORF(r, g, b) D2D1::ColorF((r),(g),(b))

static const int _DefaultPoolSize = 100;

/* Class Header */
#include "./Game/Object/Base/Object.h"
#include "System/D2D/Matrix.h"

/* Singleton Headers */
#include "./Game/Camera/Camera.h"
#include "./System/Device/Keyboard.h"
#include "./System/Device/Mouse.h"
#include "./System/D2D/Renderer.h"
#include "./System/Image/ImageManager.h"
#include "./Game/Scene/SceneManager.h"
#include "./Game/Object/ObjectManager.h"
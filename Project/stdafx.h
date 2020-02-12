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

/* D2D Library, Headers */
#pragma comment(lib, "d2d1.lib")
#pragma comment(lib, "WindowsCodecs.lib")
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
#define RESOURCEPATH "../_Resource/"

typedef D2D1_POINT_2U D2DPOINTU;
typedef D2D1_POINT_2F D2DPOINTF;
typedef D2D1_RECT_F D2DRECTF;

static const int _DefaultPoolSize = 100;


/* Singleton Headers */
#include "./System/D2D/Renderer.h"
#include "./System/Image/ImageManager.h"
#include "./Game/Scene/SceneManager.h"
#include "./Game/Object/ObjectManager.h"

/* Root Class Header */
#include "./Game/Object/Base/Object.h"
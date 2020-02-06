#pragma once

/* Headers */
#include <windows.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <string>
#include <assert.h>

/* STL */
#include <vector>
#include <unordered_map>

/* D2D Library, Headers */
#pragma comment(lib, "d2d1.lib")
#pragma comment(lib, "WindowsCodecs.lib")

#include <wincodec.h>
#include <d2d1.h>
#include <d2d1helper.h>



/* Window Setting */
extern HWND _hWnd;
extern HINSTANCE _hInstance;

#define WINSIZEX 1024
#define WINSIZEY 768
#define WINPOSX 100
#define WINPOSY 100

/* Macro & Public Function */
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
	
/* Singleton Headers */
#include "./System/D2D/Renderer.h"
#include "./System/Manager/ImageManager.h"
#pragma once

/* Windows API Headers */
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

/* Define Header */
#include "./System/Defines.h"

/* Function Header */
#include "./System/UtilityFunction.h"
#include "./System/D2D/D2DFunction.h"

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

/* General Header */
#include "./Game/Scene/Base/SceneBase.h"
#include "./Game/Object/ObjectManager.h"
#include "./Game/Object/Tile/TileManager.h"
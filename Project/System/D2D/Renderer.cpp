#include "stdafx.h"
#include "Renderer.h"


SINGLETONCPP(Renderer)

void Renderer::Initialize()
{
	InitializeD2D();
	CreateRenderTarget();
	isDebugMode = false;
}

void Renderer::BeginDraw()
{
	D2DRenderTarget->BeginDraw();
	D2DRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::Black));
	D2DRenderTarget->SetTransform(D2D1::IdentityMatrix());
}

void Renderer::EndDraw()
{
	D2DRenderTarget->EndDraw();
}

void Renderer::DrawLine(float x, float y, float dx, float dy, D2D1_COLOR_F color)
{
	HRESULT hr = E_FAIL;
	D2D_POINT_2F beginPoint = D2D1::Point2F(x, y);
	D2D_POINT_2F endPoint = D2D1::Point2F(dx, dy);

	D2DRenderTarget->CreateSolidColorBrush(color, &brush);
	D2DRenderTarget->DrawLine(beginPoint, endPoint, brush);
	SafeRelease(brush);
}

void Renderer:: DrawRectangle(D2D1_RECT_F rect, D2D1_COLOR_F color, float thikness, float radian)
{
	float tempDegree = radian * 180 / (float)M_PI;
	D2D1::Matrix3x2F tempRotateMatrix = D2D1::Matrix3x2F::Rotation(tempDegree, D2D1::Point2F(
		(rect.right + rect.left) / 2.f, (rect.top + rect.bottom) / 2.f));

	D2DRenderTarget->SetTransform(tempRotateMatrix);
	D2DRenderTarget->CreateSolidColorBrush(color, &brush);
	D2DRenderTarget->DrawRectangle(rect, brush, thikness);
	D2DRenderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
	SafeRelease(brush);
}

D2DRECTF& Renderer::DrawRectangle(float x, float y, float sizeX, float sizeY, D2D1_COLOR_F color, float thikness, float radian)
{
	float tempDegree = radian * 180 / (float)M_PI;
	D2D1::Matrix3x2F tempRotateMatrix = D2D1::Matrix3x2F::Rotation(tempDegree, D2D1::Point2F(x, y));

	D2DRECTF tempRc = D2D1::RectF(x - sizeX * 0.5f, y - sizeY * 0.5f, x + sizeX * 0.5f, y + sizeY * 0.5f);

	D2DRenderTarget->SetTransform(tempRotateMatrix);
	D2DRenderTarget->CreateSolidColorBrush(color, &brush);
	D2DRenderTarget->DrawRectangle(tempRc, brush, thikness);
	D2DRenderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
	SafeRelease(brush);

	return tempRc;
}

void Renderer::FillRectangle(D2DRECTF& rc, D2D1_COLOR_F color)
{
	D2DRenderTarget->CreateSolidColorBrush(color, &brush);
	D2DRenderTarget->FillRectangle(rc, brush);
	SafeRelease(brush);
}

void Renderer::DrawEllipse(D2D1_RECT_F rect, D2D1_COLOR_F color, float thikness, float radian)
{
	float tempDegree = radian * 180 / (float)M_PI;
	D2D1::Matrix3x2F tempRotateMatrix = D2D1::Matrix3x2F::Rotation(tempDegree, D2D1::Point2F(
		(rect.right + rect.left) / 2.f, (rect.top + rect.bottom) / 2.f));

	D2DRenderTarget->SetTransform(tempRotateMatrix);
	D2DRenderTarget->CreateSolidColorBrush(color, &brush);
	D2DRenderTarget->DrawEllipse(D2D1::Ellipse(D2D1::Point2F((rect.right + rect.left) / 2.f,(rect.bottom + rect.top)/2.f),
		(rect.right - rect.left) / 2.f, (rect.bottom - rect.top) / 2.f), brush, thikness);
	D2DRenderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
	SafeRelease(brush);
}

D2DELLIPSE& Renderer::DrawEllipse(float x, float y, float sizeX, float sizeY, D2D1_COLOR_F color, float thikness, float radian)
{
	float tempDegree = radian * 180 / (float)M_PI;
	D2D1::Matrix3x2F tempRotateMatrix = D2D1::Matrix3x2F::Rotation(tempDegree, D2D1::Point2F(x, y));

	D2DELLIPSE tempEllipse = D2D1::Ellipse(D2DPOINTF(x, y), x - sizeX / 2.f, y - sizeY / 2.f);

	D2DRenderTarget->SetTransform(tempRotateMatrix);
	D2DRenderTarget->CreateSolidColorBrush(color, &brush);
	D2DRenderTarget->DrawEllipse(tempEllipse,brush,thikness);
	D2DRenderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
	SafeRelease(brush);

	return tempEllipse;
}

void Renderer::FillEllipse(D2DELLIPSE & ellipse, D2D1_COLOR_F color)
{
	D2DRenderTarget->CreateSolidColorBrush(color, &brush);
	D2DRenderTarget->FillEllipse(ellipse, brush);
	SafeRelease(brush);
}

IDWriteTextFormat * Renderer::AddFont(std::string name, float size)
{
	assert(fonts.find(name) == fonts.end());

	std::wstring temp = StringToWstring(name);
	const wchar_t* tempName = temp.c_str();

	D2DWriteFactory->CreateTextFormat(
		tempName,						// 폰트 이름
		0,								// 폰트 컬렉션 (0)
		DWRITE_FONT_WEIGHT_REGULAR,		// 폰트 굵기
		DWRITE_FONT_STYLE_NORMAL,		// 폰트 스타일 (Normal, Italic, Obique)
		DWRITE_FONT_STRETCH_NORMAL,		// 폰트 속성 (Normal)
		size,							// 폰트 크기
		L"ko",							// 지역 이름
		&fonts[name]					// 저장 변수 포인터
	);
	return fonts[name];
}

void Renderer::Text(std::string letter, std::string fontName, D2DRECTF boundary, D2DCOLOR color, float rotate)
{
	std::wstring tempW = StringToWstring(letter);
	const wchar_t* tempLetter = tempW.c_str();

	float tempDegree = rotate * 180 / (float)M_PI;
	float x = (boundary.right + boundary.left) / 2.f;
	float y = (boundary.bottom + boundary.top) / 2.f;

	D2D1::Matrix3x2F tempRotateMatrix = D2D1::Matrix3x2F::Rotation(tempDegree, D2D1::Point2F(x, y));
	D2DRenderTarget->SetTransform(tempRotateMatrix);
	D2DRenderTarget->CreateSolidColorBrush(color, &brush);
	D2DRenderTarget->DrawTextW(
		tempLetter,
		wcslen(tempLetter),
		fonts[fontName],
		boundary,
		brush
	);
	D2DRenderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
	SafeRelease(brush);
}

void Renderer::TextWithInstanceFont(std::string letter, std::string fontName, float size, D2DRECTF boundary, D2DCOLOR color, float rotate)
{
	IDWriteTextFormat* textFormat;

	std::wstring tempW = StringToWstring(fontName);
	const wchar_t* tempName = tempW.c_str();

	D2DWriteFactory->CreateTextFormat(
		tempName,						// 폰트 이름
		0,								// 폰트 컬렉션 (0)
		DWRITE_FONT_WEIGHT_REGULAR,		// 폰트 굵기
		DWRITE_FONT_STYLE_NORMAL,		// 폰트 스타일 (Normal, Italic, Obique)
		DWRITE_FONT_STRETCH_NORMAL,		// 폰트 속성 (Normal)
		size,							// 폰트 크기
		L"ko",							// 지역 이름
		&textFormat						// 저장 변수 포인터
	);
	D2DRenderTarget->CreateSolidColorBrush(color, &brush);

	tempW = StringToWstring(letter);
	const wchar_t* tempLetter = tempW.c_str();

	float tempDegree = rotate * 180 / (float)M_PI;
	float x = (boundary.right + boundary.left) / 2.f;
	float y = (boundary.bottom + boundary.top) / 2.f;

	D2D1::Matrix3x2F tempRotateMatrix = D2D1::Matrix3x2F::Rotation(tempDegree, D2D1::Point2F(x, y));

	D2DRenderTarget->SetTransform(tempRotateMatrix);
	D2DRenderTarget->DrawTextW(
		tempLetter,
		wcslen(tempLetter),
		textFormat,
		D2D1::RectF(0, 0, 600.0f, 500.0f),
		brush
	);
	D2DRenderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
	SafeRelease(brush);
}

Matrix& Renderer::RenderSet(Matrix& transform, bool relative, bool zoom)
{
	Matrix result;
	if (relative)
	{
		result = transform * CAMERA.GetInvertView();
	}
	else
	{
		result = transform;
	}
	if (zoom)
	{
		float zoomRate = MOUSE.GetWheelValue()/_maxZoom;
		Matrix* temp = new Matrix
		(
			{ -(0.f - transform.GetPosition().x) * zoomRate ,
			-(0.f - transform.GetPosition().y) * zoomRate }, 
			{ zoomRate + 1,zoomRate + 1}, 
			0.f
		);
		result = result * (*temp);
	}
	return result;
}

void Renderer::InitializeD2D()
{
	CoInitialize(NULL);

	HRESULT hr = E_FAIL;
	//D2D Factory 생성
	hr = ::D2D1CreateFactory(
		D2D1_FACTORY_TYPE_SINGLE_THREADED, 
		&D2DFactory
	);
	assert(hr == S_OK);

	// Windows Imaging Component Factory 생성
	hr = ::CoCreateInstance(
		CLSID_WICImagingFactory, 
		NULL, 
		CLSCTX_INPROC_SERVER, 
		IID_PPV_ARGS(&WICFactory)
	);
	assert(hr == S_OK);

	//Write Factory 생성
	hr = DWriteCreateFactory(
		DWRITE_FACTORY_TYPE_SHARED,
		__uuidof(IDWriteFactory),
		reinterpret_cast<IUnknown**>(&D2DWriteFactory)
	);
	assert(hr == S_OK);
}

void Renderer::CreateRenderTarget()
{
	HRESULT hr = E_FAIL;

	//윈도우 클라이언트 영역
	RECT tempRc;
	::GetClientRect(_hWnd, &tempRc);

	//윈도우 클라이언트 영역의 크기 구하기
	D2D1_SIZE_U size = D2D1::SizeU(tempRc.right - tempRc.left, tempRc.bottom - tempRc.top);

	//렌더타겟 생성
	hr = D2DFactory->CreateHwndRenderTarget(
		D2D1::RenderTargetProperties(),
		D2D1::HwndRenderTargetProperties(_hWnd, size),
		&D2DRenderTarget);
	assert(hr == S_OK);
}

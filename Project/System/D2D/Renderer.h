#pragma once

#define COLORBLACK D2D1::ColorF(D2D1::ColorF::Black)
#define COLORWHITE D2D1::ColorF(D2D1::ColorF::White)
#define COLORRED D2D1::ColorF(D2D1::ColorF::Red)
#define COLORGREEN D2D1::ColorF(D2D1::ColorF::Green)
#define COLORBLUE D2D1::ColorF(D2D1::ColorF::Blue)

class Renderer
{
	SINGLETONHEADER(Renderer)
public:

private:
	ID2D1Factory* D2DFactory;
	ID2D1HwndRenderTarget* D2DRenderTarget;
	IWICImagingFactory* WICFactory;
	IDWriteFactory* D2DWriteFactory;

	IDWriteFactory* dwFactory;
	ID2D1SolidColorBrush *brush = 0;
	std::unordered_map<std::string, IDWriteTextFormat*> fonts;
	typedef std::unordered_map <std::string, IDWriteTextFormat*>::iterator FontIter;

	bool isDebugMode;

public:
	void Initialize();

	void BeginDraw();
	void EndDraw();

	ID2D1Factory* GetFactory() { return D2DFactory; }
	ID2D1HwndRenderTarget* GetRenderTarget() { return D2DRenderTarget; }
	IWICImagingFactory* GetWICFactory() { return WICFactory; }
	IDWriteFactory* GetWriteFactory() { return D2DWriteFactory; }
	ID2D1SolidColorBrush* GetBrush() { return brush; }

	/* Line */
	void DrawLine(float x, float y, float dx, float dy, D2D1_COLOR_F color = COLORBLACK);

	/* Rectangle */
	void DrawRectangle(D2D1_RECT_F rect, D2D1_COLOR_F color = COLORBLACK, float thikness = 1.0f, float radian = 0.f);
	D2DRECTF DrawRectangle(float x, float y, float sizeX, float sizeY, D2D1_COLOR_F color = COLORBLACK, float thikness = 1.0f, float radian = 0.f);
	void FillRectangle(D2DRECTF& rc, D2D1_COLOR_F color);

	/* Ellipse */
	void DrawEllipse(D2D1_RECT_F rect, D2D1_COLOR_F color = COLORBLACK, float thikness = 1.0f, float radian = 0.f);
	D2DELLIPSE DrawEllipse(float x, float y, float sizeX, float sizeY, D2D1_COLOR_F color = COLORBLACK, float thikness = 1.0f, float radian = 0.f);
	void FillEllipse(D2DELLIPSE& ellipse, D2D1_COLOR_F color);

	/* Text */
	IDWriteTextFormat* AddFont(std::string name, float size);
	void Text(std::string letter, std::string fontName, D2DRECTF boundary, D2DCOLOR color = D2DCOLORF(0.f,0.f,0.f), float rotate = 0.f);
	void TextWithInstanceFont(std::string letter, std::string fontName, float size, D2DRECTF boundary, D2DCOLOR color = D2DCOLORF(0.f,0.f,0.f), float rotate = 0.f);

	/* Camera Set */
	Matrix RenderSet(Matrix transform, bool relative = false, bool zoom = false);

	/* Debug Mode */
	void DebugMode(bool input) { isDebugMode = input; }
	bool IsDebugMode() { return isDebugMode; }

private:
	void InitializeD2D();
	void CreateRenderTarget();
};

#define RENDER Renderer::Get()
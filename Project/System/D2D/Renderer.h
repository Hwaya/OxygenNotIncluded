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

	IDWriteFactory* dwFactory;
	ID2D1SolidColorBrush *brush = 0;

public:
	void Initialize();

	void BeginDraw();
	void EndDraw();

	ID2D1Factory* GetFactory() { return D2DFactory; }
	ID2D1HwndRenderTarget* GetRenderTarget() { return D2DRenderTarget; }
	IWICImagingFactory* GetWICFactory() { return WICFactory; }
	void DrawLine(float x, float y, float dx, float dy, D2D1_COLOR_F color = COLORBLACK);

	void DrawRectangle(D2D1_RECT_F rect, D2D1_COLOR_F color = COLORBLACK, float thikness = 1.0f, float radian = 0.f);
	void DrawRectangle(float x, float y, float sizeX, float sizeY, D2D1_COLOR_F color = COLORBLACK, float thikness = 1.0f, float radian = 0.f);

	void DrawElipse(D2D1_RECT_F rect, D2D1_COLOR_F color = COLORBLACK, float thikness = 1.0f, float radian = 0.f);
	void DrawElipse(float x, float y, float sizeX, float sizeY, D2D1_COLOR_F color = COLORBLACK, float thikness = 1.0f, float radian = 0.f);
	

private:
	void InitializeD2D();
	void CreateRenderTarget();
};

#define RENDERER Renderer::Get()
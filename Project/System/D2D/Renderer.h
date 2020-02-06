#pragma once
class Renderer
{
	SINGLETONHEADER(Renderer)
public:

private:
	ID2D1Factory* D2DFactory;
	ID2D1HwndRenderTarget* D2DRenderTarget;
	IWICImagingFactory* WICFactory;

public:
	void Initialize();

	void BeginPaint();
	void EndPaint();

	ID2D1Factory* GetFactory() { return D2DFactory; }
	ID2D1HwndRenderTarget* GetRenderTarget() { return D2DRenderTarget; }
	IWICImagingFactory* GetWICFactory() { return WICFactory; }
	

private:
	void InitializeD2DFactory();
	void CreateRenderTarget();
	void CreateWICFactory();
};

#define RENDERER Renderer::Get()
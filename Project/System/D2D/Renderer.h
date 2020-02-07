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

	void BeginDraw();
	void EndDraw();

	ID2D1Factory* GetFactory() { return D2DFactory; }
	ID2D1HwndRenderTarget* GetRenderTarget() { return D2DRenderTarget; }
	IWICImagingFactory* GetWICFactory() { return WICFactory; }
	

private:
	void InitializeD2D();
	void CreateRenderTarget();
};

#define RENDERER Renderer::Get()
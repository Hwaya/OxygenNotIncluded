#include "stdafx.h"
#include "Renderer.h"


SINGLETONCPP(Renderer)

void Renderer::Initialize()
{
	CoInitialize(NULL);
	InitializeD2DFactory();
	CreateRenderTarget();
	CreateWICFactory();
}

void Renderer::BeginDraw()
{
	D2DRenderTarget->BeginDraw();
	D2DRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::Black));
}

void Renderer::EndDraw()
{
	D2DRenderTarget->EndDraw();
}

void Renderer::InitializeD2DFactory()
{
	HRESULT hr = E_FAIL;

	//D2D Factory ����

	hr = ::D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &D2DFactory);
	assert(hr == S_OK);
}

void Renderer::CreateRenderTarget()
{
	HRESULT hr = E_FAIL;

	//������ Ŭ���̾�Ʈ ����
	RECT tempRc;
	::GetClientRect(_hWnd, &tempRc);

	//������ Ŭ���̾�Ʈ ������ ũ�� ���ϱ�
	D2D1_SIZE_U size = D2D1::SizeU(tempRc.right - tempRc.left, tempRc.bottom - tempRc.top);

	//����Ÿ�� ����
	hr = D2DFactory->CreateHwndRenderTarget(D2D1::RenderTargetProperties(),
		D2D1::HwndRenderTargetProperties(_hWnd, size),
		&D2DRenderTarget);
	assert(hr == S_OK);
}

void Renderer::CreateWICFactory()
{
	HRESULT hr = E_FAIL;
	
	// Windows Imaging Component Factory ����
	hr = ::CoCreateInstance(CLSID_WICImagingFactory, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&WICFactory));
	
	assert(hr == S_OK);
}

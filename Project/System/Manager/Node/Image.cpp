#include "stdafx.h"
#include "Image.h"

Image::Image(std::string filePath)
	:path(filePath)
{
	Initialize();
	CreateImage(filePath);
}

void Image::Initialize()
{
	path = "";
	srcBitmap = nullptr;
	D2DBitmap = nullptr;
	decoder = nullptr;
	frame = nullptr;
}

void Image::CreateImage(std::string filePath)
{
	HRESULT hr = S_OK;

	// Decoder ����
	hr = RENDERER.GetWICFactory()->CreateDecoderFromFilename
	(
		std::wstring(path.begin(), path.end()).c_str(),
		nullptr, 
		GENERIC_READ, 
		WICDecodeMetadataCacheOnDemand, 
		&decoder
	);
	assert(hr == S_OK);

	// Frame ����
	hr = decoder->GetFrame(0, &frame);
	assert(hr == S_OK);

	//srcBitmap �ʱ�ȭ
	SafeRelease(srcBitmap);
	hr = RENDERER.GetWICFactory()->CreateFormatConverter(&srcBitmap);
	assert(hr == S_OK);

	//Frame�� ���� ������ ����
	hr = srcBitmap->Initialize
	(
		frame, 
		GUID_WICPixelFormat32bppBGRA, 
		WICBitmapDitherTypeNone, 
		nullptr,
		0.0f,
		WICBitmapPaletteTypeCustom
	);
	assert(hr == S_OK);

	//������ �̹����� ���� �̹��� ����
	SafeRelease(D2DBitmap);
	hr = RENDERER.GetRenderTarget()->CreateBitmapFromWicBitmap(srcBitmap, nullptr, &D2DBitmap);
	assert(hr == S_OK);

	SafeRelease(decoder);
	SafeRelease(frame);
}

void Image::Render(float x, float y, float sizeX, float sizeY, float alpha = 1.f)
{
	if (D2DBitmap != nullptr)
	{

		float left, top, right, bottom;
		left = x - sizeX / 2;
		top = y - sizeY / 2;
		right = x + sizeX / 2;
		bottom = y + sizeY / 2;
		::D2D1_RECT_F area =  D2D1::RectF(left, top, right, bottom);
		RENDERER.GetRenderTarget()->DrawBitmap(D2DBitmap, area, alpha);
	}
}

void Image::Render(float x, float y, float sizeX, float sizeY, float radian, float alpha = 1.f)
{
}

void Image::FrameRender(float x, float y, float sizeX, float sizeY, int frameX, int frameY)
{
}

void Image::FrameRender(float x, float y, float sizeX, float sizeY, float radian, int frameX, int frameY)
{
}

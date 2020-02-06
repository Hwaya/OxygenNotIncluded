#include "stdafx.h"
#include "Image.h"

void Image::Initialize(std::string filePath, float inputWidth, float inputHeight)
{
	info.path = filePath;
	info.width = inputWidth;
	info.height = inputHeight;
	CreateImage(filePath);
}

void Image::Initialize(std::string filePath, float inputWidth, float inputHeight, int inputFrameMaxX, int inputFrameMaxY, float inputFrameWidth, float inputFrameHeight)
{
	info.path = filePath;
	info.width = inputWidth;
	info.height = inputHeight;
	info.frameMaxX = inputFrameMaxX;
	info.frameMaxY = inputFrameMaxY;
	info.frameWidth = inputFrameWidth;
	info.frameHeight = inputFrameHeight;
	CreateImage(filePath);
}

void Image::CreateImage(std::string filePath)
{
	HRESULT hr = S_OK;

	std::wstring abc = std::wstring(info.path.begin(), info.path.end());
	LPCWSTR test = abc.c_str();

	// Decoder 생성
	hr = RENDERER.GetWICFactory()->CreateDecoderFromFilename
	(
		std::wstring(info.path.begin(), info.path.end()).c_str(),
		nullptr, 
		GENERIC_READ, 
		WICDecodeMetadataCacheOnDemand, 
		&info.decoder
	);
	assert(hr == S_OK);

	// Frame 추출
	hr = info.decoder->GetFrame(0, &info.frame);
	assert(hr == S_OK);

	//srcBitmap 초기화
	SafeRelease(info.srcBitmap);
	hr = RENDERER.GetWICFactory()->CreateFormatConverter(&info.srcBitmap);
	assert(hr == S_OK);

	//Frame에 따른 컨버터 생성
	hr = info.srcBitmap->Initialize
	(
		info.frame,
		/*GUID_WICPixelFormat32bppBGRA, */
		GUID_WICPixelFormat32bppBGR,
		WICBitmapDitherTypeNone, 
		nullptr,
		0.0f,
		WICBitmapPaletteTypeCustom
	);
	assert(hr == S_OK);

	//컨버터 이미지로 실제 이미지 생성
	SafeRelease(info.D2DBitmap);
	hr = RENDERER.GetRenderTarget()->CreateBitmapFromWicBitmap(info.srcBitmap, nullptr, &info.D2DBitmap);
	assert(hr == S_OK);

	SafeRelease(info.decoder);
	SafeRelease(info.frame);
}

void Image::Render(float x, float y, float sizeX, float sizeY, float alpha = 1.f)
{
	if (info.D2DBitmap != nullptr)
	{

		float left, top, right, bottom;
		left = x - sizeX / 2;
		top = y - sizeY / 2;
		right = x + sizeX / 2;
		bottom = y + sizeY / 2;
		::D2D1_RECT_F area =  D2D1::RectF(left, top, right, bottom);
		RENDERER.GetRenderTarget()->DrawBitmap(info.D2DBitmap, area, alpha);
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

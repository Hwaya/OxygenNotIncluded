#include "stdafx.h"
#include "Image.h"

Image::Image(std::string filePath)
{
	Initialize();
	CreateImage(filePath);
	path = filePath;
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
	hr = RENDERER.GetWICFactory()->CreateDecoderFromFilename(
		std::wstring(path.begin(), path.end()).c_str(),
		nullptr, 
		GENERIC_READ, 
		WICDecodeMetadataCacheOnDemand, 
		&decoder);
	assert(hr == S_OK);

	hr = decoder->GetFrame(0, &frame);
	assert(hr == S_OK);

	SafeRelease(srcBitmap);
	hr = RENDERER.GetWICFactory()->CreateFormatConverter(&srcBitmap);
	assert(hr == S_OK);

	hr = srcBitmap->Initialize(frame, 
		GUID_WICPixelFormat32bppBGRA, 
		WICBitmapDitherTypeNone, 
		nullptr,
		0.0f,
		WICBitmapPaletteTypeCustom);
	assert(hr == S_OK);
		
}

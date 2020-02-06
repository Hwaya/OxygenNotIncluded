#pragma once
class Image
{
private:
	std::string path;

	IWICFormatConverter* srcBitmap;
	ID2D1Bitmap* D2DBitmap;
	IWICBitmapDecoder* decoder;
	IWICBitmapFrameDecode* frame;
	
public:
	Image(std::string filePath);

	void Initialize();

	void CreateImage(std::string filePath);
};


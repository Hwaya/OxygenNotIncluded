#pragma once
class Image
{
private:
	std::string path;
	float width;
	float height;
	int frameMaxX;
	int frameMaxY;
	float frameWidth;
	float frameHeight;

	IWICFormatConverter* srcBitmap;
	ID2D1Bitmap* D2DBitmap;
	IWICBitmapDecoder* decoder;
	IWICBitmapFrameDecode* frame;
	
public:
	Image(std::string filePath);

	void Initialize();

	void CreateImage(std::string filePath);

	void Render(float x, float y, float sizeX, float sizeY, float alpha);
	void Render(float x, float y, float sizeX, float sizeY, float radian, float alpha);

	void FrameRender(float x, float y, float sizeX, float sizeY, int frameX, int frameY);
	void FrameRender(float x, float y, float sizeX, float sizeY, float radian, int frameX, int frameY);
};


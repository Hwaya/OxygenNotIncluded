#pragma once
class Image
{
	friend class ImageManager;

private:
	typedef struct imageInfo
	{
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

		imageInfo()
		{
			path = "";
			width = 0.f;
			height = 0.f;
			frameMaxX = 0;
			frameMaxY = 0;
			frameWidth = 0.f;
			frameHeight = 0.f;

			srcBitmap = nullptr;
			D2DBitmap = nullptr;
			decoder = nullptr;
			frame = nullptr;
		}
	};
	
	imageInfo info;
	
	
public:
	Image() {}
	~Image() {}
	
	void Initialize(std::string filePath, float inputWidth, float inputHeight);
	void Initialize(std::string filePath, float inputWidth, float inputHeight, int inputFrameMaxX, int inputFrameMaxY,
		float inputFrameWidth, float inputFrameHeight);

	void CreateImage(std::string filePath);

	void Render(float x, float y, float sizeX, float sizeY, float alpha);
	void Render(float x, float y, float sizeX, float sizeY, float radian, float alpha);

	void FrameRender(float x, float y, float sizeX, float sizeY, int frameX, int frameY);
	void FrameRender(float x, float y, float sizeX, float sizeY, float radian, int frameX, int frameY);
};


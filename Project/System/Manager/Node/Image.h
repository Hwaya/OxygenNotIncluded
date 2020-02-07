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

		ID2D1Bitmap* D2DBitmap;

		imageInfo()
		{
			path = "";
			width = 0.f;
			height = 0.f;
			frameMaxX = 0;
			frameMaxY = 0;
			frameWidth = 0.f;
			frameHeight = 0.f;
		}
	};
	
	imageInfo info;
	
	
public:
	Image() {}
	~Image() {}
	
	void Initialize(std::string filePath);
	void Initialize(std::string filePath, int inputFrameMaxX, int inputFrameMaxY);

	void CreateImage();

	void Render(float x, float y, float sizeX, float sizeY, float alpha);
	void Render(float x, float y, float sizeX, float sizeY, float radian, float alpha);

	void FrameRender(float x, float y, float sizeX, float sizeY, int frameX, int frameY, float alpha);
	void FrameRender(float x, float y, float sizeX, float sizeY, float radian, int frameX, int frameY, float alpha);
};

// radian À» Degree·Î
// radian * 180 / pi;
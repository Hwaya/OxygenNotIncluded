#pragma once

#include "Node/Image.h"

class ImageManager
{
	SINGLETONHEADER(ImageManager)
public:
	void Initialize();

	/*void Initialize(std::string filePath, float inputWidth, float inputHeight);
	void Initialize(std::string filePath, float inputWidth, float inputHeight, int inputFrameMaxX, int inputFrameMaxY,
		float inputFrameWidth, float inputFrameHeight);*/

	Image* Add(std::string key, std::string path, float inputWidth, float inputHeight);
	Image* FrameAdd(std::string key, std::string path, float inputWidth, float inputHeight,
		int inputFrameMaxX, int inputFrameMaxY, float inputFrameWidth, float inputFrameHeight);
	Image* Find(std::string key);
	void Del(std::string key);

	std::unordered_map<std::string, Image*> GetStorage() { return imageStorage; }
private:
	std::unordered_map<std::string, Image*> imageStorage;
	typedef std::unordered_map<std::string, Image*>::iterator ImgIter;
};

#define IMAGEMANGER ImageManager::Get()

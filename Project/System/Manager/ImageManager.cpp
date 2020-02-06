#include "stdafx.h"
#include "ImageManager.h"

SINGLETONCPP(ImageManager)

void ImageManager::Initialize()
{

}

Image * ImageManager::Add(std::string key, std::string path, float inputWidth, float inputHeight)
{
	ImgIter tempIter;
	tempIter = imageStorage.find(key);
	if (tempIter != imageStorage.end())
	{
		return tempIter->second;
	}
	else
	{
		Image* newImage = new Image();
		newImage->Initialize(path, inputWidth, inputHeight);
		imageStorage.insert(make_pair(key, newImage));
	}
}

Image * ImageManager::FrameAdd(std::string key, std::string path, float inputWidth, float inputHeight, int inputFrameMaxX, int inputFrameMaxY, float inputFrameWidth, float inputFrameHeight)
{
	ImgIter tempIter;
	tempIter = imageStorage.find(key);
	if (tempIter != imageStorage.end())
	{
		return tempIter->second;
	}
	else
	{
		Image* newImage = new Image();
		newImage->Initialize(path, inputWidth, inputHeight, inputFrameMaxX, inputFrameMaxY, inputFrameWidth, inputFrameHeight);
		imageStorage.insert(make_pair(key, newImage));
	}
}

Image * ImageManager::Find(std::string key)
{
	ImgIter tempIter;
	tempIter = imageStorage.find(key);
	if (tempIter == imageStorage.end())
	{
		return nullptr;
	}
	return imageStorage[key];
}

void ImageManager::Del(std::string key)
{
	ImgIter tempIter;
	tempIter = imageStorage.find(key);
	if (tempIter != imageStorage.end())
	{
		imageStorage.erase(key);
	}
}
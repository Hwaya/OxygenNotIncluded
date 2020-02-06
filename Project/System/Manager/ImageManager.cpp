#include "stdafx.h"
#include "ImageManager.h"

SINGLETONCPP(ImageManager)

void ImageManager::Initialize()
{

}

Image* ImageManager::Add(std::string key, std::string path)
{
	ImgIter tempIter;
	tempIter = imageStorage.find(key);
	if (tempIter != imageStorage.end())
	{
		return tempIter->second;
	}
	else
	{
		//imageStorage.insert(make_pair(key, Image()));
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
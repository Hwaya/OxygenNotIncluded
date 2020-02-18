#pragma once
#include "stdafx.h"

/* SafeFunction */
template <typename T>
inline void SafeRelease(T* &p)
{
	if (NULL != p)
	{
		p->Release();
		p = NULL;
	}
}

template <typename T>
inline void SafeDelete(T* &p)
{
	if (NULL != p)
	{
		delete(p);
		p = NULL;
	}
}

template <typename T>
inline void SafeDeleteArray(T* &p)
{
	if (NULL != p)
	{
		delete[](p);
		p = NULL;
	}
}

/* Singleton Macro */
#define LOCK_COPY(ClassName)				\
private:									\
	ClassName(const ClassName&);			\
	ClassName& operator=(const ClassName&);	

#define SINGLETONHEADER(ClassName)			\
	LOCK_COPY(ClassName)					\
	private:								\
		ClassName() {}						\
		static ClassName* instance;			\
	public:									\
		static ClassName& Get();			\
		static void Create();				\
		static void Delete();

#define SINGLETONCPP(ClassName)				\
ClassName* ClassName::instance = 0;			\
ClassName& ClassName::Get()					\
{											\
	return *instance;						\
}											\
void ClassName::Create()					\
{											\
	if (instance == 0)						\
	{										\
		instance = new ClassName();			\
	}										\
}											\
void ClassName::Delete()					\
{											\
	if (instance != 0)						\
	{										\
		SafeDelete(instance);				\
	}										\
}

/* String Converter */
inline std::wstring StringToWstring(const std::string& input)
{
	USES_CONVERSION;
	return std::wstring(A2W(input.c_str()));
};

inline std::string WstringToString(const std::wstring& input)
{
	USES_CONVERSION;
	return std::string(W2A(input.c_str()));
};

/* Math */
inline float GetDistance(float sx, float sy, float dx, float dy)
{
	return  sqrtf(powf(dx - sx, 2) + powf(dy - sy, 2));
}
inline float GetAngle(float sx, float sy, float dx, float dy)
{
	return atan2f(dy - sy, dx - sx);
}
#pragma once
#include <string>

#ifdef CUSTOM_LIB_EXPORT
#define CUSTOM_LIB_API __declspec(dllexport)
#else
#define CUSTOM_LIB_API __declspec(dllimport)
#endif
extern "C" CUSTOM_LIB_API void MyCustomLib(const std::string& name);
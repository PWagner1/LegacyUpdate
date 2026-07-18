#pragma once

#include <windows.h>
#include <SafeString.h>

static inline HMODULE LoadSystemLibrary(LPCWSTR name) {
	WCHAR path[MAX_PATH];
	GetSystemDirectory(path, ARRAYSIZE(path));
	StringCchCat(path, ARRAYSIZE(path), L"\\");
	StringCchCat(path, ARRAYSIZE(path), name);
	return LoadLibrary(path);
}

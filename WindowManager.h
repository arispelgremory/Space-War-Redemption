#pragma once
#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#define WIN32_LEAN_AND_MEAN // Only include the skinny(LEAN) and powerful(MEAN) part of Windows.h
#include <Windows.h>
#include "GameConfiguration.h"

class WindowManager {
public:
	WindowManager();
	~WindowManager();

	static WindowManager* GetInstance();
	static LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	void CreateGameWindow();
	bool IsRunning();

	void CleanUpWindow();
	HWND GetWindowHandle();

private:
	static WindowManager* _instance;
	HWND g_hWnd = NULL;
	WNDCLASS wndClass;

};

#endif
#pragma once
#include <Windows.h>
#include "AppConfiguration.h"

class WindowManager
{
private:
	static WindowManager* _instance;
	WNDCLASS wndClass;
	HWND hWnd;
public:
	WindowManager(void);
	void CreateGameWindow(HINSTANCE hInstance);
	static WindowManager* GetInstance();
	static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
	void InitWindowHandler(HINSTANCE hInstance, int nCmdShow);
	HWND GetWindowHandler();
	bool IsRunning();
	void CleanUpWindow();
	~WindowManager(void);
};


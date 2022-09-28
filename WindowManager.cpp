#include "WindowManager.h"


WindowManager::WindowManager() {}

WindowManager::~WindowManager() {}

LRESULT WindowManager::WindowProcedure(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message)
	{
		//	the message is post when we destroy the window.
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case  WM_KEYDOWN:
		switch (wParam) {
			// Quit the message when escape key is pressed down
		case VK_ESCAPE:
			PostQuitMessage(0);
			break;
		}
		break;
		//	default handling for other messages.
	default:
		return DefWindowProc(hWnd, message, wParam, lParam); // return messages back to the os
	}

	return 0;
}

WindowManager* WindowManager::_instance = 0;
WindowManager* WindowManager::GetInstance()
{
	if (_instance == 0)
		_instance = new WindowManager;
	return _instance;
}

void WindowManager::CreateGameWindow() {
	//	set all members in wndclass to 0.
	ZeroMemory(&wndClass, sizeof(wndClass));
	//	filling wndclass. you are to refer to msdn for each of the members details.
	//	these are the fundamental structure members to be specify, in order to create your window.
	wndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hInstance = GetModuleHandle(NULL);
	wndClass.lpfnWndProc = WindowProcedure; // Long Pointer to a window procedure function
	wndClass.lpszClassName = "Space War Redemption";
	wndClass.style = CS_HREDRAW | CS_VREDRAW;

	//	register the window.
	RegisterClass(&wndClass);

	//	you are to refer to msdn for each of the parameters details.
	//  create instance of window
	g_hWnd = CreateWindowEx(0, wndClass.lpszClassName, "Space War Redemption", WS_OVERLAPPEDWINDOW, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, NULL, NULL, GetModuleHandle(NULL), NULL);
	ShowWindow(g_hWnd, 1);
}

bool WindowManager::IsRunning() {
	MSG msg;
	ZeroMemory(&msg, sizeof(msg)); // Set memory to zero (To clear the memory)
	bool running = true;

	while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
		//	Receive a quit message
		if (msg.message == WM_QUIT)
			running = false;
		//	Translate the message 
		TranslateMessage(&msg);
		//	Send message to your window procedure
		DispatchMessage(&msg);
	}
	return running;
}

void WindowManager::CleanUpWindow() {
	UnregisterClass(wndClass.lpszClassName, GetModuleHandle(NULL));
}

HWND WindowManager::GetWindowHandle() {
	return g_hWnd;
}

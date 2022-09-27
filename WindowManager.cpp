#include "WindowManager.h"

WindowManager* WindowManager::_instance = 0;
WindowManager::WindowManager()
{

}

WindowManager* WindowManager::GetInstance()
{
	if (_instance == 0)
		_instance = new WindowManager();
	return _instance;
}

LRESULT WindowManager::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}

void WindowManager::CreateGameWindow(HINSTANCE hInstance)
{
	//	Set all members in wndClass to 0.
	ZeroMemory(&wndClass, sizeof(wndClass));

	//	Filling wndClass. You are to refer to MSDN for each of the members details.
	//	These are the fundamental structure members to be specify, in order to create your window.
	wndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hInstance = GetModuleHandle(NULL);
	wndClass.lpfnWndProc = WndProc; // Long Pointer to a window procedure function
	wndClass.lpszClassName = CLASS_NAME;
	wndClass.style = CS_HREDRAW | CS_VREDRAW;

	//	Register the window.
	RegisterClass(&wndClass);
}

void WindowManager::InitWindowHandler(HINSTANCE hInstance, int nCmdShow)
{
	CreateGameWindow(hInstance);

	//  Create instance of window
	HWND hWnd = CreateWindowEx(
		0, CLASS_NAME, TITLE_STR, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, SCREEN_WIDTH, SCREEN_HEIGHT, NULL, NULL, GetModuleHandle(NULL), NULL);

	if (!hWnd)
	{
		return;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	//ShowCursor(false);
	this->hWnd = hWnd;
}

HWND WindowManager::GetWindowHandler()
{
	return hWnd;
}

bool WindowManager::IsRunning()
{
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

void WindowManager::CleanUpWindow()
{
	UnregisterClass(wndClass.lpszClassName, GetModuleHandle(NULL));
}

WindowManager::~WindowManager()
{
}
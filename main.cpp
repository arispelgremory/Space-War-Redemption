//	Ask the compiler to include minimal header files for our program.
// #define -> Instruction to communicate with the compiler
#define WIN32_LEAN_AND_MEAN // Only include the skinny(LEAN) and powerful(MEAN) part of Windows.h
#include <Windows.h>
#include <d3d9.h>

#include "GameConfiguration.h"
#include "WindowManager.h"

WindowManager* windowManager = new WindowManager();

//	use WinMain if you don't want the console
int main(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
	/*
	   HINSTANCE hInstance - ID Number
	   HINSTANCE hPrevInstance - previous window
	   LPSTR lpCmdLine - Long pointer to a command line (ping.exe ->www.yahoo.com<-)
	   int nShowCmd - window mode (fullscreen, borderless)
	*/

	// Create Window
	windowManager->CreateGameWindow();


	CreateMyDX();
	CreateMyDInput();

	while (WindowIsRunning()) {
		GetInput();
		Update(10);
		Render();
	}
	CleanupMyLevel();
	CleanUpMyDirectInput();
	CleanupMyDx();
	CleanupMyWindow();

	return 0;

}
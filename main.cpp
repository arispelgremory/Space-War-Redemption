//	Ask the compiler to include minimal header files for our program.
// #define -> Instruction to communicate with the compiler
#define WIN32_LEAN_AND_MEAN // Only include the skinny(LEAN) and powerful(MEAN) part of Windows.h
#include "GameConfiguration.h"
#include "FrameTimer.h"

//WindowManager* windowManager = new WindowManager();
//D3DDeviceManger* deviceManager = new D3DDeviceManger();
//InputManager* inputManager = new InputManager();
//
//FrameTimer* timer = new FrameTimer();

void Update(int FPS) 
{

}

void Render() 
{
    D3DDEVICE->BeginRender();
    D3DDEVICE->BeginSpriteBrush();

    // Draw Something here

    D3DDEVICE->EndSpriteBrush();
    D3DDEVICE->SwapScene();
}

//	use WinMain if you don't want the console
int main(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
    /*
       HINSTANCE hInstance - ID Number
       HINSTANCE hPrevInstance - previous window
       LPSTR lpCmdLine - Long pointer to a command line (ping.exe ->www.yahoo.com<-)
       int nShowCmd - window mode (fullscreen, borderless)
    */

    // Create Window
    WINDOW->CreateGameWindow();

    // Create D3D Devices
    D3DDEVICE->CreateD3D9Device(WINDOW->GetWindowHandle());

    // Create Input
    USERINPUT->Init(WINDOW->GetWindowHandle());
    FRAMETIMER->Init(GAMEFPS);

    while (WINDOW->IsRunning()) {
        USERINPUT->GetInput();
        Update(FRAMETIMER->framesToUpdate());
        Render();
    }
    // CleanupMyLevel();
    USERINPUT->CleanUpInput();
    D3DDEVICE->CleanUpMyD3D9Device();
    WINDOW->CleanUpWindow();

	return 0;
}


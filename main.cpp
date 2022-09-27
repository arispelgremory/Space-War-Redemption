//	Ask the compiler to include minimal header files for our program.
// #define -> Instruction to communicate with the compiler
#define WIN32_LEAN_AND_MEAN // Only include the skinny(LEAN) and powerful(MEAN) part of Windows.h
#include "GameConfiguration.h"
#include "FrameTimer.h"

WindowManager* windowManager = new WindowManager();
D3DDeviceManger* deviceManager = new D3DDeviceManger();
InputManager* inputManager = new InputManager();

FrameTimer* timer = new FrameTimer();

void Update(int FPS) {

}

void Render() {
    deviceManager->BeginRender();
    deviceManager->BeginSpriteBrush();

    // Draw Something here

    deviceManager->EndSpriteBrush();
    deviceManager->SwapScene();
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
    windowManager->CreateGameWindow();
    
    // Create D3D Devices
    deviceManager->CreateD3D9Device(windowManager->GetWindowHandle());

    // Create Input
    inputManager->Init(windowManager->GetWindowHandle());
    timer->Init(GAMEFPS);

    while (windowManager->IsRunning()) {
        inputManager->GetInput();
        Update(timer->framesToUpdate());
        Render();
    }
    // CleanupMyLevel();
    inputManager->CleanUpInput();
    deviceManager->CleanUpMyD3D9Device();
    windowManager->CleanUpWindow();

	return 0;
}


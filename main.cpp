//	Ask the compiler to include minimal header files for our program.
// #define -> Instruction to communicate with the compiler
#define WIN32_LEAN_AND_MEAN // Only include the skinny(LEAN) and powerful(MEAN) part of Windows.h
#include "GameConfiguration.h"
#include "MainMenuScene.h"
#include "Scenes.h"
#include "Line.h"
#include "Text.h"
#include "FrameTimer.h"


WindowManager* windowManager = new WindowManager();
D3DDeviceManager* deviceManager = new D3DDeviceManager();
Line* lineObject = new Line();
Text* textObject = new Text();
InputManager* inputManager = new InputManager();

FrameTimer* timer = new FrameTimer();
vector<Scenes*> SCENES;

void Initialize()
{
    SCENES.push_back(new MainMenuScene());
    SCENES.back()->Initialize(deviceManager->GetD3D9Device());
}

void Update(int FPS)
{
    SCENES.back()->Update();
}

void Render()
{
    deviceManager->BeginRender();
    deviceManager->BeginSpriteBrush();

    // Draw Something here
    SCENES.back()->Render(deviceManager->GetSpriteBrush());

    deviceManager->EndSpriteBrush();

    SCENES.back()->RenderLine(deviceManager->GetSpriteBrush());
    deviceManager->SwapScene();
}

//	use WinMain if you don't want the console
int main(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    /*
       HINSTANCE hInstance - ID Number
       HINSTANCE hPrevInstance - previous window
       LPSTR lpCmdLine - Long pointer to a command line (ping.exe ->www.yahoo.com<-)
       int nShowCmd - window mode (fullscreen, borderless)
    */

    // Create Window
    windowManager->CreateGameWindow();
    cout << "Test 0" << endl;

    // Create D3D Devices
    deviceManager->CreateD3D9Device(windowManager->GetWindowHandle());
    cout << "Test 1" << endl;

    lineObject->InitLineObject(deviceManager->GetD3D9Device());
    cout << "Test 2" << endl;

    textObject->InitTextObject(deviceManager->GetD3D9Device());
    cout << "Test 3" << endl;


    // Create Input
    inputManager->Init(windowManager->GetWindowHandle());
    cout << "Test 4" << endl;
    timer->Init(GAMEFPS);
    cout << "Test 5" << endl;

    // initialize game level
    Initialize();
    cout << "Test 6" << endl;

    while (windowManager->IsRunning())
    {
        inputManager->GetInput();
        cout << "Test 7" << endl;
        Update(timer->framesToUpdate());
        cout << "Test 8" << endl;
        Render();
        cout << "Test 9" << endl;
    }

    // Clean up
    // CleanupMyLevel();
    inputManager->CleanUpInput();
    lineObject->CleanUpLine();
    textObject->CleanUpText();
    deviceManager->CleanUpMyD3D9Device();
    windowManager->CleanUpWindow();

    return 0;
}

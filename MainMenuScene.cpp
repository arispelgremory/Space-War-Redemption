#include "MainMenuScene.h"
#include "Physics.h"

MainMenuScene::MainMenuScene()
{
}

MainMenuScene::~MainMenuScene()
{
}

void MainMenuScene::Initialize(IDirect3DDevice9* d3dDevice)
{
	// Initialize background image
	bg = new Sprite(BG_DIMENSION, BG_DIMENSION, BG_SPRITEWIDTH, BG_SPRITEHEIGHT, D3DXVECTOR2(1.0f, 1.0f), NULL, D3DXVECTOR2(0, 0));
	cout << "Test 6.1" << endl;
	bg->CreateTexture(d3dDevice, BG_FILEPATH);
	cout << "Test 6.2" << endl;

	// Initialize Game Title
	//Text(int top, int right, int left, int bottom, INT fontHeight, UINT fontWeight, D3DXVECTOR2 position, D3DXVECTOR2 scaling)
	mainTitle = new Text(0, 0, WINDOW_WIDTH / 2, 200, 200, FW_BOLD, D3DXVECTOR2(), D3DXVECTOR2(1.0f, 1.0f));
	mainTitle->InitTextObject(d3dDevice);
	cout << "Test 6.3" << endl;
	
	// Initialize Play Button
	playBox->InitBox(D3DXVECTOR2(150, 170), D3DXVECTOR2(600, 170), D3DXVECTOR2(600, 300), D3DXVECTOR2(150, 300));
	cout << "Test 6.4" << endl;
	playBox->InitLineObject(d3dDevice);
	playBox->SetColour(D3DCOLOR_XRGB(255, 255, 255));

	playText = new Text(playBox->GetBoxColRect().top, playBox->GetBoxColRect().right, playBox->GetBoxColRect().left, playBox->GetBoxColRect().bottom, 100, FW_NORMAL, D3DXVECTOR2(), D3DXVECTOR2(1.0f, 1.0f));
	playText->InitTextObject(d3dDevice);
	playText->SetColour(D3DCOLOR_XRGB(255, 255, 255));

	// Initialize Exit Button
	exitBox->InitBox(D3DXVECTOR2(150, 350), D3DXVECTOR2(600, 350), D3DXVECTOR2(600, 480), D3DXVECTOR2(150, 480));
	exitBox->InitLineObject(d3dDevice);
	exitBox->SetColour(D3DCOLOR_XRGB(255, 255, 255));
	exitText = new Text(exitBox->GetBoxColRect().top, exitBox->GetBoxColRect().right, exitBox->GetBoxColRect().left, exitBox->GetBoxColRect().bottom, 100, FW_NORMAL, D3DXVECTOR2(150, 350), D3DXVECTOR2(1.0f, 1.0f));
	exitText->InitTextObject(d3dDevice);
	exitText->SetColour(D3DCOLOR_XRGB(255, 255, 255));

}

void MainMenuScene::GetInput()
{
	if (input->IsKeyDown(DIK_UP))
	{
		playBox->SetIsFocus(true);
		exitBox->SetIsFocus(false);
	}

	if (input->IsKeyDown(DIK_DOWN))
	{
		exitBox->SetIsFocus(true);
		playBox->SetIsFocus(false);
	}

	if (input->IsKeyDown(DIK_RETURN))
		buttonClicked = true;
}

void MainMenuScene::Update()
{
	cout << "main menu update" << endl;
	if (exitBox->GetIsFocus())
	{
		playBox->SetColour(D3DCOLOR_XRGB(255, 255, 255));
		playText->SetColour(D3DCOLOR_XRGB(0, 0, 0));

		exitBox->SetColour(D3DCOLOR_XRGB(0, 0, 0));
		exitText->SetColour(D3DCOLOR_XRGB(255, 255, 255));
	}

	if (playBox->GetIsFocus())
	{
		playBox->SetColour(D3DCOLOR_XRGB(0, 0, 0));
		playText->SetColour(D3DCOLOR_XRGB(255, 255, 255));

		exitBox->SetColour(D3DCOLOR_XRGB(255, 255, 255));
		exitText->SetColour(D3DCOLOR_XRGB(0, 0, 0));
	}

	if (exitBox->GetIsFocus() && buttonClicked)
		PostQuitMessage(0);

	if (playBox->GetIsFocus() && buttonClicked)
		//ChangeScene();
		PostQuitMessage(0);
}

void MainMenuScene::Render(LPD3DXSPRITE spriteBrush)
{
	cout << "Test 8.0" << endl;
	mainTitle->DrawOutText(spriteBrush, "Space War Redemption", 20, DT_CENTER, D3DCOLOR_XRGB(255, 255, 255));
	cout << "Test 8.1" << endl;

	playBox->DrawBox();
	cout << "Test 8.2" << endl;
	playText->DrawOutText(spriteBrush, "PLAY", 4, DT_CENTER);
	cout << "Test 8.3" << endl;
	
	exitBox->DrawBox();
	cout << "Test 8.4" << endl;
	exitText->DrawOutText(spriteBrush, "EXIT", 4, DT_CENTER);
	cout << "Test 8.5" << endl;
}

void MainMenuScene::Clean()
{
	bg->DestroyTexture();

	mainTitle->CleanUpText();

	playText->CleanUpText();
	playBox->CleanUpLine();

	exitText->CleanUpText();
	exitBox->CleanUpLine();
}


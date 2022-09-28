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
	bg->CreateTexture(d3dDevice, BG_FILEPATH);

	// Initialize Game Title
	//Text(int top, int right, int left, int bottom, INT fontHeight, UINT fontWeight, D3DXVECTOR2 position, D3DXVECTOR2 scaling)
	mainTitle = new Text(0, 0, WINDOW_WIDTH / 2, 200, 200, FW_BOLD, D3DXVECTOR2(), D3DXVECTOR2(1.0f, 1.0f));

	// Initialize Play Button
	playBox->InitBox(D3DXVECTOR2(), D3DXVECTOR2(), D3DXVECTOR2(), D3DXVECTOR2());
	playBox->SetColour(D3DCOLOR_XRGB(0, 0, 0));
	playText = new Text(playBox->GetBoxColRect().top, playBox->GetBoxColRect().right, playBox->GetBoxColRect().left, playBox->GetBoxColRect().bottom, 100, FW_NORMAL, D3DXVECTOR2(), D3DXVECTOR2(1.0f, 1.0f));
	playText->SetColour(D3DCOLOR_XRGB(255, 255, 255));

	// Initialize Exit Button
	exitBox->InitBox(D3DXVECTOR2(), D3DXVECTOR2(), D3DXVECTOR2(), D3DXVECTOR2());
	exitBox->SetColour(D3DCOLOR_XRGB(0, 0, 0));
	exitText = new Text(exitBox->GetBoxColRect().top, exitBox->GetBoxColRect().right, exitBox->GetBoxColRect().left, exitBox->GetBoxColRect().bottom, 100, FW_NORMAL, D3DXVECTOR2(), D3DXVECTOR2(1.0f, 1.0f));
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

void MainMenuScene::Render(LPD3DXSPRITE spriteBrush, IDirect3DDevice9* d3dDevice)
{
	mainTitle->DrawOutText(spriteBrush, "Space War Redemption", 20, DT_CENTER, D3DCOLOR_XRGB(255, 255, 255));

	playBox->DrawBox();
	playText->DrawOutText(spriteBrush, "PLAY", 4, DT_CENTER);

	exitBox->DrawBox();
	exitText->DrawOutText(spriteBrush, "EXIT", 4, DT_CENTER);
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


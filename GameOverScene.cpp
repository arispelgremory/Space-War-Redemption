#include "GameOverScene.h"

GameOverScene::GameOverScene()
{
}

GameOverScene::~GameOverScene()
{
}

void GameOverScene::Initialize(IDirect3DDevice9* d3dDevice)
{
	// Initialize background image
	bg = new Sprite(BG_DIMENSION, BG_DIMENSION, BG_SPRITEWIDTH, BG_SPRITEHEIGHT, D3DXVECTOR2(1.0f, 1.0f), NULL, D3DXVECTOR2(0, 0));
	bg->CreateTexture(d3dDevice, BG_FILEPATH);

	// Initialize Game Title
	//Text(int top, int right, int left, int bottom, INT fontHeight, UINT fontWeight, D3DXVECTOR2 position, D3DXVECTOR2 scaling)
	gameOverText = new Text(0, 0, WINDOW_WIDTH / 2, 200, 200, FW_BOLD, D3DXVECTOR2(), D3DXVECTOR2(1.0f, 1.0f));

	// Initialize retry Button
	retryBox->InitBox(D3DXVECTOR2(300, 350), D3DXVECTOR2(500, 350), D3DXVECTOR2(500, 400), D3DXVECTOR2(300, 400));
	retryBox->SetColour(D3DCOLOR_XRGB(0, 0, 0));
	retryText = new Text(retryBox->GetBoxColRect().top, retryBox->GetBoxColRect().right, retryBox->GetBoxColRect().left, retryBox->GetBoxColRect().bottom, 100, FW_NORMAL, D3DXVECTOR2(), D3DXVECTOR2(1.0f, 1.0f));
	retryText->SetColour(D3DCOLOR_XRGB(255, 255, 255));

	// Initialize Exit Button
	exitBox->InitBox(D3DXVECTOR2(), D3DXVECTOR2(), D3DXVECTOR2(), D3DXVECTOR2());
	exitBox->SetColour(D3DCOLOR_XRGB(0, 0, 0));
	exitText = new Text(exitBox->GetBoxColRect().top, exitBox->GetBoxColRect().right, exitBox->GetBoxColRect().left, exitBox->GetBoxColRect().bottom, 100, FW_NORMAL, D3DXVECTOR2(), D3DXVECTOR2(1.0f, 1.0f));
	exitText->SetColour(D3DCOLOR_XRGB(255, 255, 255));
}

void GameOverScene::GetInput()
{
	if (input->IsKeyDown(DIK_LEFT))
	{
		retryBox->SetIsFocus(true);
		exitBox->SetIsFocus(false);
	}

	if (input->IsKeyDown(DIK_RIGHT))
	{
		exitBox->SetIsFocus(true);
		retryBox->SetIsFocus(false);
	}

	if (input->IsKeyDown(DIK_RETURN))
		isClicked = true;
}

void GameOverScene::Update()
{
	if (exitBox->GetIsFocus())
	{
		retryBox->SetColour(D3DCOLOR_XRGB(255, 255, 255));
		retryText->SetColour(D3DCOLOR_XRGB(0, 0, 0));

		exitBox->SetColour(D3DCOLOR_XRGB(0, 0, 0));
		exitText->SetColour(D3DCOLOR_XRGB(255, 255, 255));
	}

	if (retryBox->GetIsFocus())
	{
		retryBox->SetColour(D3DCOLOR_XRGB(0, 0, 0));
		retryText->SetColour(D3DCOLOR_XRGB(255, 255, 255));

		exitBox->SetColour(D3DCOLOR_XRGB(255, 255, 255));
		exitText->SetColour(D3DCOLOR_XRGB(0, 0, 0));
	}

	if (exitBox->GetIsFocus() && isClicked)
		PostQuitMessage(0);

	if (retryBox->GetIsFocus() && isClicked)
		//ChangeScene();
		PostQuitMessage(0);
}

void GameOverScene::Render(LPD3DXSPRITE spriteBrush, IDirect3DDevice9* d3dDevice)
{
	gameOverText->DrawOutText(spriteBrush, "GAME OVER", 20, DT_CENTER, D3DCOLOR_XRGB(255, 255, 255));

	retryBox->DrawBox();
	retryText->DrawOutText(spriteBrush, "RETRY", 5, DT_CENTER);

	exitBox->DrawBox();
	exitText->DrawOutText(spriteBrush, "EXIT", 4, DT_CENTER);
}

void GameOverScene::Clean()
{
	bg->DestroyTexture();

	gameOverText->CleanUpText();

	retryText->CleanUpText();
	retryBox->CleanUpLine();

	exitText->CleanUpText();
	exitBox->CleanUpLine();
}

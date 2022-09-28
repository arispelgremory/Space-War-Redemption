#include "SpaceshipScene.h"
#include "GameConfiguration.h"
#include "Physics.h"
#include <string>

SpaceshipScene::SpaceshipScene()
{
}

SpaceshipScene::~SpaceshipScene()
{
}

void SpaceshipScene::Initialize(IDirect3DDevice9* d3dDevice)
{
	// Generate random seed for random position of Collectible
	srand(time(0));
	// Initialize all the collectibles within the array
	for (int i = 0; i < *(&collectible + 1) - collectible; i++) {
		collectible[i] = new Collectible();
		collectible[i]->Init(d3dDevice, rand() % (WINDOW_WIDTH - COLLECTIBLE_SPRITEWIDTH), rand() % (WINDOW_HEIGHT - COLLECTIBLE_SPRITEHEIGHT));
	}

	// initialize collectibleLeft as the array size
	collectibleLeft = *(&collectible + 1) - collectible;

	player1->Init(d3dDevice, 100, 300);
	player2->Init(d3dDevice, 700, 300);

	// Initialized scoreboard
	player1HP->InitText(0, 0, 100, 50, 40, FW_NORMAL, D3DXVECTOR2(50.0f, 5.0f), D3DXVECTOR2(1.0f, 1.0f));
	player2HP->InitText(0, 0, 100, 50, 40, FW_NORMAL, D3DXVECTOR2(700.0f, 5.0f), D3DXVECTOR2(1.0f, 1.0f));
	line->InitLine(D3DXVECTOR2(0.0f, 50.0f), D3DXVECTOR2(WINDOW_WIDTH, 50.0f), D3DCOLOR_XRGB(255, 255, 255));
}

void SpaceshipScene::GetInput()
{
	// Player 1 movements
	if (input->IsKeyDown(DIK_W))
		player1->SetState(MOVE_FORWARD);
	if (input->IsKeyDown(DIK_A))
		player1->SetState(ROTATE_LEFT);
	if (input->IsKeyDown(DIK_S))
		player1->SetState(MOVE_BACKWARD);
	if (input->IsKeyDown(DIK_D))
		player1->SetState(ROTATE_RIGHT);

	// Player 2 movements
	if (input->IsKeyDown(DIK_UP))
		player2->SetState(MOVE_FORWARD);
	if (input->IsKeyDown(DIK_LEFT))
		player2->SetState(ROTATE_LEFT);
	if (input->IsKeyDown(DIK_DOWN))
		player2->SetState(MOVE_BACKWARD);
	if (input->IsKeyDown(DIK_RIGHT))
		player2->SetState(ROTATE_RIGHT);
}

void SpaceshipScene::Update(int framesToUpdate)
{
	if (collectibleLeft = 0 || (player1->GetHP() == 0 && player2->GetHP() == 0))
	{
		// change to game over scene

	}
	else
	{
		for (int i = 0; i < framesToUpdate; i++)
		{
			// Detect collision between player and player
			if (Physics::CircleColDetection(player1->GetSpaceship()->GetSpriteWidth() / 2, player2->GetSpaceship()->GetSpriteWidth() / 2,
				player1->GetSpaceship()->GetPosition() + player1->GetSpaceship()->GetSpriteCenter(), player2->GetSpaceship()->GetPosition() + player2->GetSpaceship()->GetSpriteCenter()))
			{
				player1->SetState(DAMAGED);
				player2->SetState(DAMAGED);

				// physic response
			}

			// Detection collision between player and collectible
			for (int i = 0; i < *(&collectible + 1) - collectible; i++)
			{
				if (collectible[i]->GetHP() > 0) {
					if (Physics::CircleColDetection(player1->GetSpaceship()->GetSpriteWidth() / 2, collectible[i]->GetCollectible()->GetSpriteWidth() / 2,
						player1->GetSpaceship()->GetPosition() + player1->GetSpaceship()->GetSpriteCenter(), collectible[i]->GetCollectible()->GetPosition() + collectible[i]->GetCollectible()->GetSpriteCenter())
						|| Physics::CircleColDetection(player2->GetSpaceship()->GetSpriteWidth() / 2, collectible[i]->GetCollectible()->GetSpriteWidth() / 2,
							player2->GetSpaceship()->GetPosition() + player2->GetSpaceship()->GetSpriteCenter(), collectible[i]->GetCollectible()->GetPosition() + collectible[i]->GetCollectible()->GetSpriteCenter()))
					{
						collectible[i]->SetIsCollide(true);
						collectibleLeft--;
					}
					collectible[i]->Update();
				}
			}


			player1->Update();
			player2->Update();

			player1->SetState(IDLE);
			player1->SetState(IDLE);
			player1->SetIsCollide(false);
			player2->SetIsCollide(false);
		}
	}
}

void SpaceshipScene::Render(LPD3DXSPRITE spriteBrush, IDirect3DDevice9* d3dDevice)
{
	// find out how to convert int to LPCTSTR properly
	player1HP->DrawOutText(spriteBrush, "Player 1 HP: " + player1->GetHP(), 13, DT_LEFT, D3DCOLOR_XRGB(255, 255, 255));
	player2HP->DrawOutText(spriteBrush, "Player 2 HP: " + player2->GetHP(), 13, DT_LEFT, D3DCOLOR_XRGB(255, 255, 255));
	line->DrawALine();

	player1->Render(spriteBrush);
	player2->Render(spriteBrush);

	for (int i = 0; i < *(&collectible + 1) - collectible; i++)
		collectible[i]->Render(spriteBrush);

}

void SpaceshipScene::Clean()
{
	player1->GetSpaceship()->DestroyTexture();
	player2->GetSpaceship()->DestroyTexture();

	for (int i = 0; i < *(&collectible + 1) - collectible; i++)
		collectible[i]->GetCollectible()->DestroyTexture();
}

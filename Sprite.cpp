#include "Sprite.h"
Sprite* Sprite::_instance = 0;

Sprite* Sprite::GetInstance()
{
    if (_instance == 0)
        _instance = new Sprite();
    return _instance;
}

void Sprite::InitSprite(int texWidth, int texHeight, int spriteWidth, int spriteHeight, D3DXVECTOR2 scaling,
                        float rotation, D3DXVECTOR2 position)
{
    this->textureWidth = texWidth;
    this->textureHeight = texHeight;
    this->spriteWidth = spriteWidth;
    this->spriteHeight = spriteHeight;

    this->scaling = scaling;
    this->rotation = rotation;
    this->position = position;

    colRect.left = 0;
    colRect.top = 0;
    colRect.right = colRect.left + spriteWidth;
    colRect.bottom = colRect.top + spriteHeight;

    animRect.left = 0;
    animRect.top = 0;
    animRect.right = colRect.left + spriteWidth;
    animRect.bottom = colRect.top + spriteHeight;

    spriteCenter = D3DXVECTOR2(spriteWidth / 2, spriteHeight / 2);
}

void Sprite::InitSprite(int texWidth, int texHeight, int texCol, int texRow, D3DXVECTOR2 scaling, float rotation,
                        float xPos, float yPos)
{
    this->textureWidth = texWidth;
    this->textureHeight = texHeight;
    this->textureCol = texCol;
    this->textureRow = texRow;
    this->spriteWidth = texWidth / texCol;
    this->spriteHeight = texHeight / texCol;

    this->scaling = scaling;
    this->rotation = rotation;
    this->position = D3DXVECTOR2(xPos, yPos);

    colRect.left = 0;
    colRect.top = 0;
    colRect.right = colRect.left + spriteWidth;
    colRect.bottom = colRect.top + spriteHeight;

    animRect.left = 0;
    animRect.top = 0;
    animRect.right = colRect.left + spriteWidth;
    animRect.bottom = colRect.top + spriteHeight;

    spriteCenter = D3DXVECTOR2(spriteWidth / 2, spriteHeight / 2);
}

void Sprite::CreateTexture(IDirect3DDevice9* d3d9Device, LPCSTR texturePath)
{
    HRESULT hr;
    hr = D3DXCreateTextureFromFile(d3d9Device, texturePath, &texture);
    if (FAILED(hr))
    {
        cout << "Create Texture failed!" << endl;
        return;
    }
}

void Sprite::Draw(LPD3DXSPRITE spriteBrush, D3DCOLOR colour)
{
    D3DXMatrixTransformation2D(&mat, NULL, 0.0, &scaling, &spriteCenter, rotation, &position);
    spriteBrush->SetTransform(&mat);
    spriteBrush->Draw(this->texture, &colRect, NULL, NULL, colour);
}

void Sprite::Draw(LPD3DXSPRITE spriteBrush)
{
    D3DXMatrixTransformation2D(&mat, NULL, 0.0, &scaling, &spriteCenter, rotation, &position);
    spriteBrush->SetTransform(&mat);
    HRESULT hr = spriteBrush->Draw(this->texture, &colRect, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));
    if (FAILED(hr))
    {
        cout << "Draw failed!" << endl;
        return;
    }
}

int Sprite::GetTextureWidth()
{
    return textureWidth;
}

void Sprite::SetTextureWidth(int textureWidth)
{
    this->textureWidth = textureWidth;
}

int Sprite::GetTextureHeight()
{
    return textureHeight;
}

void Sprite::SetTextureHeight(int textureHeight)
{
    this->textureHeight = textureHeight;
}

int Sprite::GetTextureRow()
{
    return textureRow;
}

void Sprite::SetTextureRow(int textureRow)
{
    this->textureRow = textureRow;
}

int Sprite::GetTextureCol()
{
    return textureCol;
}

void Sprite::SetTextureCol(int textureCol)
{
    this->textureCol = textureCol;
}

int Sprite::GetSpriteWidth()
{
    return spriteWidth;
}

void Sprite::SetSpriteWidth(int spriteWidth)
{
    this->spriteWidth = spriteWidth;
}

int Sprite::GetSpriteHeight()
{
    return spriteHeight;
}

void Sprite::SetSpriteHeight(int spriteHeight)
{
    this->spriteHeight = spriteHeight;
}

RECT Sprite::GetAnimRect()
{
    return animRect;
}

int Sprite::GetFrameCounter()
{
    return frameCounter;
}

void Sprite::SetFrameCounter(int frameCounter)
{
    this->frameCounter = frameCounter;
}

int Sprite::GetMaxFrame()
{
    return maxFrame;
}

void Sprite::SetMaxFrame(int maxFrame)
{
    this->maxFrame = maxFrame;
}

RECT Sprite::GetColRect()
{
    return colRect;
}

void Sprite::DestroyTexture()
{
    if (this->texture != NULL)
    {
        this->texture->Release();
        this->texture = NULL;
    }
}

Sprite::Sprite(int texWidth, int texHeight, int spriteWidth, int spriteHeight, D3DXVECTOR2 scaling, float rotation,
               D3DXVECTOR2 position)
{
    this->textureWidth = texWidth;
    this->textureHeight = texHeight;
    this->spriteWidth = spriteWidth;
    this->spriteHeight = spriteHeight;

    this->scaling = scaling;
    this->rotation = rotation;
    this->position = position;

    colRect.left = 0;
    colRect.top = 0;
    colRect.right = colRect.left + spriteWidth;
    colRect.bottom = colRect.top + spriteHeight;

    animRect.left = 0;
    animRect.top = 0;
    animRect.right = colRect.left + spriteWidth;
    animRect.bottom = colRect.top + spriteHeight;

    spriteCenter = D3DXVECTOR2(spriteWidth / 2, spriteHeight / 2);
}

Sprite::Sprite(int texWidth, int texHeight, int texCol, int texRow, D3DXVECTOR2 scaling, float rotation, float xPos,
               float yPos)
{
    this->textureWidth = texWidth;
    this->textureHeight = texHeight;
    this->textureCol = texCol;
    this->textureRow = texRow;
    this->spriteWidth = texWidth / texCol;
    this->spriteHeight = texHeight / texCol;

    this->scaling = scaling;
    this->rotation = rotation;
    this->position = D3DXVECTOR2(xPos, yPos);

    colRect.left = 0;
    colRect.top = 0;
    colRect.right = colRect.left + spriteWidth;
    colRect.bottom = colRect.top + spriteHeight;

    animRect.left = 0;
    animRect.top = 0;
    animRect.right = colRect.left + spriteWidth;
    animRect.bottom = colRect.top + spriteHeight;

    spriteCenter = D3DXVECTOR2(spriteWidth / 2, spriteHeight / 2);
}

Sprite::Sprite()
{
}

Sprite::~Sprite()
{
}

D3DCOLOR Sprite::GetColour()
{
    return colour;
}

void Sprite::SetColour(D3DCOLOR colour)
{
    this->colour = colour;
}

D3DXMATRIX* Sprite::GetTransformationMatrix()
{
    return &mat;
}

void Sprite::SetTransformationMatrix(D3DXMATRIX* mat)
{
    // this->mat = mat;
}

D3DXVECTOR2 Sprite::GetScaling()
{
    return scaling;
}

void Sprite::SetScaling(D3DXVECTOR2 scaling)
{
    this->scaling = scaling;
}

D3DXVECTOR2 Sprite::GetSpriteCenter()
{
    return spriteCenter;
}

void Sprite::SetSpriteCenter(D3DXVECTOR2 spriteCenter)
{
    this->spriteCenter = spriteCenter;
}

float Sprite::GetRotation()
{
    return rotation;
}

void Sprite::SetRotation(float rotation)
{
    this->rotation = rotation;
}

D3DXVECTOR2 Sprite::GetPosition()
{
    return position;
}

void Sprite::SetPosition(D3DXVECTOR2 position)
{
    this->position = position;
}

float Sprite::GetXPosition()
{
    return position.x;
}

void Sprite::SetXPosition(float xPos)
{
    this->position.x = xPos;
}

float Sprite::GetYPosition()
{
    return position.y;
}

void Sprite::SetYPosition(float yPos)
{
    this->position.y = yPos;
}

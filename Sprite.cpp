#include "Sprite.h"
Sprite* Sprite::_instance = 0;
Sprite* Sprite::GetInstance()
{
    if (_instance == 0)
        _instance = new Sprite();
    return _instance;
}

void Sprite::InitSpriteBrush()
{
    LPD3DXSPRITE spriteBrush;
    //	Create sprite. Study the documentation. 
    HRESULT hr = D3DXCreateSprite(D3DDEVICE->GetD3DDevice(), &spriteBrush);

    if (FAILED(hr)) 
    {
        cout << "Create sprite brush failed\n";
        return;
    }

    this->spriteBrush = spriteBrush;
}

LPD3DXSPRITE Sprite::GetSpriteBrsuh()
{
    return spriteBrush;
}

void Sprite::CreateTexture(LPCSTR texturePath)
{
    HRESULT hr;
    hr = D3DXCreateTextureFromFile(D3DDEVICE->GetD3DDevice(), texturePath, &texture);
    if (FAILED(hr)) {
        cout << "Create Texture failed!" << endl;
    }
}

void Sprite::Draw(D3DCOLOR colour)
{
    D3DXMatrixTransformation2D(mat, NULL, 0.0, &scaling, &spriteCenter, rotation, &position);
    spriteBrush->SetTransform(mat);
    spriteBrush->Draw(this->texture, &colRect, NULL, NULL, colour);

}

int Sprite::GetTextureWidth()
{
    return 0;
}

void Sprite::SetTextureWidth(int textureWidth)
{
}

int Sprite::GetTextureHeight()
{
    return 0;
}

void Sprite::SetTextureHeight(int textureHeight)
{
}

int Sprite::GetSpriteWidth()
{
    return 0;
}

void Sprite::SetSpriteWidth(int spriteWidth)
{
}

int Sprite::GetSpriteHeight()
{
    return 0;
}

void Sprite::SetSpriteHeight(int spriteHeight)
{
}

Sprite::Sprite(int texWidth, int texHeight, int spriteWidth, int spriteHeight, D3DXVECTOR2 scaling, float rotation, D3DXVECTOR2 position)
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

    spriteCenter = D3DXVECTOR2(spriteWidth / 2, spriteHeight / 2);
}

Sprite::Sprite()
{
}

Sprite::~Sprite()
{
}

D3DXMATRIX* Sprite::GetTransformationMatrix()
{
    return nullptr;
}

void Sprite::SetTransformationMatrix(D3DXMATRIX* mat)
{
}

D3DXVECTOR2 Sprite::GetScaling()
{
    return D3DXVECTOR2();
}

void Sprite::SetScaling(D3DXVECTOR2 scaling)
{
}

D3DXVECTOR2 Sprite::GetSpriteCenter()
{
    return D3DXVECTOR2();
}

void Sprite::SetSpriteCenter(D3DXVECTOR2 spriteCenter)
{
}

float Sprite::GetRotation()
{
    return 0.0f;
}

void Sprite::SetRotation(float rotation)
{
}

D3DXVECTOR2 Sprite::GetPosition()
{
    return D3DXVECTOR2();
}

void Sprite::SetPosition(D3DXVECTOR2 position)
{
}

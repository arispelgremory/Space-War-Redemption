#include "Sprite.h"
Sprite* Sprite::_instance = 0;
Sprite* Sprite::GetInstance()
{
    if (_instance == 0)
        _instance = new Sprite();
    return _instance;
}

void Sprite::CreateTexture(LPCSTR texturePath)
{
    HRESULT hr;
    hr = D3DXCreateTextureFromFile(D3DDEVICE->GetD3D9Device(), texturePath, &texture);
    if (FAILED(hr)) {
        cout << "Create Texture failed!" << endl;
        return;
    }
}

void Sprite::Draw(D3DCOLOR colour)
{
    D3DXMatrixTransformation2D(mat, NULL, 0.0, &scaling, &spriteCenter, rotation, &position);
    D3DDEVICE->GetSpriteBrush()->SetTransform(mat);
    D3DDEVICE->GetSpriteBrush()->Draw(this->texture, &colRect, NULL, NULL, colour);

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
    return mat;
}

void Sprite::SetTransformationMatrix(D3DXMATRIX* mat)
{
    this->mat = mat;
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

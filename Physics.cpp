#include "Physics.h"

bool Physics::CircleColDetection(int radiusA, int radiusB, D3DXVECTOR2 positionA, D3DXVECTOR2 positionB) {
    const D3DXVECTOR2 distance = positionA - positionB;
    if (radiusA + radiusB < D3DXVec2Length(&distance)) {
        return false;
    }
    return true;
}

bool Physics::RectColDetection(RECT RectA, RECT RectB) {
    return (RectA.bottom > RectB.top &&
        RectA.top < RectB.bottom &&
        RectA.left < RectB.right &&
        RectA.right > RectB.left);
}

Physics::Physics() {
    velocity = D3DXVECTOR2(0, 0);
    acceleration = D3DXVECTOR2(0, 0);

    engineForce = 0;
    mass = 0;
    gravity = 0;
    friction = 0;
}

Physics::~Physics() {
    velocity = D3DXVECTOR2(0, 0);
    acceleration = D3DXVECTOR2(0, 0);
    
    engineForce = 0;
    mass = 0;
    gravity = 0;
    friction = 0;
}

D3DXVECTOR2 Physics::GetVelocity() const {
    return velocity;
}

float Physics::GetXVelocity() const {
    return velocity.x;
}

float Physics::GetYVelocity() const {
    return velocity.y;
}

void Physics::SetVelocity(D3DXVECTOR2 velocity) {
    this->velocity = velocity;
}

void Physics::SetXVelocity(float val) {
    velocity.x = val;
}

void Physics::SetYVelocity(float val) {
    velocity.y = val;
}

D3DXVECTOR2 Physics::GetAcceleration() const {
    return velocity;
}

float Physics::GetXAcceleration() const {
    return velocity.x;
}

float Physics::GetYAcceleration() const {
    return acceleration.y;
}

void Physics::SetAcceleration(D3DXVECTOR2 acceleration) {
    this->acceleration = acceleration;
}

void Physics::SetXAcceleration(float val) {
    acceleration.x = val;
}

void Physics::SetYAcceleration(float val) {
    acceleration.y = val;
}

float Physics::GetEngineForce() const {
    return engineForce;
}
void Physics::SetEngineForce(float force)
{
    this->engineForce = force;
}

float Physics::GetMass() const
{
    return this->mass;
}
void Physics::SetMass(float mass)
{
    this->mass = mass;
}
    
float Physics::GetGravity() const 
{
    return this->gravity;
}
void Physics::SetGravity(float gravity)
{
    this->gravity = gravity;
}

float Physics::GetFriction() const
{
    return this->friction;
}
void Physics::SetFriction(float friction)
{
    this->friction = friction;
}

RECT Physics::GetCollisionRect() const
{
    return collisionRect;
}

void Physics::SetCollisionRect(RECT rect)
{
    this->collisionRect = rect;
}





#pragma once
#include "GameConfiguration.h"

class Physics {
    public:
		// Initialization
        Physics();
        ~Physics();

        // Circle Collision Detection - position = Midpoint of circle
        static bool CircleColDetection(int radiusA, int radiusB, D3DXVECTOR2 positionA, D3DXVECTOR2 positionB);
        // Rectangle Collision Detection
        static bool RectColDetection(RECT colRectA, RECT colRectB);

        static bool CircleCollisionResponse(D3DXVECTOR2 velocityA, D3DXVECTOR2 velocityB);

        static void CircleCollisionResponse(D3DXVECTOR2* circle1Acceleration, D3DXVECTOR2 *circle2Acceleration);

        static void CollideWallResponse(D3DXVECTOR2* spaceshipPosition, int spriteWidth, int windowWidth, int windowHeight);
    
        D3DXVECTOR2 GetVelocity() const;
        float GetXVelocity() const;
        float GetYVelocity() const;

        void SetVelocity(D3DXVECTOR2 velocity);
        void SetXVelocity(float val);
        void SetYVelocity(float val);

        D3DXVECTOR2 GetAcceleration() const;
        float GetXAcceleration() const;
        float GetYAcceleration() const;

        void SetAcceleration(D3DXVECTOR2 acceleration);
        void SetXAcceleration(float val);
        void SetYAcceleration(float val);

        float GetEngineForce() const;
        void SetEngineForce(float force);

        float GetMass() const;
        void SetMass(float force);
    
        float GetGravity() const;
        void SetGravity(float force);

        float GetFriction() const;
        void SetFriction(float force);

        RECT GetCollisionRect() const;
        void SetCollisionRect(RECT rect);
    
    private:
        D3DXVECTOR2 velocity;
        D3DXVECTOR2 acceleration;
    
        float engineForce;
        RECT collisionRect;
    
        float mass;
        float gravity;
        float friction;
    
};

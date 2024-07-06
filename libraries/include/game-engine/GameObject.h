#pragma once
#include<Box2D/b2_math.h>
#include<Box2D/Box2D.h>
#include"Physics.h"
#include"Animation.h"

class GameObject{
    public:
        GameObject();
        GameObject(PhysicsComponent p);
        GameObject(float x, float y);

        b2Vec3 color;
        b2Vec2 velocity;
        b2Vec2 pos;

        PhysicsComponent p;
        AnimationController animator;

        void InitializeAsBasicBox(b2Vec2 size);
        void setPos(b2Vec2 pos);
        void updateRect();
        void Destroy();
};

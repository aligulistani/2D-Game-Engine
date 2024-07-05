#pragma once
#include<Box2D/b2_math.h>
#include<Box2D/Box2D.h>
#include"Sprite.h"
#include"Physics.h"

class GameObject{
    public:
        GameObject();
        GameObject(PhysicsComponent p);
        GameObject(float x, float y);
        GameObject(float x, float y, Sprite t);

        b2Vec3 color;
        b2Vec2 velocity;
        b2Vec2 pos;

        PhysicsComponent p;
        Sprite sprite; // temp variable until an Entity class is made

        void InitializeAsBasicBox(b2Vec2 size);
        void setPos(b2Vec2 pos);
        void updateRect();
};

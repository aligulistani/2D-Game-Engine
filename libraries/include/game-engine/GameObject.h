#pragma once
#include<Box2D/b2_math.h>
#include"Sprite.h"

class GameObject{
    public:
        GameObject();
        GameObject(float x, float y);
        GameObject(float x, float y, Sprite t);

        b2Vec3 color;
        b2Vec2 velocity;
        b2Vec2 pos;

        Sprite sprite; // temp variable until an Entity class is made

        void setPos(b2Vec2 pos);
        void updateRect();
};

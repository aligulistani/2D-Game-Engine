#pragma once
#include<Box2D/b2_math.h>
#include"Sprite.h"

class GameObject{
    public:
        GameObject();
        GameObject(float x, float y);
        GameObject(float x, float y, Sprite t,bool physicsEnabled);
        GameObject(float x, float y,float w,float h, std::vector<int> c);

        b2Vec3 color;
        b2Vec2 velocity;
        b2Vec2 pos;

        void changeX(float x);
        void changeY(float y);
        void setVel(std::vector<float> vel);
        void setPos(std::vector<float> pos);
        void move(std::vector<float> vec);
        void updateRect();
};

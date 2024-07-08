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

        b2Vec2 world_pos;
        b2Vec2 rendering_size;
        b2Vec2 hitbox_size;
        float size_scale = 1.0f;

        PhysicsComponent p;
        AnimationController animator;
        SDL_FRect rendering_data;
        SDL_FRect Hitbox;

        void InitializeAsBasicBox(b2Vec2 size);
        void setPos(b2Vec2 pos);
        void update();
        SDL_FRect getRenderingData();
        void Destroy();
};

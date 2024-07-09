#pragma once
#include<Box2D/b2_math.h>
#include<Box2D/Box2D.h>
#include"Physics.h"
#include"Animation.h"


struct RenderData {
    //Data that is sent to the renderer to draw on the screen
    int type;
    SDL_FRect main_sprite;
    SDL_FRect physics_hitbox; // IF NULL, dont render
    SDL_FRect sprite_hitbox; // IF NULL, dont render
};

class GameObject{
    public:
        GameObject();

        b2Vec2 world_pos;
        b2Vec2 hitbox_size;
        float size_scale = 1.0f;

        AnimationController animator;
        RenderData rendering_data;
        
        void setWorldPosition(b2Vec2 pos);
        b2Vec2 GetWorldPosition();
        AnimationController* GetAnimator();
        void ScaleSize(float v);
        void InitializeAnimator();
        RenderData* getRenderingData();
        virtual void update();
        virtual void Destroy();
};

struct Entity : public GameObject{
    Entity();
    Entity(RB_DATA rigidbody_data);
    RigidBody* r_b;
    RigidBody* GetRigidbody();
    //void InitializeRigidBody(RB_DATA data);
    void update() override;
};


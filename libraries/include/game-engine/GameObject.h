#pragma once
#include<SDL2/SDL.h>
#include<game-engine/main.h>
#include<vector>
class GameObject{
    public:
        GameObject();
        GameObject(float x, float y);
        GameObject(float x, float y, SDL_Texture* texture,bool physicsEnabled);
        GameObject(float x, float y,float w,float h);
        void changeX(float x);
        void changeY(float y);
        void setVel(std::vector<float> vel);
        void setPos(std::vector<float> pos);
        // GameObject(float[2] coords, SDL_Texture* texure);
        // float[2] coords;
        std::vector<float>velocity;
        std::vector<float>pos;
        float w;
        float h;
        SDL_FRect rect;
       void updateRect();
       void move(std::vector<float> vec);
};
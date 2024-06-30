#pragma once
#include<SDL2/SDl.h>
// #include<game-engine/main.h>
#include<game-engine/Sprite.h>
#include<vector>
#include <Box2D/b2_body.h>
#include <Box2D/b2_polygon_shape.h>

class GameObject{
    public:
        GameObject();
        GameObject(float x, float y);
        GameObject(float x, float y, Sprite t,bool physicsEnabled);
        GameObject(b2Body* body);
        GameObject(float x, float y,float w,float h, std::vector<int> c);
        b2Body* GetBody();
        std::vector<int> color;
        Sprite sprite;
        void changeX(float x);
        void changeY(float y);
        void setVel(std::vector<float> vel);
        void setPos(std::vector<float> pos);
        // GameObject(float[2] coords, SDL_Texture* texure);
        // float[2] coords;
        std::vector<float>velocity;
        std::vector<float>pos;
        int type;
        float w;
        float h;
        b2Body* body;
        SDL_FRect rect;
       void updateRect();
       void move(std::vector<float> vec);
};

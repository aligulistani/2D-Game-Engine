#pragma once
#include<SDL2/SDL.h>
#include<game-engine/main.h>
class GameObject{
    public:
        GameObject(int x, int y);
        // GameObject(int[2] coords, SDL_Texture* texure);
        // int[2] coords;
        int x;
        int y;

};
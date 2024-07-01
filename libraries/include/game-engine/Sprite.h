#pragma once
#include<game-engine/main.h>
#include<SDL2/SDl.h>
//#include<game-engine/Texture.h>
//#include<game-engine/Animation.h>
#include<vector>

class Sprite{
    public:
        Sprite(const char* file_path, int frames);
        Sprite();
        Texture texture;
        Animation animation;
        SDL_Renderer* renderer;

};
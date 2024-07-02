#pragma once
#include"Texture.h"
#include"Animation.h"

class Sprite{
    public:
        Sprite(const char* file_path, int frames);
        Sprite();
        Texture texture;
        Animation animation;
        SDL_Renderer* renderer;
};
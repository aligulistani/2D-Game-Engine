#pragma once
#include"Texture.h"
#include"Animation.h"

class Sprite{
    public:
        Sprite(const char* file_path, const char* i);
        Sprite();
        const char* identifer;
        SDL_RendererFlip flip = SDL_FLIP_NONE;
        Texture texture;
};
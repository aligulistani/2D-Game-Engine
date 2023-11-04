#pragma once
#include<game-engine/main.h>
#include<SDL2/SDL_image.h>

class Texture{
    public:
        Texture();
        Texture(const char* file_path,SDL_Renderer* renderer);
        const char* file_path;
        SDL_Texture* image;
        int w,h;
};
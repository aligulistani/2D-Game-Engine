#pragma once
#include<SDL2/SDL.h>
class Texture{
    public:
        Texture();
        Texture(const char* file_path);
        const char* file_path;
        SDL_Texture* _rawImage;
        int w,h;
};

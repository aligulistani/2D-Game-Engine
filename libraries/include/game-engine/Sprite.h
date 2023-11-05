#pragma once
#include<game-engine/main.h>

class Sprite{
    public:
        Sprite(const char* file_path,SDL_Renderer* r);
        Sprite();
        std::vector<Texture> textures;
        // std::vector<Animation> animations;
        SDL_Renderer* renderer;
};
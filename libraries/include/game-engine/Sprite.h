#pragma once
// #include<game-engine/main.h>
#include<SDL2/SDl.h>
#include<game-engine/Texture.h>
#include<vector>
class Sprite : public Texture{
    public:
        Sprite(const char* file_path,SDL_Renderer* r);
        Sprite();
        std::vector<Texture> textures;
        Texture texture;
        // std::vector<Animation> animations;
        SDL_Renderer* renderer;
};
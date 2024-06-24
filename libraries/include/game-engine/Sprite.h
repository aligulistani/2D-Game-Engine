#pragma once
// #include<game-engine/main.h>
#include<SDL2/SDl.h>
#include<game-engine/Texture.h>
#include<game-engine/Animation.h>
#include<vector>
class Sprite{
    public:
        Sprite(const char* file_path,SDL_Renderer* r, int frames);
        Sprite();
        std::vector<Texture> textures;
        Texture texture;
        Animation animation;
        SDL_Renderer* renderer;
};
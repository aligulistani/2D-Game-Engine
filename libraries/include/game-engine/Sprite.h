#pragma once
#include"Texture.h"
#include"Animation.h"

class Sprite{
    public:
        Sprite(const char* file_path, int frames, const char* i);
        Sprite();
        const char* identifer;
        Texture texture;
        Animation animation;
};
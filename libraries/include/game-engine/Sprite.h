#pragma once
#include"Texture.h"

class Sprite{
    public:
        Sprite(const char* file_path, const char* i);
        Sprite();
        const char* identifer;
        Texture texture;
};
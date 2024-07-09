#pragma once
#include"Texture.h"

class SpriteSheet {
    public:
        SpriteSheet(const char* file_path);
        SpriteSheet();
        Texture texture;
};
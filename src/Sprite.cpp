#pragma once
#include<game-engine/main.h>

#include<game-engine/main.h>
namespace fs = std::filesystem;

Sprite::Sprite(const char* file_path, SDL_Renderer* r){
    this->raw_image = Texture(file_path, r);
    this->renderer = r;

    std::string path = file_path;
    for (const auto & entry : fs::directory_iterator(path))
        std::cout << entry.path() << std::endl;
};
Sprite::Sprite(){};


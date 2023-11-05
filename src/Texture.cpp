#pragma once
#include<game-engine/main.h>

Texture::Texture(){};
Texture::Texture(const char* file_path, SDL_Renderer* renderer){
    this->image = IMG_LoadTexture(renderer, file_path);
    SDL_QueryTexture(this->image,NULL,NULL,&this->w,&this->h);
};




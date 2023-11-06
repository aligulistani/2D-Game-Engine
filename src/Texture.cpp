
// #include<game-engine/main.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<game-engine/Texture.h>

Texture::Texture(){};
Texture::Texture(const char* file_path, SDL_Renderer* renderer){
    this->_rawImage = IMG_LoadTexture(renderer, file_path);
    SDL_QueryTexture(this->_rawImage,NULL,NULL,&this->w,&this->h);
};





#include<game-engine/main.h>


Texture::Texture(){};
Texture::Texture(const char* file_path){
    this->_rawImage = IMG_LoadTexture(GameEngine::renderer.get(), file_path);
    SDL_QueryTexture(this->_rawImage,NULL,NULL,&this->w,&this->h);
};




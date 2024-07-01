
#include<game-engine/main.h>

//#include<game-engine/Texture.h>

Texture::Texture(){};
Texture::Texture(const char* file_path){
    this->_rawImage = IMG_LoadTexture(GameEngine::r->get(), file_path);
    SDL_QueryTexture(this->_rawImage,NULL,NULL,&this->w,&this->h);
};




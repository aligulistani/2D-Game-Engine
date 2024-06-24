
// #include<game-engine/main.h>
#include<SDL2/SDL.h>
#include<game-engine/Sprite.h>

Sprite::Sprite(const char* file_path, SDL_Renderer* r, int frames){
    this->texture = Texture(file_path, r);
    this->renderer = r;
    this->animation = Animation(this->texture, this->renderer, frames);
};
Sprite::Sprite(){};


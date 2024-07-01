
// #include<game-engine/main.h>
#include<SDL2/SDL.h>
#include<game-engine/Sprite.h>

Sprite::Sprite(const char* file_path, int frames){
    this->texture = Texture(file_path);
    this->animation = Animation(this->texture, frames);
};
Sprite::Sprite(){};


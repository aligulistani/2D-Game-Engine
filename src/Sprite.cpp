
#include<game-engine/main.h>


Sprite::Sprite(const char* file_path, int frames){
    this->texture = Texture(file_path);
    this->animation = Animation(this->texture, frames);
};
Sprite::Sprite(){};


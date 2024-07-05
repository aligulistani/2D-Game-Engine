
#include<game-engine/main.h>


Sprite::Sprite(const char* file_path, int frames, const char* i){
    this->texture = Texture(file_path);
    this->identifer = i;
    this->animation = Animation(this->texture, frames);
};
Sprite::Sprite(){};


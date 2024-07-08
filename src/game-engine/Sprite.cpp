
#include<game-engine/main.h>


Sprite::Sprite(const char* file_path, const char* i){
    this->texture = Texture(file_path);
    this->identifer = i;
};
Sprite::Sprite(){};


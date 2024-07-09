
#include<game-engine/main.h>


SpriteSheet::SpriteSheet(const char* file_path){
    this->texture = Texture(file_path);
};
SpriteSheet::SpriteSheet(){};


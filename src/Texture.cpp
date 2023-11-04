#include<game-engine/main.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>

Texture::Texture(){};
Texture::Texture(const char* file_path, SDL_Renderer* renderer){
    this->image = IMG_LoadTexture(renderer, file_path);
    SDL_QueryTexture(this->image,NULL,NULL,&w,&h);
    int frames = 8;
	SDL_Rect source;
	int time_animation = SDL_GetTicks() / 150 % frames;

	source.x = (w/frames) * time_animation;
	source.y = 0;
	source.w = w/frames;
	source.h = h;

	SDL_Rect dest;
	// dest.x = e.rect.x;
	// dest.y = e.rect.y;
	dest.w = (w/frames)*2;
	dest.h = h*2;
};




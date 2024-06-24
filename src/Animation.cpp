// #include<game-engine/main.h>
#include <iostream>
#include<SDL2/SDL.h>
#include<game-engine/Animation.h>
#include <game-engine/Sprite.h>
Texture temp_t;

Animation::Animation(){
    this->frame_count = 0;
}

Animation::Animation(Texture t, SDL_Renderer* renderer, int frames){
    this->frame_count = frames;
	this->source.x = (t.w/this->frame_count) * this->animation_current_frame; // NEEDS TO BE UPDATED IN GAME LOOP
	this->source.y = 0;
	this->source.w = t.w/this->frame_count;
	this->source.h = t.h;
	texture = t;
	this->dest.x = 100; // TEMP VALUES, NEED TO BE VARIABLES
	this->dest.y = 100;
	this->dest.w = (t.w/this->frame_count);
	this->dest.h = t.h;

	this->animation_speed = animation_speed; // Default Speed is 150 milliseconds
};
void Animation::animate(){
    this->animation_current_frame = (SDL_GetTicks() / this->animation_speed) % this->frame_count;
	this->source.x = (texture.w/this->frame_count) * this->animation_current_frame;
	std::cout << this->source.x << std::endl;

}
void Animation::setAnimationSpeed(int s){
	// Sets the amount of time each frame of a sprite is displayed for
	// The time is measured in milliseconds
	this->animation_speed  = s;
}
// SDL_Rect* Animation::getSource(){
//     this->animation_current_frame = (SDL_GetTicks() / 150) % 8;
// }
// SDL_Rect* Animation::getDest(){
//     this->animation_current_frame = (SDL_GetTicks() / 150) % 8;
// }

int calculateFrames(int w){
    return 0;
}
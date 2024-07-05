#include<game-engine/main.h>


Texture temp_t;

Animation::Animation(){
    this->frame_count = 0;
}

Animation::Animation(Texture t, int frames){
    this->frame_count = frames;
	this->source.x = (t.w/this->frame_count) * this->animation_current_frame; // NEEDS TO BE UPDATED IN GAME LOOP
	this->source.y = 0;
	this->source.w = t.w/this->frame_count;
	this->source.h = t.h;
	this->texture = t;
	this->dest.x = 100; // TEMP VALUES, NEED TO BE VARIABLES
	this->dest.y = 100;
	this->dest.w = (t.w/this->frame_count);
	this->dest.h = t.h;

	this->animation_speed = animation_speed; // Default Speed is 150 milliseconds
};
int c = 0;
int animation_current_frame_2;
bool p;
void Animation::animate(){
	if(this->animation_current_frame==5 && p) {
		p = false;
		if(c>9) {
			c=0;
		}
		this->source.y = (this->texture.h/11) * c;
		//std::cout << this->source.x * c << std::endl;
		c++;
	}else if(this->animation_current_frame!=5){
		p = true;
	}
    this->animation_current_frame = (SDL_GetTicks() / this->animation_speed) % this->frame_count;
	this->source.x = (texture.w/this->frame_count) * this->animation_current_frame;
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
#include<game-engine/main.h>


AnimationController::AnimationController() {
	this->c_anim = new Animation();
	this->c_anim->animation_speed = 150;
	this->c_anim->frame_count = 1;
}

int cycle_counter = 0;

void AnimationController::runAnimation(const char* id, int cycles){
	nextFrame();
	Animation* last_anim = c_anim;


	if (this->c_anim->sprite.identifer != id) {//Check to see if the id of the given animation is the same one that is already being played
		for (int i = 0; i < this->animations.size(); i++) {
			if (this->animations[i].sprite.identifer == id) {
				this->c_anim = &this->animations[i];
			}
		}
	}

	if (cycles > 0) {
		//Force play one animation
		
	}

}

void AnimationController::nextFrame() {
	this->c_anim->animation_current_frame = (SDL_GetTicks() / this->c_anim->animation_speed) % this->c_anim->frame_count;
	this->c_anim->src.x = (c_anim->t.w / this->c_anim->frame_count) * this->c_anim->animation_current_frame;
}
SDL_Rect* AnimationController::getCurrentDrawFrame() {
	return &this->c_anim->src;
}

Texture temp_t;

Animation::Animation(){
    this->frame_count = 1;
	this->sprite = Sprite("./res/missing.png", "missing");
}

Animation::Animation(Sprite s, int frames){
    this->frame_count = frames;
	this->t = s.texture;
	
	this->sprite = s;

	this->src.x = 0;
	this->src.y = 0;
	this->src.w = t.w/this->frame_count;
	this->src.h = t.h;

	this->animation_speed = animation_speed; // Default Speed is 150 milliseconds
};

int c = 0;
bool p;

void Animation::animate(){
	//if(this->animation_current_frame==5 && p) {
	//	p = false;
	//	if(c>9) {
	//		c=0;
	//	}
	//	this->source.y = (this->texture.h/11) * c;
	//	//std::cout << this->source.x * c << std::endl;
	//	c++;
	//}else if(this->animation_current_frame!=5){
	//	p = true;
	//}
}
void Animation::setAnimationSpeed(int s){
	// Sets the amount of time each frame of a sprite is displayed for
	// The time is measured in milliseconds
	this->animation_speed  = s;
}

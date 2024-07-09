#include<game-engine/main.h>

Animation::Animation() {}
AnimationController::AnimationController() {
	this->c_anim = new Animation();
}
int cycle_counter = 0;
bool ch = true;
Animation* temp_anim;
int temp_cycle;

void AnimationController::countCycles(int c) {
	if (this->c_anim->animation_current_frame == this->c_anim->frame_count-1) {
		if (ch) {
			cycle_counter += 1;
		}
		ch = false;
	}
	else {
		ch = true;
	}

	if (cycle_counter == temp_cycle) {
		//this->c_anim = prev_forced_anim;
		this->forced_state = 0;
		cycle_counter = 0;
		ch = true;
		temp_cycle = -1;
	}
}
void AnimationController::AddAnimation(Animation a) {
	this->animations.push_back(a);
}

Animation* AnimationController::FindAnimation(const char* id) {
	for (int i = 0; i < this->animations.size(); i++) {
		if (this->animations[i].identifer == id) {
			return &this->animations[i];
		}
	}
}
void AnimationController::InitializeDefaultAnimation(const char* id) { // To-DO : NEED TO MAKE THIS PLAY WHEN NOTHING ELSE IS BEING PLAYED
	this->c_anim = this->FindAnimation(id);

}
void AnimationController::PlayAnimation(const char* id, int cycles){
	Animation* temp = new Animation();
	if (this->forced_state) {
		countCycles(cycles);
	}else {
		this->c_anim = this->FindAnimation(id);
		temp = c_anim;
	}

	if (cycles > 0) {
		temp_cycle = cycles;
		temp_anim = temp; // store the previously played animation before forced state
		this->forced_state = 1; // Put the animation controller into a force play state
	}
	nextFrame();
}


void AnimationController::nextFrame() {
	this->c_anim->animation_current_frame = (SDL_GetTicks() / this->c_anim->animation_speed) % this->c_anim->frame_count;
	this->c_anim->src.x = ((c_anim->sprite.texture.w / this->c_anim->frame_count) * this->c_anim->animation_current_frame);
}
SDL_Rect* AnimationController::getCurrentDrawFrame() {
	return &this->c_anim->src;
}

Texture temp_t;

Animation::Animation(SpriteSheet s, int frame_count, const char* identifer):
	frame_count(frame_count), sprite(s),identifer(identifer){
	
	this->src.x = 0;
	this->src.y = 0;
	this->src.w = (this->sprite.texture.w / this->frame_count) ;
	this->src.h = this->sprite.texture.h;
	this->animation_speed = 100; 
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

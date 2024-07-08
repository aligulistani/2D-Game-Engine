#include<game-engine/main.h>


AnimationController::AnimationController() {
	this->c_anim = new AnimationFrame();
	this->c_anim->animation_speed = 150;
	this->c_anim->frame_count = 1;
	this->AlignFrames();
}

int cycle_counter = 0;
bool ch = true;
AnimationFrame* temp_anim;
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
void AnimationController::runAnimation(const char* id, int cycles){
	AnimationFrame* temp = new AnimationFrame();
	if (this->forced_state) {
		countCycles(cycles);
	}else {
		for (int i = 0; i < this->animations.size(); i++) {
			if (this->animations[i].sprite.identifer == id) {
				this->c_anim = &this->animations[i];
				temp = c_anim;
			}
		}
	}

	if (cycles > 0) {
		temp_cycle = cycles;
		temp_anim = temp; // store the previously played animation before forced state
		this->forced_state = 1; // Put the animation controller into a force play state
	}
	nextFrame();
}

void AnimationController::AlignFrames() {

}

void AnimationController::nextFrame() {
	this->c_anim->animation_current_frame = (SDL_GetTicks() / this->c_anim->animation_speed) % this->c_anim->frame_count;

	//this->c_anim->src.w = this->c_anim->offset.w;
	//this->c_anim->src.h = this->c_anim->offset.h;j
	this->c_anim->src.x = ((c_anim->t.w / this->c_anim->frame_count) * this->c_anim->animation_current_frame);
}
SDL_Rect* AnimationController::getCurrentDrawFrame() {
	return &this->c_anim->src;
}

Texture temp_t;

AnimationFrame::AnimationFrame(){
    this->frame_count = 1;
	this->sprite = Sprite("./res/missing.png", "missing");
}
AnimationFrame::AnimationFrame(Sprite s, int frames) {
	this->frame_count = frames;
	this->t = s.texture;

	this->offset = b2Vec2(0.0f,0.0f);
	this->sprite = s;

	this->frame_center = b2Vec2((t.w / this->frame_count) / 2, t.h / 2);

	this->src.x = 0;
	this->src.y = 0;
	this->src.w = frame_center.x * 2;
	this->src.h = t.h;

	this->animation_speed = animation_speed; // Default Speed is 150 
};
AnimationFrame::AnimationFrame(Sprite s, int frames, b2Vec2 center){
    this->frame_count = frames;
	this->t = s.texture;
	
	this->offset = offset;
	this->sprite = s;

	this->frame_center = b2Vec2((t.w / this->frame_count) / 2, t.h / 2);

	this->src.x = 0;
	this->src.y = 0;
	this->src.w = frame_center.x*2;
	this->src.h = t.h;

	this->animation_speed = animation_speed; // Default Speed is 150 milliseconds
};

int c = 0;
bool p;

void AnimationFrame::animate(){
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
void AnimationFrame::setAnimationSpeed(int s){
	// Sets the amount of time each frame of a sprite is displayed for
	// The time is measured in milliseconds
	this->animation_speed  = s;
}

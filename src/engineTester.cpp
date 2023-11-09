#include<game-engine/main.h>

int WINDOW_WIDTH = 1280;
int WINDOW_HEIGHT = 720;
int max_fps = 120;
const char* window_title = "Game-Engine Test";

GameScene scene;
Display main_window;

GameObject square1;
GameObject square2;

void game_loop();
void clean_up();

float clock_temp_start;
EventHandler handler;

// NEED TO DO:
// - Refactor and clean up code
// - work on collision and physics classes
// - work on clock and time class
// - work on rendering pipline and structure
// - Make Sprite class able to handle more than one animation
int onGround;

int main(int argc,char **argv){
	GameEngine::initialize();

	main_window = Display(window_title,WINDOW_WIDTH,WINDOW_HEIGHT);
	scene = GameScene();

	square1 = GameObject(200.0f,100.0f,100.0f,100.0f);
	square2 = GameObject(1000.0f,100.0f,100.0f,100.0f);
	
	square1.setVel(std::vector<float>{0.5f,0.0f});
	square2.setVel(std::vector<float>{-0.5f,0.0f});
	onGround = 0;
	handler = EventHandler();
	GameEngine::set_main_game_loop(game_loop,-1, &handler);
	clean_up();
	return 0;		
}

float previous_tick_t = 0;
float current_tick_t = 0;
float tick_time;

Timer clock_ = Timer();

float speed = 0.2f;

float y = 0;

const float friction = 0.0001f;
const float air_drag = 0.0001f;

const float gravity = 0.1f;

bool second_bool = true;
void jump(){
	if(onGround ){
		square1.velocity[1] -= 0.5f;
		clock_.endTimer();
		clock_.open = true;
		onGround = 0;
		second_bool = true;
	}
}
float time_n;
void game_loop(){


	clock_.startTimer();
	if(handler.current_event.type == SDL_KEYDOWN){
		switch(handler.current_event.key.keysym.scancode){
			case SDL_SCANCODE_SPACE:
				jump(); 
			break;
		}
    }


	scene.addObjectToScene(&square1);
	scene.addObjectToScene(&square2);

	previous_tick_t = current_tick_t;
	current_tick_t = SDL_GetTicks();
	tick_time = current_tick_t - previous_tick_t;
	// std::cout << tick_time << std::endl; // How long every frame/tick takes in milliseconds

	std::vector<GameObject> test = scene.checkCollisions();


	if(square1.velocity[0] > 0.0f){
		square1.velocity[0] -= friction;
	}
	if(square1.velocity[0] < 0.0f){
		square1.velocity[0] += friction;
	}

	if(square2.velocity[0] > 0.0f){
		square2.velocity[0] -= friction;
	}
	if(square2.velocity[0] < 0.0f){
		square2.velocity[0] += friction;
	}

	if(square1.pos[1]+square1.rect.h >= WINDOW_HEIGHT && second_bool){
		square1.pos[1] = WINDOW_HEIGHT-square1.rect.h;
		second_bool = false;
		onGround = 1;
	}




	if(!onGround){
		square1.velocity[1] += 0.5*gravity*(clock_.previousTime/1000.0f)*(clock_.previousTime/1000.0f);
	}


	std::cout <<  "TIME: " << clock_.previousTime/1000.0f  << " VELOCITY: " << square1.velocity[1] << " onGround: " << onGround << std::endl;

	main_window.update();
	main_window.renderObjects(scene);
	scene.clearScene();
}
void clean_up(){
	main_window.cleanup();
}
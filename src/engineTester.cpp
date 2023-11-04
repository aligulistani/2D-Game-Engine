#include<SDL2/SDL.h>
#include<iostream>
#include<string>
#include<game-engine/main.h>


int WINDOW_WIDTH = 1280;
int WINDOW_HEIGHT = 720;
int max_fps = 120;
const char* window_title = "Game-Engine Test";

GameScene scene;
Display main_window;

GameObject rectangle;
Texture ninja;

void game_loop();
void clean_up();

int main(int argc,char **argv){
	GameEngine::initialize();

	main_window = Display(window_title,WINDOW_WIDTH,WINDOW_HEIGHT);
	rectangle = GameObject(0,0,100,100);
	scene = GameScene();

	ninja = Texture("./res/ninja/Idle.png",main_window.renderer);

	GameEngine::set_main_game_loop(game_loop,-1);
	clean_up();
	return 0;		
}
float velocity_x = 0.5f;
float velocity_y = 0.5f;
float speed = 0.5f;

void calculate_angle(){

}

void game_loop(){
	scene.addObjectToScene(rectangle);
	rectangle.rect.x += velocity_x;
	rectangle.rect.y += velocity_y;

	if(rectangle.rect.x+100 >= WINDOW_WIDTH){ // RIGHT WALL
		velocity_x = -speed;
		velocity_y = -speed;
	}else if(rectangle.rect.y+100 >= WINDOW_HEIGHT){ // BOTTOM WALL
		velocity_x = speed;
		velocity_y = -speed;
	}else if(rectangle.rect.x <= 0){ // LEFT WALL
		velocity_x = -speed;
		velocity_y = speed;
	}else if(rectangle.rect.y <= 0){ // TOP WALL
		velocity_x = -speed;
		velocity_y = speed;
	}

	main_window.update();
	main_window.renderObjects(scene);
	scene.clearScene();
}
void clean_up(){
	main_window.cleanup();
}
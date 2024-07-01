#include<game-engine/main.h>

void game_loop();

// Window Settings
int WINDOW_WIDTH = 1280;
int WINDOW_HEIGHT = 720;
int max_fps = 120;
const char* window_title = "Game-Engine Test";

Display main_window;

GameObject player;
Sprite blasphemous_sprite;

int main(int argc,char **argv){
	main_window = Display(window_title,WINDOW_WIDTH,WINDOW_HEIGHT);
	GameEngine::initialize(&main_window);

	blasphemous_sprite = Sprite("./res/blasphemous/test_sprite.png",6);
	player = Entity(200.0f, 100.0f, blasphemous_sprite, true);

	GameEngine::start_main_game_loop(game_loop,-1, &handler);
	return 0;
}

void game_loop(){

	ImGui::ShowDemoWindow();

	main_window.game_scene.addObjectToScene(&player);
}
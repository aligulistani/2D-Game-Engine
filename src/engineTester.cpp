#include<game-engine/main.h>
#include"imgui.h"

/*
 *
 *
 *
 *
 */


void game_loop();

// Window Settings
int WINDOW_WIDTH = 1280;
int WINDOW_HEIGHT = 720;
int max_fps = 120;
const char* window_title = "Game-Engine Test";

using namespace std;

EventHandler handler;
Display main_window;

GameObject player;
Sprite ninja_attack1;
Sprite ninja_attack2;
Sprite ninja_run;
Sprite ninja_death;
Sprite ninja_idle;

int main(int argc,char **argv){
	main_window = Display(window_title,WINDOW_WIDTH,WINDOW_HEIGHT);
	GameEngine::initialize(&main_window);

	ninja_attack1 = Sprite("./res/ninja/Attack1.png",main_window.renderer.get(), 6);
	ninja_attack2 = Sprite("./res/ninja/Attack2.png",main_window.renderer.get(), 6);
	ninja_run = Sprite("./res/ninja/Run.png",main_window.renderer.get(), 8);
	ninja_death = Sprite("./res/ninja/Death.png",main_window.renderer.get(), 6);
	ninja_idle = Sprite("./res/ninja/Idle.png",main_window.renderer.get(), 8);
	player = GameObject(200.0f, 100.0f, ninja_attack1, true);

	GameEngine::set_main_game_loop(game_loop,-1, &handler);
	return 0;
}
bool a;
void game_loop(){

	ImGui::ShowDemoWindow();

	ImGui::Begin("Animations");
	if(	ImGui::Button("Attack 1")) {
		player.sprite = ninja_attack1;
	}
	if(	ImGui::Button("Attack 2")) {
		player.sprite = ninja_attack2;
	}
	if(	ImGui::Button("Run")) {
		player.sprite = ninja_run;
	}
	if(	ImGui::Button("Death")) {
		player.sprite = ninja_death;
	}
	if(	ImGui::Button("Idle")) {
		player.sprite = ninja_idle;
	}
	if(ImGui::DragInt("Speed (ms)", &player.sprite.animation.animation_speed, 1.0f, 1, 1000, "%d")){}
	ImGui::End();

	main_window.game_scene.addObjectToScene(&player);

}
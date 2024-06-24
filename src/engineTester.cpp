#include<game-engine/main.h>
#include"imgui.h"
#include"imgui_impl_sdlrenderer2.h"
//#include"imgui_impl_opengl3.h"
#include"imgui_impl_sdl2.h"
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
Sprite ninja;

int main(int argc,char **argv){
	GameEngine::initialize(&main_window);
	main_window = Display(window_title,WINDOW_WIDTH,WINDOW_HEIGHT);

	ninja = Sprite("./res/ninja/Idle.png",main_window.renderer.get());
	player = GameObject(200.0f, 100.0f, ninja, true);

	handler = EventHandler();
	ImGui::CreateContext();
	ImGui_ImplSDL2_InitForSDLRenderer(main_window.window, main_window.renderer.get());
	ImGui_ImplSDLRenderer2_Init(main_window.renderer.get());

	//ImGui::GetIO().DisplaySize = ImVec2(1280, 720);
	GameEngine::set_main_game_loop(game_loop,-1, &handler);
	return 0;
}

static float f = 0.0f;
static int counter = 0;
bool show_another_window = false;
ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
void game_loop(){

	ImGui_ImplSDL2_NewFrame();
	ImGui_ImplSDLRenderer2_NewFrame();

	ImGui::NewFrame();
	ImGui::ShowDemoWindow();
	main_window.game_scene.addObjectToScene(&player);



	ImGui::Render();
	SDL_SetRenderDrawColor(main_window.renderer.get(), (Uint8)(clear_color.x * 255), (Uint8)(clear_color.y * 255), (Uint8)(clear_color.z * 255), (Uint8)(clear_color.w * 255));
	SDL_RenderClear(main_window.renderer.get());
	main_window.renderer.renderObjects();
	ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData(), main_window.renderer.get());
	SDL_RenderPresent(main_window.renderer.get());

}

#include<game-engine/main.h>

Display* window;

GameEngine::GameEngine(){};
void GameEngine::initialize(Display* w){
    //Initilialize SDL Festures
    window = w;

    // Initalize SDL2 Library

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        std::cout<<"SDL Succesfully Initialized!"<<std::endl;
    }else{
        std::cout<<"SDL failed to Initialize!"<<std::endl;
    }

    // Initialize ImGUI Library
    ImGui::CreateContext();
    ImGui_ImplSDL2_InitForSDLRenderer(window->window, window->renderer.get());
    ImGui_ImplSDLRenderer2_Init(window->renderer.get());
}


float previous_tick_t = 0;
float current_tick_t = 0;
float tick_time;

static float f = 0.0f;
static int counter = 0;
bool show_another_window = false;
ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);


void GameEngine::start_main_game_loop(void (*game_loop_func)(), int fps_cap){
    bool open = 1;

    //Start a game loop
    while(open){
        handler->pollEvents();

        ImGui_ImplSDL2_ProcessEvent(&handler->current_event); // Forward your event to backend
        ImGui_ImplSDL2_NewFrame();
        ImGui_ImplSDLRenderer2_NewFrame();
        ImGui::NewFrame();

        if(handler->current_event.type == SDL_QUIT){
            break;
        }
        previous_tick_t = current_tick_t;
        current_tick_t = SDL_GetTicks();
        tick_time = current_tick_t - previous_tick_t;

        window->renderer.update(&window->game_scene);
        window->game_scene.clearScene();

        game_loop_func();

        ImGui::Render();
        SDL_SetRenderDrawColor(window->renderer.get(), (Uint8)(clear_color.x * 255), (Uint8)(clear_color.y * 255), (Uint8)(clear_color.z * 255), (Uint8)(clear_color.w * 255));
        SDL_RenderClear(window->renderer.get());
        window->renderer.renderObjects();
        ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData(), window->renderer.get());
        SDL_RenderPresent(window->renderer.get());


        //window->update();
       // window->renderObjects(window->game_scene);
        //window->game_scene.clearScene();

    }
    ImGui_ImplSDLRenderer2_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();
    window->cleanup();

}
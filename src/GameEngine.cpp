#include<game-engine/main.h>


GameEngine::GameEngine(){};
void GameEngine::initialize(Display* w){


    // Initalize SDL2 Library
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        std::cout<<"SDL Succesfully Initialized!"<<std::endl;
    }else{
        std::cout<<"SDL failed to Initialize!"<<std::endl;
    }


    // Initialize ImGUI Library
    ImGui::CreateContext();
    ImGui_ImplSDL2_InitForSDLRenderer(w->window, GameEngine::renderer.get());
    ImGui_ImplSDLRenderer2_Init(GameEngine::renderer.get());

    // INIT GAME ENGINE CLASSES

    GameEngine::renderer = Renderer();
    GameEngine::window = w;
    GameEngine::handler = EventHandler();

}

void GameEngine::Shutdown() {
    ImGui_ImplSDLRenderer2_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();
    window->cleanup();
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
        // Event Handling
        handler.pollEvents();
        if(handler.current_event.type == SDL_QUIT){break;} // Close the window SDL_QUIT event is called
        ImGui_ImplSDL2_ProcessEvent(&handler.current_event);

        // ImGUI & SDL Function Calls
        ImGui_ImplSDL2_NewFrame();
        ImGui_ImplSDLRenderer2_NewFrame();
        ImGui::NewFrame();

        // Delta Time Calculations
        previous_tick_t = current_tick_t;
        current_tick_t = SDL_GetTicks();
        tick_time = current_tick_t - previous_tick_t;


        // Call the Logic Loop
        game_loop_func();

        // End of Tick Render Calls
        renderer.draw();

    }
    Shutdown();
}
#include<game-engine/main.h>


GameEngine::GameEngine(){};
Renderer GameEngine::renderer;
Display* GameEngine::window;
EventHandler GameEngine::handler;
PhysicsWorld GameEngine::main_physics_world;

b2Vec2 default_gravity(0.0f, 10.0f);
b2World c_world(default_gravity);

void GameEngine::initialize(Display* w){

    // INIT GAME ENGINE CLASSES
    GameEngine::window = w;
    renderer = Renderer();
    renderer.renderer = SDL_CreateRenderer(GameEngine::window->window,-1,0);
    GameEngine::handler = EventHandler();
    GameEngine::main_physics_world.physics_world = &c_world;

    // Initalize SDL2 Library
    if(SDL_Init(SDL_INIT_EVENTS|SDL_INIT_VIDEO) == 0 ){
        std::cout<<"SDL Succesfully Initialized!"<<std::endl;
    }else{
        std::cout<<"SDL failed to Initialize!"<<std::endl;
    }

    // Initialize ImGUI Library
    ImGui::CreateContext();
    ImGui_ImplSDL2_InitForSDLRenderer(w->window, GameEngine::renderer.get());
    ImGui_ImplSDLRenderer2_Init(GameEngine::renderer.get());
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

        //Physics Handling for every tick
        GameEngine::main_physics_world.NextStep();

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
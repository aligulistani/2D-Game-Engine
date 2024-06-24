#pragma once
#include <game-engine/Renderer.h>

class Display {
public:
	Display();
	Display(const char* title, int w, int h,Renderer renderer, SDL_Window* window);
	Display(const char* title, int w, int h);
    // SDL_Texture* loadTexture(const char* path);
    void cleanup();
	void renderObjects(GameScene scene);
	void update();
	void changeTitle(const char* title);
	void windowResize(int w, int h);
	// void render(Entity &e);
	void clear();
	Renderer renderer = Renderer();
	GameScene game_scene;
	SDL_Window* window;
	int counter = 0;
	int width;
	int height;
	const char* title;
	int fps_cap = -1;
private:
	// SDL_Window* window;
	// SDL_Renderer* renderer;
};

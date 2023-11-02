#pragma once
#include <iostream>
#include<SDL2/SDL.h>

class Display {
public:
	Display();
	Display(const char* title, int w, int h,SDL_Renderer* renderer, SDL_Window* window);
	Display(const char* title, int w, int h);
    // SDL_Texture* loadTexture(const char* path);
    void cleanup();
	void renderObjects();
	void update();
	void changeTitle(const char* title);
	void windowResize(int w, int h);
	// void render(Entity &e);
	void clear();
	SDL_Renderer* renderer;
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
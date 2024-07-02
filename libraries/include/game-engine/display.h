#pragma once

class Display {
	public:
		Display();
		Display(const char* title, int w, int h);

		SDL_Window* window;
		int width;
		int height;
		const char* title;

	    void cleanup();
		void update();
		void changeTitle(const char* title);
		void windowResize(int w, int h);
};

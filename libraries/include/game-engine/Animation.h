#pragma once
#include<game-engine/main.h>

class Animation {
    public:
        Animation(const char* file_path, SDL_Renderer* renderer, int frames, int animation_speed);
        std::vector<SDL_Texture*> frames;
        SDL_Rect dest;
        SDL_Rect source;
        const char* name;
        int frame_count;
        int animation_current_frame;
        int animation_speed = 150; // Default is at 150 milliseconds
        void loadAnimations(const char* folder_path);
        void setAnimationSpeed(int s);
        void animateOnEvent();

    
};
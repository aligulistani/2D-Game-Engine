#pragma once
#include<SDL2/SDl.h>
#include<game-engine/Texture.h>
#include<vector>


class Animation{
    public:
        Animation();
        Animation(Texture t, int frames);
        std::vector<SDL_Texture*> frames;
        SDL_Rect dest;
        SDL_Rect source;
        Texture texture;
        const char* name;
        int frame_count;
        int animation_current_frame = 0; // Show first aimation frame as a default value
        int animation_speed = 150; // Default is at 150 milliseconds
        void loadAnimations(const char* folder_path);
        void setAnimationSpeed(int s);
        void animateOnEvent();
        void animate();

};

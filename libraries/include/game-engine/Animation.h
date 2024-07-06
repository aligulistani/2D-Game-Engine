#pragma once
#include<game-engine/Sprite.h>
#include<vector>


class Animation{
    public:
        Animation();
        Animation(Sprite s, int frames);

        SDL_Rect src;
        Sprite sprite;

        Texture t;
        int frame_count;
        int animation_current_frame = 0; // Show first aimation frame as a default value
        int animation_speed = 150; // Default is at 150 milliseconds
        void setAnimationSpeed(int s);
        void animate();
};

struct AnimationController {
    float hx, hy;
    int forced_state = 0;

    b2Timer anim_timer;

    SDL_RendererFlip flip_state;
    AnimationController();
    Animation* c_anim; // The current animation that is played on screen
    std::vector<Animation> animations;
    void runAnimation(const char* id, int cycles);// Runs a certain animation for a given cycle count, if given NULL then it will play the animation indefinitely
    SDL_Rect* getCurrentDrawFrame();
    void nextFrame();
private:
    void countCycles(int c);
};
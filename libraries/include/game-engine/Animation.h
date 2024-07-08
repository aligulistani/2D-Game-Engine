#pragma once
#include<game-engine/Sprite.h>
#include<vector>

struct Vec4 {
    Vec4() :x(0.0f), y(0.0f), w(0.0f), h(0.0f) {}
    Vec4(float x,float y,float w,float h):x(x), y(y),w(w),h(h){}
    float x, y, w, h;
};

class AnimationFrame{
    public:
        AnimationFrame();
        AnimationFrame(Sprite s, int frames);
        AnimationFrame(Sprite s, int frames, b2Vec2 center);

        SDL_Rect src;
        Sprite sprite;

        b2Vec2 center;
        b2Vec2 offset;

        Texture t;
        int frame_count;
        b2Vec2 frame_center;
        int animation_current_frame = 0; // Show first aimation frame as a default value
        int animation_speed = 150; // Default is at 150 milliseconds
        void setAnimationSpeed(int s);
        void animate();
};

struct AnimationController {
    int forced_state = 0;

    b2Timer anim_timer;

    SDL_RendererFlip flip_state;
    AnimationController();
    AnimationFrame* c_anim; // The current animation that is played on screen
    std::vector<AnimationFrame> animations;
    void runAnimation(const char* id, int cycles);// Runs a certain animation for a given cycle count, if given NULL then it will play the animation indefinitely
    SDL_Rect* getCurrentDrawFrame();
    void nextFrame();
    void AlignFrames();
private:
    void countCycles(int c);
};
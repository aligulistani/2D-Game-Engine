#pragma once
#include<game-engine/SpriteSheet.h>
#include<vector>

//namespace Animation {
//    void createAnimation();
//}

struct Vec4 {
    Vec4() :x(0.0f), y(0.0f), w(0.0f), h(0.0f) {}
    Vec4(float x,float y,float w,float h):x(x), y(y),w(w),h(h){}
    float x, y, w, h;
};

class Animation {
public:
    Animation();
    Animation(SpriteSheet s, int frame_count, const char* identifer);

    int frame_count;
    SpriteSheet sprite;
    const char* identifer;

    SDL_Rect src;

    b2Vec2 frame_center;
    int animation_current_frame = 0; // Show first aimation frame as a default value
    int animation_speed; // Default is at 150 milliseconds

    void setAnimationSpeed(int s);
    void animate();
};


struct AnimationController {
    AnimationController();
    int forced_state = 0;
    b2Timer anim_timer;
    SDL_RendererFlip flip_state;
    Animation* c_anim; // The current animation that is played on screen
    std::vector<Animation> animations;

    void AddAnimation(Animation a);
    void PlayAnimation(const char* id, int cycles);// Runs a certain animation for a given cycle count, if given NULL then it will play the animation indefinitely
    void setAnimationCondition(const char* id, bool* condition);
    void InitializeDefaultAnimation(const char* id);
    Animation* FindAnimation(const char* id);
    SDL_Rect* getCurrentDrawFrame();
    void nextFrame();

private:
    void countCycles(int c);
};
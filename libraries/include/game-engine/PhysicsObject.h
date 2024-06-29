#pragma once
#include <Box2D/b2_world.h>

class PhysicsObject{
    public:
        PhysicsObject();
        b2World* world;
};

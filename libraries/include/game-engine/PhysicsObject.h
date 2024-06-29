#pragma once
#include <Box2D/Box2D.h>

class PhysicsObject{
    public:
        PhysicsObject();
        PhysicsObject(b2Vec2 pos, b2BodyType type, b2World* world, float density, float friction);
        b2BodyDef definition;
        b2Body* body;
        b2World* world;
        b2FixtureDef fixture_definition;
        float density;
        float friction;
        void updateAllPhysics();
};

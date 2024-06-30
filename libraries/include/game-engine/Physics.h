#pragma once
#include <Box2D/Box2D.h>
class Physics{
    public:
        void AppliedForce(const b2Vec2& force,  const b2Vec2& point,  b2Body* body);
        void AppliedForce(const b2Vec2& force,  b2Body* body);     
        void AppliedTorque(float torque, b2Body* body);
        void Jump(b2Body* body);  
};
#include <game-engine/Physics.h>
#include <game-engine/GameObject.h>
#include <Box2D/Box2D.h>
#include <iostream>

void Physics::AppliedForce(const b2Vec2& force, const b2Vec2& point, b2Body* body){
    b2Body* bodyObject = body;
    bodyObject->SetAwake(true);
    bodyObject->ApplyForce(force, point, true);
}
void Physics::AppliedForce(const b2Vec2& force, b2Body* body){
    b2Body* bodyObject = body;
    bodyObject->SetAwake(true);
    b2Vec2 point = b2Vec2(0.0,0.0);
    bodyObject->ApplyForce(force, point, true);
}
void Physics::AppliedTorque(float torque, b2Body* body){
    body->ApplyTorque(torque, true);
}
void Physics::Jump(b2Body* body){
    float impulse = body->GetMass() * -100;
    body->ApplyLinearImpulse(b2Vec2(0,impulse), b2Vec2(0,0), true);
}

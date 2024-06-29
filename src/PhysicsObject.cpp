/*
 * Main Physics Handler for the Game Enigne
 */

#include<game-engine/Physics.h>

Physics::PhysicsObject() {
    b2Vec2 gravity(0.0f, 10.0f); // DEFAULT VALUES
    world = new b2World(gravity);

};
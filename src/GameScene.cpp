// #include<game-engine/main.h>
#include<game-engine/GameScene.h>
#include<iostream>
#include<vector>

GameScene::GameScene(){}
// void GameScene::addArrayToScene(std::vector<GameObject> array){
//     for(int i=0;i<array.size();i++){
//         this->array.push_back(array[i]);
//     }
// }
void GameScene::addObjectToScene(GameObject* obj){
        this->activeObjects.push_back(obj);
}
void GameScene::clearScene(){
    this->activeObjects.clear();
    // this->array.clear();
}
// void GameScene::update(){
//     for(int i=0;i<this->activeObjects.size();i++){

//     }
// }

std::vector<GameObject> GameScene::checkCollisions(){
    // THIS FUNCTION HAS HARD CODED VALUES
    // THOSE NEED TO BE CHANGED 
    for(int i=0;i<this->activeObjects.size();i++){
        // Collision with a wall
        if(this->activeObjects[i]->pos[0]+this->activeObjects[i]->rect.w > 1280 || this->activeObjects[i]->pos[0] < 0){
            //COLLIDED WITH ONE OF THE SIDE WALLS
            this->activeObjects[i]->velocity[0] *= -1;
        }
        if(this->activeObjects[i]->pos[1]+this->activeObjects[i]->rect.h > 720 || this->activeObjects[i]->pos[1] < 0){
            //COLLIDED WITH ONE OF THE TOP AND BOTTOM WALL
            if(this->activeObjects[i]->velocity[1] > 0.0f){
                this->activeObjects[i]->velocity[1] = 0.0f;
            }
        }

        for(int j=0;j<this->activeObjects.size();j++){
            // Collision with other Game Objects
            if( this->activeObjects[i]->pos[0] + this->activeObjects[i]->rect.w > this->activeObjects[j]->pos[0] ){
                if( this->activeObjects[j]->pos[0] > this->activeObjects[i]->pos[0] ){
                    // Collision Detected in X-Coords!
                    std::cout << "X-AXIS Collision Detected!" << std::endl;
                    handleCollisions(this->activeObjects[i],this->activeObjects[j]);
                }
            }
        }
    }

    return std::vector<GameObject>{GameObject(),GameObject()};
}

void GameScene::handleCollisions(GameObject* obj_1,GameObject* obj_2){
    if(obj_1->velocity[0] > 0.0f && obj_2->velocity[0] < 0.0f){
        obj_1->velocity[0] *= -1.0f;
        obj_2->velocity[0] *= -1.0f;
    }

    if(obj_1->velocity[0] > 0.0f && obj_2->velocity[0] > 0.0f){
        if(obj_1->pos[0] < obj_2->pos[0]){
            obj_1->velocity[0] /= 2.0f;
            obj_2->velocity[0] *= 2.0f;
        }
    }

}
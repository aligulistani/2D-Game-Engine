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

std::vector<GameObject> checkCollisions(){
    // for(int i=0;i<this->activeObjects[i].size();i++){
    //     for(int j=0;j<this->activeObjects[i].size();j++){
    //         if(this->activeObjects[i].pos[0] < this->activeObjects[j].pos[0] < this->activeObjects[i].pos[0]+this->activeObjects[i].rect.w){
    //             // Collision Detected in X-Coords!
    //         }
    //     }
    // }
}
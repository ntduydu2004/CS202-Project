#include "lane.h"
using namespace std;

Lane::Lane(string TypeOfLane, short height){
    string Filename = "../data/image/Lane/" + TypeOfLane + ".png";
    Pic = LoadTexture(Filename.c_str());
    this->height = height;
}
Lane::~Lane(){
    UnloadTexture(Pic);
}
void Lane::Draw(Vector2 position){
    DrawTextureEx(Pic, position, 0.0f, 1.0f, WHITE);
}
short Lane::GetHeight(){
    return height;
}

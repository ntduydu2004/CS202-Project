#include "Obstacle.h"


Obstacle::Obstacle(int _x, int _y, int _speed, string texturePath) {
    x = _x;
    y = _y;
    speed = _speed;

    if (speed > 0) image = LoadTexture((texturePath + "/right.png").c_str());
    else image = LoadTexture((texturePath + "/left.png").c_str());
}

Obstacle::~Obstacle() {
    UnloadTexture(image);
}
#include "Obstacle.h"


Obstacle::Obstacle(Vector2 _position, int _speed, string texturePath) {
    position = _position;
    speed = _speed;

    if (speed > 0) image = LoadTexture((texturePath + "/right.png").c_str());
    else image = LoadTexture((texturePath + "/left.png").c_str());
}

Obstacle::~Obstacle() {
    UnloadTexture(image);
}

void Obstacle::draw() {
    DrawTextureEx(image, position, .0f, 1.0f, WHITE);
}
#pragma once
#include <bits/stdc++.h>
#include "raylib.h"
#include "player.h"
using namespace std;


class Obstacle {
private:
    Texture2D image;
    Vector2 position;
    int speed;

public:
    Obstacle(Vector2 _position, int _speed, string texturePath);
    ~Obstacle();
    void draw();
    virtual void soundOnImpact() = 0;

};

// Vehicle
//----------------------------------------------------------------------------------

class Truck: public Obstacle {
private:

public:
    Truck();
    ~Truck();
};


class Car: public Obstacle {
private:

public:
};

// Animal
//----------------------------------------------------------------------------------

class Bird: public Obstacle {
private:

public:

};

class Elephant: public Obstacle {
private:

public:

};

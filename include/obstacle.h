#pragma once
#include <bits/stdc++.h>
#include "raylib.h"
#include "Character.h"
using namespace std;


class Obstacle {
private:
    Texture2D image;
    int x, y;
    int speed;

public:
    Obstacle(int _x, int _y, int _speed, string texturePath);
    ~Obstacle();
    void soundOnImpact();

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

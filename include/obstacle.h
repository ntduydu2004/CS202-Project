#pragma once
#include <bits/stdc++.h>
#include "raylib.h"
using namespace std;
// Vehicle
//----------------------------------------------------------------------------------
class Vehicle{
protected:
    Texture2D left;
    Texture2D right;
public:
    
};

class Truck: public Vehicle{
private:

public:
};


class Car: public Vehicle{
private:

public:
};

// Animal
//----------------------------------------------------------------------------------
class Animal{
protected:
    Texture2D left;
    Texture2D right;
    
public:
    virtual void Draw(bool IsLeft) = 0;
};

class Bird{
private:

public:

};

class Elephant{
private:

public:

};

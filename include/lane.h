#pragma once
#include "object.h"
using namespace std;
class Lane{
private:
    Texture2D Pic;
    short height;
public:
    Lane(string TypeOfLane, short height);
    ~Lane();
    void Draw(Vector2 position);
    short GetHeight();
};

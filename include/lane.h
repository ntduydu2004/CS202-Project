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
class LaneFactory{
private:
    Lane lane[4] =
    {
        Lane("Road", 270),
        Lane("Pavement", 135),
        Lane("Stream", 135),
        Lane("Grass", 135),
    };
public:
    ~LaneFactory(){};
    void Draw(int type, Vector2 position);
    short GetHeight(int type);
};
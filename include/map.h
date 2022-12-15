#pragma once
#include <bits/stdc++.h>
#include "raylib.h"
#include "raygui.h"

using namespace std;

class Map {
private:
    Texture2D grass = LoadTexture("../data/image/Map/Full grass.png");
    Texture2D doublepath = LoadTexture("../data/image/Map/doublepath.png");
    Texture2D singlepath = LoadTexture("../data/image/Map/singlepath.png");
    Texture2D river = LoadTexture("../data/image/Map/river.png");
    Texture2D woodboard = LoadTexture("../data/image/Map/woodboard.png");

public:
    ~Map();
    void draw();
    void Restart();
};
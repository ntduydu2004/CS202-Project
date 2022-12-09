#pragma once
#include <bits/stdc++.h>
#include "raylib.h"
using namespace std;
class Character{
private:
    short moveside; // 0: up, 1: right, 2: down, 3: left
    short movestate;
    vector <vector <Texture2D>> moveState;
    string name;
    string namePlayer;
public:
    Character(string name);
    ~Character();
    void DrawInGame(Vector2 position);
    void DrawChoose(Vector2 position);
    void SetNamePlayer(string namePlayer);
};
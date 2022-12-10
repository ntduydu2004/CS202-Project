#pragma once
#include <bits/stdc++.h>
#include "raylib.h"
using namespace std;
class Character{
private:
    short moveside; // 0: up, 1: right, 2: down, 3: left
    short movestate;
    vector <vector <Texture2D>> moveState;
    string characterName;
public:
    Character() = default;
    Character(string name);
    ~Character();
    void DrawInGame(Vector2 position);
    void DrawChoose(Vector2 position);
};

class Player {
private:
    Vector2 position;
    string playerName;
    Character character;
public:
    void SetCharacter(Character _character);
    void SetNamePlayer(string playerName);
    void draw();
};

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
    Character();
    Character(string name);
    ~Character();
    const string& name();
    void DrawInGame(Vector2 position);
    void DrawChoose(Vector2 position);
    void move(int direction);
};

class Player {
private:
    Vector2 position;
    string playerName;
    Character *pCharacter;
public:
    void SetCharacter(Character *_pCharacter);
    void SetNamePlayer(string playerName);
    void setPosition(Vector2 _position);
    void draw();
    void move();
};

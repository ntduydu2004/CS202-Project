#pragma once
#include <bits/stdc++.h>
#include <vector>
#include <string.h>

#include "raylib.h"
#include "raygui.h"
#include "menu.h"
#include "obstacle.h"
#include "map.h"
#include "player.h"


class Game: public Menu {
private:
    Map gameMap;
    Player player;
    vector< Obstacle* > obstacleList;
    
public:
    Game(){};
    ~Game(){};
    void DrawPlayGame();
    void run(bool& close);
    void saveGame();
};
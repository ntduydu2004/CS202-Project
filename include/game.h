#pragma once
#include <bits/stdc++.h>

#include "raylib.h"
#include "raygui.h"
#include "menu.h"
#include "map.h"
#include "player.h"


class Game: public Menu {
private:
    
public:
    Game(){};
    ~Game(){};
    void run(bool& close);
    void SaveScore();
    void LoadScore();
};

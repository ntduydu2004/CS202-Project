#include "map.h"


Map::~Map() {
    UnloadTexture(grass);
    UnloadTexture(doublepath);
    UnloadTexture(singlepath);
    UnloadTexture(river);
}

void Map::draw() {
    ClearBackground(GetColor(0x052c46ff));
    DrawTextureEx(grass, (Vector2){-150, 0}, 0.0f, 1.0f, WHITE);
    DrawTextureEx(doublepath, (Vector2){-150, 0}, 0.0f, 1.0f, WHITE);
    DrawTextureEx(singlepath, (Vector2){-150, 300}, 0.0f, 1.0f, WHITE);
    DrawTextureEx(river, (Vector2){-150, 446}, 0.0f, 1.0f, WHITE);
}

void Map::Restart(){
    lane.clear();
    x = -10;
    int type = GetRandomValue(0, 3);
    if (type == 2) type = 3;
    short height = laneFactory.GetHeight(type);
    MovingLane x((Vector2){-10, GetScreenHeight() + 10}, type, height);
    lane.push_back(x);
    while (lane.back().isLastInScreen()){
        int type = GetRandomValue(0, 3);
        if (type == 2) type = 3;
        short height = laneFactory.GetHeight(type);
        MovingLane x((Vector2){-10, lane.back().position.y - height}, type, height);
        lane.push_back(x);
    }
}
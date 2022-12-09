#include "map.h"


Map::~Map() {
    UnloadTexture(grass);
    UnloadTexture(doublepath);
    UnloadTexture(singlepath);
    UnloadTexture(river);
}

void Map::drawMap() {
    BeginDrawing();
    ClearBackground(GetColor(0x052c46ff));
    DrawTextureEx(grass, (Vector2){-150, 0}, 0.0f, 1.0f, WHITE);
    DrawTextureEx(doublepath, (Vector2){-150, 0}, 0.0f, 1.0f, WHITE);
    DrawTextureEx(singlepath, (Vector2){-150, 300}, 0.0f, 1.0f, WHITE);
    DrawTextureEx(river, (Vector2){-150, 446}, 0.0f, 1.0f, WHITE);
    EndDrawing();
}
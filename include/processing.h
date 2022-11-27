#pragma once
#include "raylib.h"
#include "menu.h"
bool ModeProcessing();
bool LevelProcessing(int level);
bool GameProcessing(int level);
void LoadGame();
void SaveGame();
void SaveScore();
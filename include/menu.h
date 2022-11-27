#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "raylib.h"
#include "raygui.h"
void DrawMainMenu(Vector2& mousePosition, Vector2& touchPosition, short& indexMouse, short& menu, Rectangle rec_Role[], Texture2D background);
void DrawLevelMenu(Vector2& mousePosition, Vector2& touchPosition, short& indexMouse, short& menu, short& level, Rectangle rec_Role[], Texture2D background);
void DrawStatusMenu(); // appear if you lose/ want to exit
void DrawScoreboard(Vector2& mousePosition, Vector2& touchPosition, short& indexMouse, short& menu, Rectangle rec_Role[], Texture2D background, bool& ClearScoreBoard);
void DrawEnterNamePhase(Vector2& mousePosition, Vector2& touchPosition, short& indexMouse, short& indexTouch, short& menu, Rectangle rec_Role[], Texture2D background, char name[], short& id, short& frames);
void DrawLoadingPhase(); 
void DrawInstructions(Vector2& mousePosition, Vector2& touchPosition, short& indexMouse, short& menu, Rectangle rec_Role, Texture2D background);
#include "raylib.h"
#include <vector>
#include <map.h>
#include <string.h>
#include "processing.h"
#include "raygui.h"
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1000;
    const int screenHeight = 650;

    InitWindow(screenWidth, screenHeight, "CROSSING ROAD GAME - CS202 - GROUP 10");  
    Texture2D background = LoadTexture("../data/image/Background.png");     
    short menu = 0, id = 0;
    short frames = 0;
    bool close = false, clearScoreboard = true;
    Vector2 mousePosition;
    Vector2 touchPosition;
    char name[30] = "\0";
    short indexMouse = -1, indexTouch = -1, choose, level = 0;
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    Rectangle rec_Mode[] =
    {
        {GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 - 100, 300, 50},
        {GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 - 40, 300, 50},
        {GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 + 20, 300, 50},
        {GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 + 80, 300, 50},
        {GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 + 140, 300, 50},
    };
    Rectangle rec_Level[] =
    {
        {GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 - 100, 300, 50},
        {GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 - 40, 300, 50},
        {GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 + 20, 300, 50},
        {GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 + 80, 300, 50},
    };
    Rectangle rec_ScoreBoard[] =
    {
        {GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 + 140, 300, 50},
        {GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 + 200, 300, 50},
    };
    Rectangle rec_Instruction = {GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 + 80, 300, 50};
    Rectangle rec_EnterName[] =
    {
        {GetScreenWidth() / 2 - 400, GetScreenHeight() / 2 - 25, 800, 50},
        {GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 + 140, 300, 50},
        {GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 + 200, 300, 50},
    };
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        frames++;
        mousePosition = GetMousePosition();
        touchPosition = GetTouchPosition(0);
        SetMouseCursor(0);
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        switch (menu)
        {
            case 0:
            {
                DrawMainMenu(mousePosition, touchPosition, indexMouse, menu, rec_Mode, background);
                break;
            }
            case 1:
            {
                level = 0;
                DrawLevelMenu(mousePosition, touchPosition, indexMouse, menu, level, rec_Level, background);
                break;
            }
            // case 2:
            // {
                // load game 
            // }
            case 3:
            {
                DrawScoreboard(mousePosition, touchPosition, indexMouse, menu, rec_ScoreBoard, background, clearScoreboard);
                break;
            }
            case 4:
            {
                DrawInstructions(mousePosition, touchPosition, indexMouse, menu, rec_Instruction, background);
                break;
            }
            case 5:
            {
                close = true;
                break;
            }
            case 6:
            {
                DrawEnterNamePhase(mousePosition, touchPosition, indexMouse, indexTouch, menu, rec_EnterName, background, name, id, frames);
                break;
            }
            default:
            {
                menu = 0;
                break;
            }
        }
        // Draw
        //----------------------------------------------------------------------------------
        // DrawEnterNamePhase(mousePosition, touchPosition, indexMouse, indexTouch, menu, rec_EnterName, background, name, id);
        DrawFPS(10, 10);
        if (close) break;
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    UnloadTexture(background);
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

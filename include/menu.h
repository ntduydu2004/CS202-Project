#pragma once
#include <iostream>
#include <vector>
#include "raylib.h"
#include "raygui.h"
#include "player.h"
typedef enum{
    MAIN_MENU = 0,
    LEVEL_MENU = 1,
    LOAD_GAME_MENU = 2,
    SCOREBOARD = 3,
    INSTRUCTIONS = 4,
    EXIT_MENU = 5,
    ENTER_NAME = 6,
    CHOOSE_CHARACTER = 7,
    STATUS_MENU = 8,
    PLAY_GAME = 9,
}menuScreen;
class Menu {
protected:
    Font font=LoadFont("../data/font/AllTheWayToTheSun-o2O0.ttf");
    Texture2D background = LoadTexture("../data/image/Background/Background.png");
    Texture2D woodboard = LoadTexture("../data/image/Map/woodboard.png");
    Character character[3] = { Character("Ekko"), Character("Wukong"), Character("Samira")};

    short menu = 0, id = 0, characterIndex = 0; 
    short frames = 0;
    bool close = false, clearScoreBoard = true, touch = false;

    Vector2 mousePosition;
    Vector2 touchPosition;

    char playerName[30] = "\0";
    short indexMouse = -1, indexTouch = -1, choose, level = 0;

    Rectangle rec_Mode[5] =
    {
        {GetScreenWidth() / 2.0f - 150, GetScreenHeight() / 2.0f - 100, 300, 50},
        {GetScreenWidth() / 2.0f - 150, GetScreenHeight() / 2.0f - 40, 300, 50},
        {GetScreenWidth() / 2.0f - 150, GetScreenHeight() / 2.0f + 20, 300, 50},
        {GetScreenWidth() / 2.0f - 150, GetScreenHeight() / 2.0f + 80, 300, 50},
        {GetScreenWidth() / 2.0f - 150, GetScreenHeight() / 2.0f + 140, 300, 50},
    };
    Rectangle rec_Level[4] =
    {
        {GetScreenWidth() / 2.0f - 150, GetScreenHeight() / 2.0f - 100, 300, 50},
        {GetScreenWidth() / 2.0f - 150, GetScreenHeight() / 2.0f - 40, 300, 50},
        {GetScreenWidth() / 2.0f - 150, GetScreenHeight() / 2.0f + 20, 300, 50},
        {GetScreenWidth() / 2.0f - 150, GetScreenHeight() / 2.0f + 80, 300, 50},
    };
    Rectangle rec_ScoreBoard[2] =
    {
        {GetScreenWidth() / 2.0f - 150, GetScreenHeight() / 2.0f + 140, 300, 50},
        {GetScreenWidth() / 2.0f - 150, GetScreenHeight() / 2.0f + 200, 300, 50},
    };
    Rectangle rec_Instruction = {GetScreenWidth() / 2.0f - 150, GetScreenHeight() / 2.0f + 80, 300, 50};
    Rectangle rec_EnterName[3] =
    {
        {GetScreenWidth() / 2.0f - 400, GetScreenHeight() / 2.0f - 25, 800, 50},
        {GetScreenWidth() / 2.0f - 150, GetScreenHeight() / 2.0f + 140, 300, 50},
        {GetScreenWidth() / 2.0f - 150, GetScreenHeight() / 2.0f + 200, 300, 50},
    };
    Rectangle rec_ChooseCharacter[5] =
    {
        {GetScreenWidth() / 2.0f - 425, GetScreenHeight() / 2.0f - 150, 250, 250},
        {GetScreenWidth() / 2.0f - 125, GetScreenHeight() / 2.0f - 150, 250, 250},
        {GetScreenWidth() / 2.0f + 175, GetScreenHeight() / 2.0f - 150, 250, 250},
        {GetScreenWidth() / 2.0f - 150, GetScreenHeight() / 2.0f + 140, 300, 50},
        {GetScreenWidth() / 2.0f - 150, GetScreenHeight() / 2.0f + 200, 300, 50},
    };
    
public:
    ~Menu();
    void DrawMainMenu();
    void DrawLevelMenu();
    void DrawLoadGameWhilePlay(); // appear if you press T
    void DrawSaveGameWhilePlay(); // appear if you press L
    void DrawScoreboard();
    void DrawEnterNamePhase();
    void DrawInstructions();
    void DrawChooseCharacter(Character *&pChosenCharacter);
};
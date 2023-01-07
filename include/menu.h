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
    LOADING_PHASE = 10,
    LOSE_MENU = 11,
    LOAD_GAME_PLAY = 12,
    SAVE_GAME = 13,

}menuScreen;
class Menu {
protected:
    Font font=LoadFont("../data/font/AllTheWayToTheSun-o2O0.ttf");
    Texture2D background = LoadTexture("../data/image/Background/Background.png");
    Character character[3] =
    {
        Character("Ekko", (Vector2){GetScreenWidth() / 2 - 365, GetScreenHeight() / 2 - 125}),
        Character("Wukong", (Vector2){GetScreenWidth() / 2 - 65, GetScreenHeight() / 2 - 125}),
        Character("Samira", (Vector2){GetScreenWidth() / 2 + 235, GetScreenHeight() / 2 - 125}),
    };

    Map GameMap;

    short menu = 0, id = 0, characterIndex = 0; 
    short frames = 0, framesCharacter = 0;
    float acceleration = 0;
    bool touch = false, CanLoad = true, CanSave = true;

    Vector2 mousePosition;
    Vector2 touchPosition;
    char name[30] = "\0";
    string FilePath;
    short indexMouse = -1, indexTouch = -1, choose, level = 0;
    int score = 0;
    short TrafficLightSecond = 0;
    short TrafficLight = 0;
    short LoadingSecond = 239;
    bool isCollided = false;
    int record = 0;

    vector <int> ScoreList;
    vector <string> UserScoreList;
    vector <int> ScoreLevel;
    int numScore = 0;

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
    Rectangle rec_LoseMenu[2] =
    {
        {GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 + 140, 300, 50},
        {GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 + 200, 300, 50},
    };
      Rectangle rec_LoadGame[3] = 
    {
        {GetScreenWidth() / 2 - 400, GetScreenHeight() / 2 - 25, 800, 50},
        {GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 + 140, 300, 50},
        {GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 + 200, 300, 50},
    };
      Rectangle rec_LoadGameWhilePlay[4] =
    {
        {GetScreenWidth() / 2 - 400, GetScreenHeight() / 2 - 25, 800, 50},
        {GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 + 140, 300, 50},
        {GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 + 200, 300, 50},
        {GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 + 260, 300, 50},
    };
    Rectangle rec_SaveGame[4] = 
    {
        {GetScreenWidth() / 2 - 400, GetScreenHeight() / 2 - 25, 800, 50},
        {GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 + 140, 300, 50},
        {GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 + 200, 300, 50},
        {GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 + 260, 300, 50},
    };
    Rectangle rec_Exit[4] =
    {
        {GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 - 100, 300, 50},
        {GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 - 40, 300, 50},
        {GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 + 20, 300, 50},
        {GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 + 80, 300, 50},
    };
    
public:
    ~Menu();
    void DrawMainMenu();
    void DrawLevelMenu();
    void DrawLoadGame();
    void DrawExitMenu();
    void DrawLoadGameWhilePlay(); // appear if you press T
    void DrawSaveGame(); // appear if you press L
    void DrawEnterNamePhase();
    void Restart();
    void SaveGame();
    void LoadGame();
    void DrawLoseMenu();
    void DrawLoadingPhase();
    void DrawChooseCharacter();
};

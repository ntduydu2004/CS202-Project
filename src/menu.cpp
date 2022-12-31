#define RAYGUI_IMPLEMENTATION
#include "menu.h"
using namespace std;
Menu::~Menu(){
    UnloadTexture(background);
}
void Menu::DrawMainMenu(){
    if (CheckCollisionPointRec(mousePosition, rec_Mode[0]))
        {indexMouse = 1; SetMouseCursor(4);}
    else if (CheckCollisionPointRec(mousePosition, rec_Mode[1]))
        {indexMouse = 2; SetMouseCursor(4);}
    else if (CheckCollisionPointRec(mousePosition, rec_Mode[2]))
        {indexMouse = 3; SetMouseCursor(4);}
    else if (CheckCollisionPointRec(mousePosition, rec_Mode[3]))
        {indexMouse = 4; SetMouseCursor(4);}
    else if (CheckCollisionPointRec(mousePosition, rec_Mode[4]))
        {indexMouse = 5; SetMouseCursor(4);}
    else
        indexMouse = 0;
    if (IsMouseButtonPressed(0))
    {
        for (int i = 0; i < 5; i ++){
            if (CheckCollisionPointRec(mousePosition, rec_Mode[i])){
                menu = i + 1;
                break;
            }
        }
    }

    BeginDrawing();
    ClearBackground(GetColor(0x052c46ff));
    DrawTextureEx(background, (Vector2){-150, 0}, 0.0f, 1.2f, WHITE);
    DrawRectangle(rec_Mode[0].x, rec_Mode[0].y, rec_Mode[0].width, rec_Mode[0].height, BROWN);
    DrawRectangle(rec_Mode[1].x, rec_Mode[1].y, rec_Mode[1].width, rec_Mode[1].height, BROWN);
    DrawRectangle(rec_Mode[2].x, rec_Mode[2].y, rec_Mode[2].width, rec_Mode[2].height, BROWN);
    DrawRectangle(rec_Mode[3].x, rec_Mode[3].y, rec_Mode[3].width, rec_Mode[3].height, BROWN);
    DrawRectangle(rec_Mode[4].x, rec_Mode[4].y, rec_Mode[4].width, rec_Mode[4].height, BROWN);
    if (indexMouse > 0){
        DrawRectangle(rec_Mode[indexMouse - 1].x, rec_Mode[indexMouse - 1].y, rec_Mode[indexMouse - 1].width, rec_Mode[indexMouse - 1].height, Fade(DARKBROWN, 0.3f));
        DrawRectangleLines(rec_Mode[indexMouse - 1].x, rec_Mode[indexMouse - 1].y, rec_Mode[indexMouse - 1].width, rec_Mode[indexMouse - 1].height, RAYWHITE);
    }

    DrawTextEx(font, "CROSSING ROAD", (Vector2){GetScreenWidth() / 2.0f - 210, GetScreenHeight() / 2.0f - 230}, 70, 2, DARKBLUE);
    DrawText(" PLAY ", GetScreenWidth() / 2.0f - 50, GetScreenHeight() / 2.0f - 90, 30, RAYWHITE);
    DrawText("LOAD GAME", GetScreenWidth() / 2.0f - 85, GetScreenHeight() / 2.0f - 30, 30, RAYWHITE);
    DrawText("SCOREBOARD", GetScreenWidth() / 2.0f - 100, GetScreenHeight() / 2.0f + 30, 30, RAYWHITE);
    DrawText("INSTRUCTION", GetScreenWidth() / 2.0f - 105, GetScreenHeight() / 2.0f + 90, 30, RAYWHITE);
    DrawText(" EXIT ", GetScreenWidth() / 2.0f - 50, GetScreenHeight() / 2.0f + 150, 30, RAYWHITE);
    EndDrawing();
}
void Menu::DrawLevelMenu(){
    if (CheckCollisionPointRec(mousePosition, rec_Level[0]))
        {indexMouse = 1; SetMouseCursor(4);}
    else if (CheckCollisionPointRec(mousePosition, rec_Level[1]))
        {indexMouse = 2; SetMouseCursor(4);}
    else if (CheckCollisionPointRec(mousePosition, rec_Level[2]))
        {indexMouse = 3; SetMouseCursor(4);}
    else if (CheckCollisionPointRec(mousePosition, rec_Level[3]))
        {indexMouse = 4; SetMouseCursor(4);}
    else
        indexMouse = 0;
    if (IsMouseButtonPressed(0))
    {
        for (int i = 0; i < 4; i ++){
            if (CheckCollisionPointRec(mousePosition, rec_Level[i])){
                level = i + 1;
                break;
            }
        }
        if (level == 4) menu = 0;
        else if (level == 0) menu = 1;
        else menu = 6;
    }
    BeginDrawing();
    ClearBackground(GetColor(0x052c46ff));
    DrawTextureEx(background, (Vector2){-150, 0}, 0.0f, 1.2f, WHITE);
    DrawRectangle(rec_Level[0].x, rec_Level[0].y, rec_Level[0].width, rec_Level[0].height, BROWN);
    DrawRectangle(rec_Level[1].x, rec_Level[1].y, rec_Level[1].width, rec_Level[1].height, BROWN);
    DrawRectangle(rec_Level[2].x, rec_Level[2].y, rec_Level[2].width, rec_Level[2].height, BROWN);
    DrawRectangle(rec_Level[3].x, rec_Level[3].y, rec_Level[3].width, rec_Level[3].height, BROWN);
    if (indexMouse > 0){
        DrawRectangle(rec_Level[indexMouse - 1].x, rec_Level[indexMouse - 1].y, rec_Level[indexMouse - 1].width, rec_Level[indexMouse - 1].height, Fade(DARKBROWN, 0.3f));
        DrawRectangleLines(rec_Level[indexMouse - 1].x, rec_Level[indexMouse - 1].y, rec_Level[indexMouse - 1].width, rec_Level[indexMouse - 1].height, RAYWHITE);
    }
    

    DrawTextEx(font, "CHOOSE YOUR LEVEL", (Vector2){GetScreenWidth() / 2.0f - 250, GetScreenHeight() / 2.0f - 230}, 70, 2, MAROON);
    DrawText(" EASY ", GetScreenWidth() / 2.0f - 50, GetScreenHeight() / 2.0f - 90, 30, RAYWHITE);
    DrawText("MEDIUM", GetScreenWidth() / 2.0f - 60, GetScreenHeight() / 2.0f - 30, 30, RAYWHITE);
    DrawText(" HARD ", GetScreenWidth() / 2.0f - 50, GetScreenHeight() / 2.0f + 30, 30, RAYWHITE);
    DrawText(" BACK ", GetScreenWidth() / 2.0f - 50, GetScreenHeight() / 2.0f + 90, 30, RAYWHITE);
    EndDrawing();
}
void Menu::DrawScoreboard(){
    if (CheckCollisionPointRec(mousePosition, rec_ScoreBoard[0]))
        {indexMouse = 1; SetMouseCursor(4);}
    else if (CheckCollisionPointRec(mousePosition, rec_ScoreBoard[1]))
        {indexMouse = 2; SetMouseCursor(4);}
    else 
        indexMouse = 0;
    
    if (IsMouseButtonPressed(0))
    {
        if (CheckCollisionPointRec(mousePosition, rec_ScoreBoard[0])) clearScoreBoard = 1;
        if (CheckCollisionPointRec(mousePosition, rec_ScoreBoard[1])) menu = 0;
    }
    BeginDrawing();
    ClearBackground(GetColor(0x052c46ff));
    DrawTextureEx(background, (Vector2){-150, 0}, 0.0f, 1.2f, WHITE);
    DrawRectangle(rec_ScoreBoard[0].x, rec_ScoreBoard[0].y, rec_ScoreBoard[0].width, rec_ScoreBoard[0].height, BROWN);
    DrawRectangle(rec_ScoreBoard[1].x, rec_ScoreBoard[1].y, rec_ScoreBoard[1].width, rec_ScoreBoard[1].height, BROWN);
    if (indexMouse) {
        DrawRectangle(rec_ScoreBoard[indexMouse - 1].x, rec_ScoreBoard[indexMouse - 1].y, rec_ScoreBoard[indexMouse - 1].width, rec_ScoreBoard[indexMouse - 1].height, Fade(DARKBROWN, 0.3f));
        DrawRectangleLines(rec_ScoreBoard[indexMouse - 1].x, rec_ScoreBoard[indexMouse - 1].y, rec_ScoreBoard[indexMouse - 1].width, rec_ScoreBoard[indexMouse - 1].height, RAYWHITE);
    }
    if (clearScoreBoard){
        DrawRectangle(GetScreenWidth() / 2.0f - 325, GetScreenHeight() / 2.0f - 210, 645, 65,LIME);
        DrawTextEx(font,"THERE IS NO ACHIEVEMENT HERE!!", (Vector2){GetScreenWidth() / 2.0f - 320, GetScreenHeight() / 2.0f - 200}, 50, 2, MAROON);
    }
    DrawText(" CLEAR ", GetScreenWidth() / 2.0f - 60, GetScreenHeight() / 2.0f + 150, 30, RAYWHITE);
    DrawText(" BACK ", GetScreenWidth() / 2.0f - 50, GetScreenHeight() / 2.0f + 210, 30, RAYWHITE);
    EndDrawing();
}
void Menu::DrawInstructions(){
    if (CheckCollisionPointRec(mousePosition, rec_Instruction))
        {indexMouse = 1; SetMouseCursor(4);}
    else 
        indexMouse = 0;
    if (IsMouseButtonPressed(0))
    {
        if (CheckCollisionPointRec(mousePosition, rec_Instruction)) menu = 0;
    }
    BeginDrawing();
    ClearBackground(GetColor(0x052c46ff));
    DrawTextureEx(background, (Vector2){-150, 0}, 0.0f, 1.2f, WHITE);
    DrawTextureEx(woodboard,(Vector2){GetScreenWidth() / 2.0f - 363, GetScreenHeight() / 2.0f - 237},0.0f, 0.7f, WHITE);
    DrawTextureEx(woodboard,(Vector2){GetScreenWidth() / 2.0f - 363, GetScreenHeight() / 2.0f - 187},0.0f, 0.7f, WHITE);
    DrawRectangle(rec_Instruction.x, rec_Instruction.y, rec_Instruction.width, rec_Instruction.height, BROWN);
    if (indexMouse){
        DrawRectangle(rec_Instruction.x, rec_Instruction.y, rec_Instruction.width, rec_Instruction.height, Fade(DARKBROWN, 0.3f));
        DrawRectangleLines(rec_Instruction.x, rec_Instruction.y, rec_Instruction.width, rec_Instruction.height, RAYWHITE);
    }
    DrawTextEx(font,"USE W, A, S, D TO MOVE ", (Vector2){GetScreenWidth() / 2.0f - 350, GetScreenHeight() / 2.0f - 230}, 30, 2, YELLOW);
    DrawTextEx(font,"STAY AWAY FROM OBSTACLES !!! ",(Vector2){GetScreenWidth() / 2.0f - 350, GetScreenHeight() / 2.0f - 200}, 30, 2, YELLOW);
    DrawTextEx(font,"SURVIVE AS LONG AS POSSIBLE ^^ ",(Vector2){GetScreenWidth() / 2.0f - 350, GetScreenHeight() / 2.0f - 170}, 30, 2, YELLOW);
    DrawText(" BACK ", GetScreenWidth() / 2.0f - 50, GetScreenHeight() / 2.0f + 90, 30, RAYWHITE);
    EndDrawing();
}
void Menu::DrawEnterNamePhase(){
    if (CheckCollisionPointRec(mousePosition, rec_EnterName[0])) {
        indexMouse = 1;
        SetMouseCursor(2);
    }
    else if (CheckCollisionPointRec(mousePosition, rec_EnterName[1])) {
        indexMouse = 2;
        SetMouseCursor(4);
    }
    else if (CheckCollisionPointRec(mousePosition, rec_EnterName[2])) {
        indexMouse = 3;
        SetMouseCursor(4);
    }
    else 
        indexMouse = 0;


    if (IsKeyPressed(KEY_ESCAPE)) menu = LEVEL_MENU;
    if (IsMouseButtonPressed(0)) {
        if (CheckCollisionPointRec(mousePosition, rec_EnterName[0])) {
            frames = 0;
            indexTouch = 1;
        }
        else if (CheckCollisionPointRec(mousePosition, rec_EnterName[1])) {
            indexTouch = 0;
            menu = 7; // enter to choose character
        }
        else if (CheckCollisionPointRec(mousePosition, rec_EnterName[2]))
            menu = 1;
        else {
            indexTouch = 0;
            frames = 100;
        }
    }
    if (indexTouch == 1) {
        int key = GetCharPressed();
        while (key > 0) {
            if ((key >= 32) && (key <= 125) && (id <= 25)) {
                name[id] = (char)key;
                name[id + 1] = '\0';
                id++;
            }
            key = GetCharPressed();
        }
        if (IsKeyPressed(KEY_BACKSPACE)) {
            id--;
            if (id < 0) id = 0;
            name[id] = '\0';
        }
    }
    if (IsKeyPressed(KEY_ENTER)) {
        indexTouch = 0;
        menu = 7;
    }
    BeginDrawing();
    ClearBackground(GetColor(0x052c46ff));
    DrawTextureEx(background, (Vector2){-150, 0}, 0.0f, 1.2f, WHITE);
    DrawRectangle(rec_EnterName[0].x, rec_EnterName[0].y, rec_EnterName[0].width, rec_EnterName[0].height, DARKBLUE);
    DrawRectangle(rec_EnterName[1].x, rec_EnterName[1].y, rec_EnterName[1].width, rec_EnterName[1].height, BLUE);
    DrawRectangle(rec_EnterName[2].x, rec_EnterName[2].y, rec_EnterName[2].width, rec_EnterName[2].height, BLUE);
    if (indexMouse) {
        DrawRectangle(rec_EnterName[indexMouse - 1].x, rec_EnterName[indexMouse - 1].y, rec_EnterName[indexMouse - 1].width, rec_EnterName[indexMouse - 1].height, Fade(DARKBLUE, 0.3f));
        DrawRectangleLines(rec_EnterName[indexMouse - 1].x, rec_EnterName[indexMouse - 1].y, rec_EnterName[indexMouse - 1].width, rec_EnterName[indexMouse - 1].height, DARKBLUE);
    }
    DrawText("ENTER YOUR NAME", GetScreenWidth() / 2 - 400, GetScreenHeight() / 2 - 60, 30, MAROON);
    DrawText(name, rec_EnterName[0].x + 10, rec_EnterName[0].y + 10, 30, RAYWHITE);
    if ((frames/15)%2 == 0 && indexTouch == 1) DrawText("|", rec_EnterName[0].x + 13 + MeasureText(name, 30), rec_EnterName[0].y + 10, 30, RAYWHITE);
    DrawText(" PLAY ", GetScreenWidth() / 2 - 50, GetScreenHeight() / 2 + 150, 30, RAYWHITE);
    DrawText(" BACK ", GetScreenWidth() / 2 - 50, GetScreenHeight() / 2 + 210, 30, RAYWHITE);
    EndDrawing();
}
void Menu::DrawChooseCharacter(Character *&pChosenCharacter){
    indexMouse = 0;
    for (int i = 0; i <= 4; ++i)
        if (CheckCollisionPointRec(mousePosition, rec_ChooseCharacter[i])) {
            indexMouse = i + 1;
            SetMouseCursor(4);
            break;
        }
    
    if (IsKeyPressed(KEY_ESCAPE)) menu = ENTER_NAME;
    if (IsMouseButtonPressed(0)) {
        indexTouch = 0;
        for (int i = 0; i <= 4; ++i)
            if (CheckCollisionPointRec(mousePosition, rec_ChooseCharacter[i])) {
                if (i <= 2) {// character
                    characterIndex = i, indexTouch = i + 1;
                    cout << characterIndex << "====\n";
                }
                else // game state
                    menu = (i == 3) ? PLAY_GAME : ENTER_NAME;
                break;
            }

        if (menu == PLAY_GAME) {
            pChosenCharacter = &character[characterIndex];
        }
    }

    BeginDrawing();
    ClearBackground(GetColor(0x052c46ff));
    DrawTextureEx(background, (Vector2){-150, 0}, 0.0f, 1.2f, WHITE);

    for (int i = 0; i <= 4; ++i)
        DrawRectangle(rec_ChooseCharacter[i].x, rec_ChooseCharacter[i].y, rec_ChooseCharacter[i].width, rec_ChooseCharacter[i].height, BROWN);

    if (indexMouse){
        DrawRectangle(rec_ChooseCharacter[indexMouse - 1].x, rec_ChooseCharacter[indexMouse - 1].y, rec_ChooseCharacter[indexMouse - 1].width, rec_ChooseCharacter[indexMouse - 1].height, Fade(LIME, 0.5f));
       // DrawRectangleLines(rec_ChooseCharacter[indexTouch - 1].x, rec_ChooseCharacter[indexTouch - 1].y, rec_ChooseCharacter[indexTouch - 1].width, rec_ChooseCharacter[indexTouch - 1].height, RAYWHITE);
    }

    if (1 <= indexMouse && indexMouse <= 4){
        DrawRectangleLines(rec_ChooseCharacter[indexMouse - 1].x, rec_ChooseCharacter[indexMouse - 1].y, rec_ChooseCharacter[indexMouse - 1].width, rec_ChooseCharacter[indexMouse - 1].height, RAYWHITE);
    }

    if (indexTouch){
        DrawRectangle(rec_ChooseCharacter[indexTouch - 1].x, rec_ChooseCharacter[indexTouch - 1].y, rec_ChooseCharacter[indexTouch - 1].width, rec_ChooseCharacter[indexTouch - 1].height, Fade(LIME, 0.5f));
        DrawRectangleLines(rec_ChooseCharacter[indexTouch - 1].x, rec_ChooseCharacter[indexTouch - 1].y, rec_ChooseCharacter[indexTouch - 1].width, rec_ChooseCharacter[indexTouch - 1].height, RAYWHITE);
    }

    DrawTextEx(font, "CHOOSE YOUR CHARACTER", (Vector2){GetScreenWidth() / 2.0f - 700 / 2, GetScreenHeight() / 2.0f - 230}, 70, 2, DARKGREEN);
    DrawText(" PLAY ", GetScreenWidth() / 2.0f - 50, GetScreenHeight() / 2.0f + 150, 30, RAYWHITE);
    DrawText(" BACK ", GetScreenWidth() / 2.0f - 50, GetScreenHeight() / 2.0f + 210, 30, RAYWHITE);
    character[0].DrawChoose((Vector2){GetScreenWidth() / 2.0f - 365, GetScreenHeight() / 2.0f - 125});
    character[1].DrawChoose((Vector2){GetScreenWidth() / 2.0f - 65, GetScreenHeight() / 2.0f - 125});
    character[2].DrawChoose((Vector2){GetScreenWidth() / 2.0f + 235, GetScreenHeight() / 2.0f - 125});
    EndDrawing();
}

void Menu::Restart(){
    GameMap.Restart();
    LoadingSecond = 239;
    character[characterIndex].position = (Vector2){GetScreenWidth()/2 - 32, GetScreenHeight() - 200};
    character[characterIndex].moveside = character[characterIndex].movestate = 0;
    isCollided = false;
    if (record < score) record = score;
    score = 0;
    acceleration = (level - 1)*2;

}

void Menu::DrawLoadGame(){
    if (CheckCollisionPointRec(mousePosition, rec_LoadGame[0])){
        indexMouse = 1;
        SetMouseCursor(2);
    }
    else if (CheckCollisionPointRec(mousePosition, rec_LoadGame[1])){
        indexMouse = 2;
        SetMouseCursor(4);
    }
    else if (CheckCollisionPointRec(mousePosition, rec_LoadGame[2])){
        indexMouse = 3;
        SetMouseCursor(4);
    }
    else{
        indexMouse = 0;
    }
    if (IsKeyPressed(KEY_ESCAPE)) menu = LEVEL_MENU;
    if (IsMouseButtonPressed(0))
    {
        if (CheckCollisionPointRec(mousePosition, rec_LoadGame[0])){
            frames = 0;
            indexTouch = 1;
        }
        else if (CheckCollisionPointRec(mousePosition, rec_LoadGame[1])){
            CanLoad = DirectoryExists(FilePath.c_str()) && !IsPathFile(FilePath.c_str());
            if (CanLoad){
                LoadGame();
                LoadingSecond = 239;
                menu = LOADING_PHASE;
            }
        }
        else if (CheckCollisionPointRec(mousePosition, rec_LoadGame[2])){
            menu = MAIN_MENU;
        }
        else{
            indexTouch = 0;
            frames = 100;
        }
    }
    if (indexTouch == 1){
        int key = GetCharPressed();
        while (key > 0)
        {
            if ((key >= 32) && (key <= 125) && (id <= 25))
            {
                FilePath.push_back((char)key);
            }
            key = GetCharPressed();
        }
        if (IsKeyPressed(KEY_BACKSPACE))
        {
            if (FilePath.size())
            FilePath.pop_back();
        }
    }
    if (IsKeyPressed(KEY_ENTER)){
        CanLoad = DirectoryExists(FilePath.c_str()) && !IsPathFile(FilePath.c_str());
        if (CanLoad){
            LoadGame();
            LoadingSecond = 239;
            menu = LOADING_PHASE;
        }
    }
    BeginDrawing();
    ClearBackground(GetColor(0x052c46ff));
    DrawTextureEx(background, (Vector2){-150, 0}, 0.0f, 1.2f, WHITE);
    DrawRectangle(rec_LoadGame[0].x, rec_LoadGame[0].y, rec_LoadGame[0].width, rec_LoadGame[0].height, DARKBLUE);
    DrawRectangle(rec_LoadGame[1].x, rec_LoadGame[1].y, rec_LoadGame[1].width, rec_LoadGame[1].height, BLUE);
    DrawRectangle(rec_LoadGame[2].x, rec_LoadGame[2].y, rec_LoadGame[2].width, rec_LoadGame[2].height, BLUE);
    if (indexMouse) {
        DrawRectangle(rec_LoadGame[indexMouse - 1].x, rec_LoadGame[indexMouse - 1].y, rec_LoadGame[indexMouse - 1].width, rec_LoadGame[indexMouse - 1].height, Fade(DARKBLUE, 0.3f));
        DrawRectangleLines(rec_LoadGame[indexMouse - 1].x, rec_LoadGame[indexMouse - 1].y, rec_LoadGame[indexMouse - 1].width, rec_LoadGame[indexMouse - 1].height, DARKBLUE);
    }
    DrawText("CHOOSE A FOLDER PATH TO LOAD", GetScreenWidth() / 2 - 400, GetScreenHeight() / 2 - 60, 30, MAROON);
    DrawText(FilePath.c_str(), rec_LoadGame[0].x + 10, rec_LoadGame[0].y + 10, 30, RAYWHITE);
    if ((frames/15)%2 == 0 && indexTouch == 1) DrawText("|", rec_LoadGame[0].x + 13 + MeasureText(FilePath.c_str(), 30), rec_LoadGame[0].y + 10, 30, RAYWHITE);
    DrawText(" LOAD ", GetScreenWidth() / 2 - 50, GetScreenHeight() / 2 + 150, 30, RAYWHITE);
    DrawText(" BACK ", GetScreenWidth() / 2 - 50, GetScreenHeight() / 2 + 210, 30, RAYWHITE);
    if (!CanLoad){
        DrawText("*WRONG DIRECTORY", GetScreenWidth() / 2 - 400, GetScreenHeight() / 2 + 50, 20, RED);
    }
    EndDrawing();
}

void Menu::DrawLoadGameWhilePlay(){
    if (CheckCollisionPointRec(mousePosition, rec_LoadGameWhilePlay[0])){
        indexMouse = 1;
        SetMouseCursor(2);
    }
    else if (CheckCollisionPointRec(mousePosition, rec_LoadGameWhilePlay[1])){
        indexMouse = 2;
        SetMouseCursor(4);
    }
    else if (CheckCollisionPointRec(mousePosition, rec_LoadGameWhilePlay[2])){
        indexMouse = 3;
        SetMouseCursor(4);
    }
    else if (CheckCollisionPointRec(mousePosition, rec_LoadGameWhilePlay[3])){
        indexMouse = 4;
        SetMouseCursor(4);
    }
    else{
        indexMouse = 0;
    }
    if (IsKeyPressed(KEY_ESCAPE)) menu = LEVEL_MENU;
    if (IsMouseButtonPressed(0))
    {
        if (CheckCollisionPointRec(mousePosition, rec_LoadGameWhilePlay[0])){
            frames = 0;
            indexTouch = 1;
        }
        else if (CheckCollisionPointRec(mousePosition, rec_LoadGameWhilePlay[1])){
            indexTouch = 0;
            menu = PLAY_GAME; // enter to choose character
        }
        else if (CheckCollisionPointRec(mousePosition, rec_LoadGameWhilePlay[2])){
            CanLoad = DirectoryExists(FilePath.c_str()) && !IsPathFile(FilePath.c_str());
            if (CanLoad){
                LoadGame();
                LoadingSecond = 239;
                menu = LOADING_PHASE;
            }
        }
        else if (CheckCollisionPointRec(mousePosition, rec_LoadGameWhilePlay[3])){
            Restart();
            menu = MAIN_MENU;
        }
        else{
            indexTouch = 0;
            frames = 100;
        }
    }
    if (indexTouch == 1){
        int key = GetCharPressed();
        while (key > 0)
        {
            if ((key >= 32) && (key <= 125) && (id <= 25))
            {
                FilePath.push_back((char)key);
            }
            key = GetCharPressed();
        }
        if (IsKeyPressed(KEY_BACKSPACE))
        {
            if(FilePath.size())
            FilePath.pop_back();
        }
    }
    if (IsKeyPressed(KEY_ENTER)){
        CanLoad = DirectoryExists(FilePath.c_str()) && !IsPathFile(FilePath.c_str());
        if (CanLoad){
            LoadGame();
            LoadingSecond = 239;
            menu = LOADING_PHASE;
        }
    }
    BeginDrawing();
    ClearBackground(GetColor(0x052c46ff));
    GameMap.Draw(TrafficLight);
    character[characterIndex].DrawInGame();
    DrawRectangle(GetScreenWidth()/2 - 420, GetScreenHeight()/2 - 150, 840, 500, BROWN);
    DrawRectangle(rec_LoadGameWhilePlay[0].x, rec_LoadGameWhilePlay[0].y, rec_LoadGameWhilePlay[0].width, rec_LoadGameWhilePlay[0].height, DARKBLUE);
    DrawRectangle(rec_LoadGameWhilePlay[1].x, rec_LoadGameWhilePlay[1].y, rec_LoadGameWhilePlay[1].width, rec_LoadGameWhilePlay[1].height, BLUE);
    DrawRectangle(rec_LoadGameWhilePlay[2].x, rec_LoadGameWhilePlay[2].y, rec_LoadGameWhilePlay[2].width, rec_LoadGameWhilePlay[2].height, BLUE);
    DrawRectangle(rec_LoadGameWhilePlay[3].x, rec_LoadGameWhilePlay[3].y, rec_LoadGameWhilePlay[3].width, rec_LoadGameWhilePlay[3].height, BLUE);
    if (indexMouse) {
        DrawRectangle(rec_LoadGameWhilePlay[indexMouse - 1].x, rec_LoadGameWhilePlay[indexMouse - 1].y, rec_LoadGameWhilePlay[indexMouse - 1].width, rec_LoadGameWhilePlay[indexMouse - 1].height, Fade(DARKBLUE, 0.3f));
        DrawRectangleLines(rec_LoadGameWhilePlay[indexMouse - 1].x, rec_LoadGameWhilePlay[indexMouse - 1].y, rec_LoadGameWhilePlay[indexMouse - 1].width, rec_LoadGameWhilePlay[indexMouse - 1].height, DARKBLUE);
    }
    DrawText("CHOOSE A FOLDER PATH TO LOAD", GetScreenWidth() / 2 - 400, GetScreenHeight() / 2 - 60, 30, PINK);
    DrawText(FilePath.c_str(), rec_LoadGameWhilePlay[0].x + 10, rec_LoadGameWhilePlay[0].y + 10, 30, RAYWHITE);
    if ((frames/15)%2 == 0 && indexTouch == 1) DrawText("|", rec_LoadGameWhilePlay[0].x + 13 + MeasureText(FilePath.c_str(), 30), rec_LoadGameWhilePlay[0].y + 10, 30, RAYWHITE);
    DrawText(" RESUME ", GetScreenWidth() / 2 - MeasureText(" RESUME ", 30)/2, GetScreenHeight() / 2 + 150, 30, RAYWHITE);
    DrawText(" LOAD ", GetScreenWidth() / 2 - 50, GetScreenHeight() / 2 + 210, 30, RAYWHITE);
    DrawText(" EXIT ", GetScreenWidth() / 2 - 50, GetScreenHeight() / 2 + 270, 30, RAYWHITE);
    if (!CanLoad){
        DrawText("*WRONG DIRECTORY", GetScreenWidth() / 2 - 400, GetScreenHeight() / 2 + 50, 20, YELLOW);
    }
    EndDrawing();
}
void Menu::SaveGame(){
    ofstream fout;
    fout.open(FilePath + "/gamestate.txt");
    fout << level << " " << score << " " << characterIndex << " " << TrafficLight << " " << TrafficLightSecond << '\n';
    character[characterIndex].Save(fout);
    GameMap.Save(fout);
    fout.close();
}
void Menu::DrawLoseMenu(){
    if (CheckCollisionPointRec(mousePosition, rec_LoseMenu[0]))
        {indexMouse = 1; SetMouseCursor(4);}
    else if (CheckCollisionPointRec(mousePosition, rec_LoseMenu[1]))
        {indexMouse = 2; SetMouseCursor(4);}    
    else 
        indexMouse = 0;
    if (IsMouseButtonPressed(0)){
        if (CheckCollisionPointRec(mousePosition, rec_LoseMenu[0])){
            Restart();
            menu = LOADING_PHASE;
            return;
        }
        if (CheckCollisionPointRec(mousePosition, rec_LoseMenu[1])){
            Restart();
            menu = MAIN_MENU;
            return;
        }
    }
    BeginDrawing();
    ClearBackground(GetColor(0x052c46ff));
    GameMap.Draw(TrafficLight);
    character[characterIndex].DrawInGame();
    // DrawRectangle(GetScreenWidth()/2 - 420, GetScreenHeight()/2 - 250, 840, 500, BROWN);
    DrawRectangle(rec_LoseMenu[0].x, rec_LoseMenu[0].y, rec_LoseMenu[0].width, rec_LoseMenu[0].height, BLUE);
    DrawRectangle(rec_LoseMenu[1].x, rec_LoseMenu[1].y, rec_LoseMenu[1].width, rec_LoseMenu[1].height, BLUE);
    if (indexMouse) {
        DrawRectangle(rec_LoseMenu[indexMouse - 1].x, rec_LoseMenu[indexMouse - 1].y, rec_LoseMenu[indexMouse - 1].width, rec_LoseMenu[indexMouse - 1].height, Fade(DARKBLUE, 0.3f));
    }
    DrawText("BETTER LUCK NEXT TIME^^", GetScreenWidth()/2 - MeasureText("BETTER LUCK NEXT TIME^^", 50)/2, GetScreenHeight()/2 - 25, 50, MAROON);
    if (score > record){
        DrawText("CONGRATULATIONS! YOU HAVE BEATEN THE RECORD", GetScreenWidth()/2 - MeasureText("CONGRATULATIONS! YOU HAVE BEATEN THE RECORD", 30)/2, GetScreenHeight()/2 + 55, 30, YELLOW);
    }
    DrawText(" RESTART ", GetScreenWidth() / 2 - MeasureText(" RESTART ", 30) / 2, GetScreenHeight() / 2 + 150, 30, RAYWHITE);
    DrawText(" BACK ", GetScreenWidth() / 2 - 50, GetScreenHeight() / 2 + 210, 30, RAYWHITE);
    EndDrawing();
}

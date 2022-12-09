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

    DrawTextEx(font, "CROSSING ROAD", (Vector2){GetScreenWidth() / 2 - 210, GetScreenHeight() / 2 - 230}, 70, 2, DARKBLUE);
    DrawText(" PLAY ", GetScreenWidth() / 2 - 50, GetScreenHeight() / 2 - 90, 30, RAYWHITE);
    DrawText("LOAD GAME", GetScreenWidth() / 2 - 85, GetScreenHeight() / 2 - 30, 30, RAYWHITE);
    DrawText("SCOREBOARD", GetScreenWidth() / 2 - 100, GetScreenHeight() / 2 + 30, 30, RAYWHITE);
    DrawText("INSTRUCTION", GetScreenWidth() / 2 - 105, GetScreenHeight() / 2 + 90, 30, RAYWHITE);
    DrawText(" EXIT ", GetScreenWidth() / 2 - 50, GetScreenHeight() / 2 + 150, 30, RAYWHITE);
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
    

    DrawTextEx(font, "CHOOSE YOUR LEVEL", (Vector2){GetScreenWidth() / 2 - 250, GetScreenHeight() / 2 - 230}, 70, 2, MAROON);
    DrawText(" EASY ", GetScreenWidth() / 2 - 50, GetScreenHeight() / 2 - 90, 30, RAYWHITE);
    DrawText("MEDIUM", GetScreenWidth() / 2 - 60, GetScreenHeight() / 2 - 30, 30, RAYWHITE);
    DrawText(" HARD ", GetScreenWidth() / 2 - 50, GetScreenHeight() / 2 + 30, 30, RAYWHITE);
    DrawText(" BACK ", GetScreenWidth() / 2 - 50, GetScreenHeight() / 2 + 90, 30, RAYWHITE);
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
        DrawRectangle(GetScreenWidth() / 2 - 325, GetScreenHeight() / 2 - 210, 645, 65,LIME);
        DrawTextEx(font,"THERE IS NO ACHIEVEMENT HERE!!", (Vector2){GetScreenWidth() / 2 - 320, GetScreenHeight() / 2 - 200}, 50, 2, MAROON);
    }
    DrawText(" CLEAR ", GetScreenWidth() / 2 - 60, GetScreenHeight() / 2 + 150, 30, RAYWHITE);
    DrawText(" BACK ", GetScreenWidth() / 2 - 50, GetScreenHeight() / 2 + 210, 30, RAYWHITE);
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
    DrawTextureEx(woodboard,(Vector2){GetScreenWidth() / 2 - 363, GetScreenHeight() / 2 - 237},0.0f, 0.7f, WHITE);
    DrawTextureEx(woodboard,(Vector2){GetScreenWidth() / 2 - 363, GetScreenHeight() / 2 - 187},0.0f, 0.7f, WHITE);
    DrawRectangle(rec_Instruction.x, rec_Instruction.y, rec_Instruction.width, rec_Instruction.height, BROWN);
    if (indexMouse){
        DrawRectangle(rec_Instruction.x, rec_Instruction.y, rec_Instruction.width, rec_Instruction.height, Fade(DARKBROWN, 0.3f));
        DrawRectangleLines(rec_Instruction.x, rec_Instruction.y, rec_Instruction.width, rec_Instruction.height, RAYWHITE);
    }
    DrawTextEx(font,"USE W, A, S, D TO MOVE ", (Vector2){GetScreenWidth() / 2 - 350, GetScreenHeight() / 2 - 230}, 30, 2, YELLOW);
    DrawTextEx(font,"STAY AWAY FROM OBSTACLES !!! ",(Vector2){GetScreenWidth() / 2 - 350, GetScreenHeight() / 2 - 200}, 30, 2, YELLOW);
    DrawTextEx(font,"SURVIVE AS LONG AS POSSIBLE ^^ ",(Vector2){GetScreenWidth() / 2 - 350, GetScreenHeight() / 2 - 170}, 30, 2, YELLOW);
    DrawText(" BACK ", GetScreenWidth() / 2 - 50, GetScreenHeight() / 2 + 90, 30, RAYWHITE);
    EndDrawing();
}
void Menu::DrawEnterNamePhase(){
    if (CheckCollisionPointRec(mousePosition, rec_EnterName[0])){
        indexMouse = 1;
        SetMouseCursor(2);
    }
    else if (CheckCollisionPointRec(mousePosition, rec_EnterName[1])){
        indexMouse = 2;
        SetMouseCursor(4);
    }
    else if (CheckCollisionPointRec(mousePosition, rec_EnterName[2])){
        indexMouse = 3;
        SetMouseCursor(4);
    }
    else{
        indexMouse = 0;
    }
    if (IsKeyPressed(KEY_ESCAPE)) menu = LEVEL_MENU;
    if (IsMouseButtonPressed(0))
    {
        if (CheckCollisionPointRec(mousePosition, rec_EnterName[0])){
            frames = 0;
            indexTouch = 1;
        }
        else if (CheckCollisionPointRec(mousePosition, rec_EnterName[1])){
            indexTouch = 0;
            menu = 7; // enter to choose character
        }
        else if (CheckCollisionPointRec(mousePosition, rec_EnterName[2])){
            menu = 1;
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
                name[id] = (char)key;
                name[id + 1] = '\0';
                id++;
            }
            key = GetCharPressed();
        }
        if (IsKeyPressed(KEY_BACKSPACE))
        {
            id--;
            if (id < 0)
                id = 0;
            name[id] = '\0';
        }
    }
    if (IsKeyPressed(KEY_ENTER)){
        indexTouch = 0;
        menu = 7;
    }
    BeginDrawing();
    ClearBackground(GetColor(0x052c46ff));
    DrawTextureEx(background, (Vector2){-150, 0}, 0.0f, 1.2f, WHITE);
    DrawRectangle(rec_EnterName[0].x, rec_EnterName[0].y, rec_EnterName[0].width, rec_EnterName[0].height, DARKBROWN);
    DrawRectangle(rec_EnterName[1].x, rec_EnterName[1].y, rec_EnterName[1].width, rec_EnterName[1].height, BROWN);
    DrawRectangle(rec_EnterName[2].x, rec_EnterName[2].y, rec_EnterName[2].width, rec_EnterName[2].height, BROWN);
    if (indexMouse) {
        DrawRectangle(rec_EnterName[indexMouse - 1].x, rec_EnterName[indexMouse - 1].y, rec_EnterName[indexMouse - 1].width, rec_EnterName[indexMouse - 1].height, Fade(DARKBROWN, 0.3f));
        DrawRectangleLines(rec_EnterName[indexMouse - 1].x, rec_EnterName[indexMouse - 1].y, rec_EnterName[indexMouse - 1].width, rec_EnterName[indexMouse - 1].height, RAYWHITE);
    }
    DrawTextEx(font, "ENTER YOUR NAME", (Vector2){GetScreenWidth() / 2 - 400, GetScreenHeight() / 2 - 60}, 40, 2, MAROON);
    DrawText(name, rec_EnterName[0].x + 10, rec_EnterName[0].y + 10, 30, RAYWHITE);
    if ((frames/15)%2 == 0 && indexTouch == 1) DrawText("|", rec_EnterName[0].x + 13 + MeasureText(name, 30), rec_EnterName[0].y + 10, 30, MAROON);
    DrawText(" PLAY ", GetScreenWidth() / 2 - 50, GetScreenHeight() / 2 + 150, 30, RAYWHITE);
    DrawText(" BACK ", GetScreenWidth() / 2 - 50, GetScreenHeight() / 2 + 210, 30, RAYWHITE);
    EndDrawing();
}
void Menu::DrawChooseCharacter(){
    if (CheckCollisionPointRec(mousePosition, rec_ChooseCharacter[0]))
        {indexMouse = 1; SetMouseCursor(4);}
    else if (CheckCollisionPointRec(mousePosition, rec_ChooseCharacter[1]))
        {indexMouse = 2; SetMouseCursor(4);}
    else if (CheckCollisionPointRec(mousePosition, rec_ChooseCharacter[2]))
        {indexMouse = 3; SetMouseCursor(4);}
    else if (CheckCollisionPointRec(mousePosition, rec_ChooseCharacter[3]))
        {indexMouse = 4; SetMouseCursor(4);}
    else if (CheckCollisionPointRec(mousePosition, rec_ChooseCharacter[4]))
        {indexMouse = 5; SetMouseCursor(4);}
    else 
        indexMouse = 0;
    if (IsKeyPressed(KEY_ESCAPE)) menu = ENTER_NAME;
    if (IsMouseButtonPressed(0))
    {
        if (CheckCollisionPointRec(mousePosition, rec_ChooseCharacter[0])) characterIndex = 0, indexTouch = 1;
        else if (CheckCollisionPointRec(mousePosition, rec_ChooseCharacter[1])) characterIndex = 1, indexTouch = 2;
        else if (CheckCollisionPointRec(mousePosition, rec_ChooseCharacter[2])) characterIndex = 2, indexTouch = 3;
        else if (CheckCollisionPointRec(mousePosition, rec_ChooseCharacter[3])) menu = 9; // game state
        else if (CheckCollisionPointRec(mousePosition, rec_ChooseCharacter[4])) menu = 6;
        else indexTouch = 0;
    }
    BeginDrawing();
    ClearBackground(GetColor(0x052c46ff));
    DrawTextureEx(background, (Vector2){-150, 0}, 0.0f, 1.2f, WHITE);
    DrawRectangle(rec_ChooseCharacter[0].x, rec_ChooseCharacter[0].y, rec_ChooseCharacter[0].width, rec_ChooseCharacter[0].height, BROWN);
    DrawRectangle(rec_ChooseCharacter[1].x, rec_ChooseCharacter[1].y, rec_ChooseCharacter[1].width, rec_ChooseCharacter[1].height, BROWN);
    DrawRectangle(rec_ChooseCharacter[2].x, rec_ChooseCharacter[2].y, rec_ChooseCharacter[2].width, rec_ChooseCharacter[2].height, BROWN);
    DrawRectangle(rec_ChooseCharacter[3].x, rec_ChooseCharacter[3].y, rec_ChooseCharacter[3].width, rec_ChooseCharacter[3].height, BROWN);
    DrawRectangle(rec_ChooseCharacter[4].x, rec_ChooseCharacter[4].y, rec_ChooseCharacter[4].width, rec_ChooseCharacter[4].height, BROWN);

    if (indexMouse){
        DrawRectangle(rec_ChooseCharacter[indexMouse - 1].x, rec_ChooseCharacter[indexMouse - 1].y, rec_ChooseCharacter[indexMouse - 1].width, rec_ChooseCharacter[indexMouse - 1].height, Fade(LIME, 0.5f));
       // DrawRectangleLines(rec_ChooseCharacter[indexTouch - 1].x, rec_ChooseCharacter[indexTouch - 1].y, rec_ChooseCharacter[indexTouch - 1].width, rec_ChooseCharacter[indexTouch - 1].height, RAYWHITE);
    }

    if (1 <= indexMouse && indexMouse <= 4){
        DrawRectangleLines(rec_ChooseCharacter[indexMouse - 1].x, rec_ChooseCharacter[indexMouse - 1].y, rec_ChooseCharacter[indexMouse - 1].width, rec_ChooseCharacter[indexMouse - 1].height, RAYWHITE);
    }

    if (indexTouch){
        DrawRectangleLines(rec_ChooseCharacter[indexTouch - 1].x, rec_ChooseCharacter[indexTouch - 1].y, rec_ChooseCharacter[indexTouch - 1].width, rec_ChooseCharacter[indexTouch - 1].height, RAYWHITE);
    }

    DrawTextEx(font, "CHOOSE YOUR CHARACTER", (Vector2){GetScreenWidth() / 2 - 700 / 2, GetScreenHeight() / 2 - 230}, 70, 2, DARKGREEN);
    DrawText(" PLAY ", GetScreenWidth() / 2 - 50, GetScreenHeight() / 2 + 150, 30, RAYWHITE);
    DrawText(" BACK ", GetScreenWidth() / 2 - 50, GetScreenHeight() / 2 + 210, 30, RAYWHITE);
    character[0].DrawChoose((Vector2){GetScreenWidth() / 2 - 365, GetScreenHeight() / 2 - 125});
    character[1].DrawChoose((Vector2){GetScreenWidth() / 2 - 65, GetScreenHeight() / 2 - 125});
    character[2].DrawChoose((Vector2){GetScreenWidth() / 2 + 235, GetScreenHeight() / 2 - 125});
    EndDrawing();
}
void DrawLoadingPhase(){
    
}
void DrawStatusMenu(){

} // appear if you lose/ want to exit
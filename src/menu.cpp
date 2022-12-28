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

}

void DrawLoadingPhase(){
    
}
void DrawStatusMenu(){

} // appear if you lose/ want to exit


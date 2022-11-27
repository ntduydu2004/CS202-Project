#define RAYGUI_IMPLEMENTATION
#include "menu.h"
using namespace std;
void DrawMainMenu(Vector2& mousePosition, Vector2& touchPosition, short& indexMouse, short& menu, Rectangle rec_Role[], Texture2D background){
    if (CheckCollisionPointRec(mousePosition, rec_Role[0]))
        {indexMouse = 1; SetMouseCursor(4);}
    else if (CheckCollisionPointRec(mousePosition, rec_Role[1]))
        {indexMouse = 2; SetMouseCursor(4);}
    else if (CheckCollisionPointRec(mousePosition, rec_Role[2]))
        {indexMouse = 3; SetMouseCursor(4);}
    else if (CheckCollisionPointRec(mousePosition, rec_Role[3]))
        {indexMouse = 4; SetMouseCursor(4);}
    else if (CheckCollisionPointRec(mousePosition, rec_Role[4]))
        {indexMouse = 5; SetMouseCursor(4);}
    else
        indexMouse = 0;
    if (IsMouseButtonPressed(0))
    {
        for (int i = 0; i < 5; i ++){
            if (CheckCollisionPointRec(mousePosition, rec_Role[i])){
                menu = i + 1;
                break;
            }
        }
    }

    BeginDrawing();
    ClearBackground(GetColor(0x052c46ff));
    DrawTextureEx(background, (Vector2){-150, 0}, 0.0f, 1.2f, WHITE);
    DrawRectangle(rec_Role[0].x, rec_Role[0].y, rec_Role[0].width, rec_Role[0].height, BROWN);
    DrawRectangle(rec_Role[1].x, rec_Role[1].y, rec_Role[1].width, rec_Role[1].height, BROWN);
    DrawRectangle(rec_Role[2].x, rec_Role[2].y, rec_Role[2].width, rec_Role[2].height, BROWN);
    DrawRectangle(rec_Role[3].x, rec_Role[3].y, rec_Role[3].width, rec_Role[3].height, BROWN);
    DrawRectangle(rec_Role[4].x, rec_Role[4].y, rec_Role[4].width, rec_Role[4].height, BROWN);
    if (indexMouse > 0){
        DrawRectangle(rec_Role[indexMouse - 1].x, rec_Role[indexMouse - 1].y, rec_Role[indexMouse - 1].width, rec_Role[indexMouse - 1].height, Fade(DARKBROWN, 0.3f));
        DrawRectangleLines(rec_Role[indexMouse - 1].x, rec_Role[indexMouse - 1].y, rec_Role[indexMouse - 1].width, rec_Role[indexMouse - 1].height, RAYWHITE);
    }

    DrawText("CROSSING ROAD", GetScreenWidth() / 2 - 200, GetScreenHeight() / 2 - 230, 50, RAYWHITE);
    DrawText(" PLAY ", GetScreenWidth() / 2 - 50, GetScreenHeight() / 2 - 90, 30, RAYWHITE);
    DrawText("LOAD GAME", GetScreenWidth() / 2 - 85, GetScreenHeight() / 2 - 30, 30, RAYWHITE);
    DrawText("SCOREBOARD", GetScreenWidth() / 2 - 100, GetScreenHeight() / 2 + 30, 30, RAYWHITE);
    DrawText("INSTRUCTION", GetScreenWidth() / 2 - 105, GetScreenHeight() / 2 + 90, 30, RAYWHITE);
    DrawText(" EXIT ", GetScreenWidth() / 2 - 50, GetScreenHeight() / 2 + 150, 30, RAYWHITE);
    EndDrawing();
}
void DrawLevelMenu(Vector2& mousePosition, Vector2& touchPosition, short& indexMouse, short& menu, short& level, Rectangle rec_Role[], Texture2D background){
    if (CheckCollisionPointRec(mousePosition, rec_Role[0]))
        {indexMouse = 1; SetMouseCursor(4);}
    else if (CheckCollisionPointRec(mousePosition, rec_Role[1]))
        {indexMouse = 2; SetMouseCursor(4);}
    else if (CheckCollisionPointRec(mousePosition, rec_Role[2]))
        {indexMouse = 3; SetMouseCursor(4);}
    else if (CheckCollisionPointRec(mousePosition, rec_Role[3]))
        {indexMouse = 4; SetMouseCursor(4);}
    else
        indexMouse = 0;
    if (IsMouseButtonPressed(0))
    {
        for (int i = 0; i < 4; i ++){
            if (CheckCollisionPointRec(mousePosition, rec_Role[i])){
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
    DrawRectangle(rec_Role[0].x, rec_Role[0].y, rec_Role[0].width, rec_Role[0].height, BROWN);
    DrawRectangle(rec_Role[1].x, rec_Role[1].y, rec_Role[1].width, rec_Role[1].height, BROWN);
    DrawRectangle(rec_Role[2].x, rec_Role[2].y, rec_Role[2].width, rec_Role[2].height, BROWN);
    DrawRectangle(rec_Role[3].x, rec_Role[3].y, rec_Role[3].width, rec_Role[3].height, BROWN);
    if (indexMouse > 0){
        DrawRectangle(rec_Role[indexMouse - 1].x, rec_Role[indexMouse - 1].y, rec_Role[indexMouse - 1].width, rec_Role[indexMouse - 1].height, Fade(DARKBROWN, 0.3f));
        DrawRectangleLines(rec_Role[indexMouse - 1].x, rec_Role[indexMouse - 1].y, rec_Role[indexMouse - 1].width, rec_Role[indexMouse - 1].height, RAYWHITE);
    }
    

    DrawText("CHOOSE YOUR LEVEL", GetScreenWidth() / 2 - 270, GetScreenHeight() / 2 - 230, 50, RAYWHITE);
    DrawText(" EASY ", GetScreenWidth() / 2 - 50, GetScreenHeight() / 2 - 90, 30, RAYWHITE);
    DrawText("MEDIUM", GetScreenWidth() / 2 - 60, GetScreenHeight() / 2 - 30, 30, RAYWHITE);
    DrawText(" HARD ", GetScreenWidth() / 2 - 50, GetScreenHeight() / 2 + 30, 30, RAYWHITE);
    DrawText(" EXIT ", GetScreenWidth() / 2 - 50, GetScreenHeight() / 2 + 90, 30, RAYWHITE);
    EndDrawing();
}
void DrawScoreboard(Vector2& mousePosition, Vector2& touchPosition, short& indexMouse, short& menu, Rectangle rec_Role[], Texture2D background, bool& ClearScoreBoard){
    if (CheckCollisionPointRec(mousePosition, rec_Role[0]))
        {indexMouse = 1; SetMouseCursor(4);}
    else if (CheckCollisionPointRec(mousePosition, rec_Role[1]))
        {indexMouse = 2; SetMouseCursor(4);}
    else 
        indexMouse = 0;
    if (IsMouseButtonPressed(0))
    {
        if (CheckCollisionPointRec(mousePosition, rec_Role[0])) ClearScoreBoard = 1;
        if (CheckCollisionPointRec(mousePosition, rec_Role[1])) menu = 0;
    }
    BeginDrawing();
    ClearBackground(GetColor(0x052c46ff));
    DrawTextureEx(background, (Vector2){-150, 0}, 0.0f, 1.2f, WHITE);
    DrawRectangle(rec_Role[0].x, rec_Role[0].y, rec_Role[0].width, rec_Role[0].height, BROWN);
    DrawRectangle(rec_Role[1].x, rec_Role[1].y, rec_Role[1].width, rec_Role[1].height, BROWN);
    if (indexMouse) {
        DrawRectangle(rec_Role[indexMouse - 1].x, rec_Role[indexMouse - 1].y, rec_Role[indexMouse - 1].width, rec_Role[indexMouse - 1].height, Fade(DARKBROWN, 0.3f));
        DrawRectangleLines(rec_Role[indexMouse - 1].x, rec_Role[indexMouse - 1].y, rec_Role[indexMouse - 1].width, rec_Role[indexMouse - 1].height, RAYWHITE);
    }
    if (ClearScoreBoard){
        DrawText("THERE IS NO ACHIEVEMENT HERE!!", GetScreenWidth() / 2 - 280, GetScreenHeight() / 2 - 230, 30, RAYWHITE);
    }
    DrawText(" CLEAR ", GetScreenWidth() / 2 - 60, GetScreenHeight() / 2 + 150, 30, RAYWHITE);
    DrawText(" EXIT ", GetScreenWidth() / 2 - 50, GetScreenHeight() / 2 + 210, 30, RAYWHITE);
    EndDrawing();
}
void DrawInstructions(Vector2& mousePosition, Vector2& touchPosition, short& indexMouse, short& menu, Rectangle rec_Role, Texture2D background){
    if (CheckCollisionPointRec(mousePosition, rec_Role))
        {indexMouse = 1; SetMouseCursor(4);}
    else 
        indexMouse = 0;
    if (IsMouseButtonPressed(0))
    {
        if (CheckCollisionPointRec(mousePosition, rec_Role)) menu = 0;
    }
    BeginDrawing();
    ClearBackground(GetColor(0x052c46ff));
    DrawTextureEx(background, (Vector2){-150, 0}, 0.0f, 1.2f, WHITE);
    DrawRectangle(rec_Role.x, rec_Role.y, rec_Role.width, rec_Role.height, BROWN);
    if (indexMouse){
        DrawRectangle(rec_Role.x, rec_Role.y, rec_Role.width, rec_Role.height, Fade(DARKBROWN, 0.3f));
        DrawRectangleLines(rec_Role.x, rec_Role.y, rec_Role.width, rec_Role.height, RAYWHITE);
    }
    DrawText("USE W, A, S, D TO MOVE ", GetScreenWidth() / 2 - 350, GetScreenHeight() / 2 - 230, 30, RAYWHITE);
    DrawText("STAY AWAY FROM OBSTACLES !!! ", GetScreenWidth() / 2 - 350, GetScreenHeight() / 2 - 180, 30, RAYWHITE);
    DrawText("SURVIVE AS LONG AS POSSIBLE ^^ ", GetScreenWidth() / 2 - 350, GetScreenHeight() / 2 - 130, 30, RAYWHITE);
    DrawText(" EXIT ", GetScreenWidth() / 2 - 50, GetScreenHeight() / 2 + 90, 30, RAYWHITE);
    EndDrawing();
}
void DrawEnterNamePhase(Vector2& mousePosition, Vector2& touchPosition, short& indexMouse, short& indexTouch, short& menu, Rectangle rec_Role[], Texture2D background, char name[], short& id, short& frames){
    if (CheckCollisionPointRec(mousePosition, rec_Role[0])){
        indexMouse = 1;
        SetMouseCursor(2);
    }
    else if (CheckCollisionPointRec(mousePosition, rec_Role[1])){
        indexMouse = 2;
        SetMouseCursor(4);
    }
    else if (CheckCollisionPointRec(mousePosition, rec_Role[2])){
        indexMouse = 3;
        SetMouseCursor(4);
    }
    else{
        indexMouse = 0;
    }
    if (IsMouseButtonPressed(0))
    {
        if (CheckCollisionPointRec(mousePosition, rec_Role[0])){
            frames = 0;
            indexTouch = 1;
        }
        else if (CheckCollisionPointRec(mousePosition, rec_Role[1])){
            menu = 7; // enter to play
        }
        else if (CheckCollisionPointRec(mousePosition, rec_Role[2])){
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
        menu = 7;
    }
    BeginDrawing();
    ClearBackground(GetColor(0x052c46ff));
    DrawTextureEx(background, (Vector2){-150, 0}, 0.0f, 1.2f, WHITE);
    DrawRectangle(rec_Role[0].x, rec_Role[0].y, rec_Role[0].width, rec_Role[0].height, DARKBROWN);
    DrawRectangle(rec_Role[1].x, rec_Role[1].y, rec_Role[1].width, rec_Role[1].height, BROWN);
    DrawRectangle(rec_Role[2].x, rec_Role[2].y, rec_Role[2].width, rec_Role[2].height, BROWN);
    if (indexMouse) {
        DrawRectangle(rec_Role[indexMouse - 1].x, rec_Role[indexMouse - 1].y, rec_Role[indexMouse - 1].width, rec_Role[indexMouse - 1].height, Fade(DARKBROWN, 0.3f));
        DrawRectangleLines(rec_Role[indexMouse - 1].x, rec_Role[indexMouse - 1].y, rec_Role[indexMouse - 1].width, rec_Role[indexMouse - 1].height, RAYWHITE);
    }
    DrawText("ENTER YOUR NAME", GetScreenWidth() / 2 - 400, GetScreenHeight() / 2 - 60, 30, RAYWHITE);
    DrawText(name, rec_Role[0].x + 10, rec_Role[0].y + 10, 30, RAYWHITE);
    if ((frames/15)%2 == 0 && indexTouch == 1) DrawText("|", rec_Role[0].x + 13 + MeasureText(name, 30), rec_Role[0].y + 10, 30, RAYWHITE);
    DrawText(" PLAY ", GetScreenWidth() / 2 - 50, GetScreenHeight() / 2 + 150, 30, RAYWHITE);
    DrawText(" EXIT ", GetScreenWidth() / 2 - 50, GetScreenHeight() / 2 + 210, 30, RAYWHITE);
    EndDrawing();
}
void DrawLoadingPhase(){
    
}
void DrawStatusMenu(){

} // appear if you lose/ want to exit
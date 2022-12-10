#include "game.h"
using namespace std;
void Game::run(bool& close){
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
        case MAIN_MENU:
        {
            Menu::DrawMainMenu();
            break;
        }
        case LEVEL_MENU:
        {
            level = 0;
            Menu::DrawLevelMenu();
            break;
        }
        // case 2:
        // {
            // load game 
        // }
        case SCOREBOARD:
        {
            Menu::DrawScoreboard();
            break;
        }
        case INSTRUCTIONS:
        {
            Menu::DrawInstructions();
            break;
        }
        case EXIT_MENU:
        {
            close = true;
            break;
        }
        case ENTER_NAME:
        {
            Menu::DrawEnterNamePhase();
            break;
        }
        case CHOOSE_CHARACTER:
        {
            Menu::DrawChooseCharacter();
            break;
        }
        // case STATUS_MENU:
        // {
            
        // }
        case PLAY_GAME:
        {
            DrawPlayGame();
            break;
        }
        default:
        {
            menu = 0;
            break;
        }
    }
    DrawFPS(10, 10);
}

void Game::DrawPlayGame() {
    gameMap.draw();
    player.draw();
}
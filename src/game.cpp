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
            Character *pchosenCharacter = nullptr;
            Menu::DrawChooseCharacter(pchosenCharacter);
            
            if (pchosenCharacter) {
                player.SetCharacter(pchosenCharacter);
                player.setPosition(Vector2({GetScreenWidth() / 2.0f - 65, GetScreenHeight() - 100.0f}));
                
                cout << pchosenCharacter->name() << '\n';
                cout << GetScreenWidth() / 2.0f << ' ' << GetScreenHeight() - 200.0f << '\n';
            }
            
            break;
        }
        // case STATUS_MENU:
        // {
            
        // }
        case PLAY_GAME:
        {
            player.move();
            DrawPlayGame();
            break;
        }
        case LOSE_MENU:
        {
            Menu::DrawLoseMenu();
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
    BeginDrawing();
    gameMap.draw();
    player.draw();
    EndDrawing();
}
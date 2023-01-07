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
void Game::SaveScore(){
    string FilePath = "../data/scoreboard.txt";
    ofstream fout;
    fout.open(FilePath);
    fout << record << '\n';
    fout << numScore << '\n';
    for (int i = 0; i < numScore; i ++){
        fout << UserScoreList[i] << '\n';
    }
    for (int i = 0; i < numScore; i ++){
        fout << ScoreList[i] << '\n';
    }
    for (int i = 0; i < numScore; i ++){
        fout << ScoreLevel[i] << '\n';
    }
    fout.close();
}
void Game::LoadScore(){
    string FilePath = "../data/scoreboard.txt";
    ifstream fin;
    fin.open(FilePath);
    fin >> record >> numScore;
    fin.ignore();
    ScoreList.clear();
    UserScoreList.clear();
    ScoreLevel.clear();
    for (int i = 0; i < numScore; i ++){
        string tmp;
        getline(fin, tmp);
        UserScoreList.push_back(tmp);
    }
    for (int i = 0; i < numScore; i ++){
        int tmp;
        fin >> tmp;
        ScoreList.push_back(tmp);
    }
    for (int i = 0; i < numScore; i ++){
        int tmp;
        fin >> tmp;
        ScoreLevel.push_back(tmp);
    }
    fin.close();
}
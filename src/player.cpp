#include "player.h"
using namespace std;

Character::Character(string name){
    moveside = 0;
    movestate = 0;
    this->characterName = name;
    string Filename = "../data/image/Character/" + name;
    moveState.assign(4, vector <Texture2D> (4));
    // add stand state
    moveState[0][0] = LoadTexture((Filename + "/Up/stand.png").c_str());
    moveState[1][0] = LoadTexture((Filename + "/Right/stand.png").c_str());
    moveState[2][0] = LoadTexture((Filename + "/Down/stand.png").c_str());
    moveState[3][0] = LoadTexture((Filename + "/Left/stand.png").c_str());
    // add move state
    for (int i = 1; i <= 3; i ++){
        moveState[0][i] = LoadTexture((Filename + "/Up/move" + char(i + '0')).c_str());
    }
    for (int i = 1; i <= 3; i ++){
        moveState[1][i] = LoadTexture((Filename + "/Right/move" + char(i + '0')).c_str());
    }
    for (int i = 1; i <= 3; i ++){
        moveState[2][i] = LoadTexture((Filename + "/Down/move" + char(i + '0')).c_str());
    }
    for (int i = 1; i <= 3; i ++){
        moveState[3][i] = LoadTexture((Filename + "/Left/move" + char(i + '0')).c_str());
    }
}
Character::~Character(){
    for (int i = 0; i < 4; i ++){
        for (int j = 0; j < 4; j ++){
            UnloadTexture(moveState[i][j]);
        }
    }
}
void Character::DrawChoose(Vector2 position){
    DrawTextureEx(moveState[2][0], position, 0.0f, 2.0f, WHITE);
    DrawText(characterName.c_str(), position.x + 20, position.y + 150, 30, YELLOW);
}
void Character::DrawInGame(Vector2 position){
    DrawTextureEx(moveState[moveside][movestate], position, 0.0f, 1.0f, WHITE);
}



void Player::SetCharacter(Character _character) {
    character = _character;
}

void Player::SetNamePlayer(string playerName){
    this->playerName = playerName;
}

void Player::draw() {
    character.DrawInGame(position);
}
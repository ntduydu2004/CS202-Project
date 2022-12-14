#include "object.h"
using namespace std;
void ObjectFactory::Draw(int typeLane, int type, Vector2 position, bool isLeft) {
    object[typeLane][type].Draw(position, isLeft);
}

short ObjectFactory::GetHeight(int typeLane, int type) {
    return object[typeLane][type].GetHeight();
}

short ObjectFactory::GetWidth(int typeLane, int type) {
    return object[typeLane][type].GetWidth();
}


/// ====================================================================================

Object::~Object() {
    UnloadTexture(PicLeft);
    UnloadTexture(PicRight);
}

Object::Object(string TypeOfObject, int width, int height) {
    string FilePath = "../data/image/Object/" + TypeOfObject;
    PicLeft = LoadTexture((FilePath + "Left.png").c_str());
    PicRight = LoadTexture((FilePath + "Right.png").c_str());
    this->width = width;
    this->height = height;
}

void Object::Draw(Vector2 position, bool isLeft) {
    if (isLeft)
        DrawTextureEx(PicLeft, position, 0.0f, 2.0f, WHITE);
    else
        DrawTextureEx(PicRight, position, 0.0f, 2.0f, WHITE);
}

short Object::GetHeight() {
    return height;
}

short Object::GetWidth() {
    return width;
}

/// ====================================================================================

MovingObject::MovingObject(Vector2 position, int typeLane, int type, bool isLeft) {
    this->position = position;
    this->typeLane = typeLane;
    this->type = type;
    this->isLeft = isLeft;
}
void MovingObject::Draw(ObjectFactory& objectFactory, int TrafficLight) {
    if (type >= 10)
        objectFactory.Draw(0, 10 + TrafficLight, position, true);
    else 
        objectFactory.Draw(typeLane, type, position, isLeft);
}

void MovingObject::Move(float p) {
    position.y += p;
}

void MovingObject::MoveX(int TrafficLight,  float speed) {
    if (type > 9) return;

    // Check the speed of every object
    
    if (typeLane == 0) {
        if (TrafficLight == LIGHT_YELLOW) speed += 4;
        else if (TrafficLight == LIGHT_RED) speed = 0;
        else 
        speed += 8;
    }
    else if (typeLane == 2) speed += 2;
    else if (typeLane == 3) speed += 3;

    if (isLeft) speed *= -1;
    position.x += speed;
    // check outside screen and comeback to the beginning
    if (isLeft && position.x < -340) position.x = GetScreenWidth() + 10;
    if (!isLeft && position.x > GetScreenWidth() + 10) position.x = -340;
}

void MovingObject::Follow(Vector2& position, float speed) {
    if ((type == 0 && CheckCollisionPointRec((Vector2) {position.x + 30, position.y + 55}, 
                                        (Rectangle) {this->position.x, this->position.y, 195, 130}))||
    (type == 1 && CheckCollisionPointRec((Vector2) {position.x + 30, position.y + 55}, 
                                        (Rectangle) {this->position.x, this->position.y, 344, 130}))) {
        
        if (isLeft) position.x -= 2 + speed;
        else position.x += 2 + speed;

        if (position.x > GetScreenWidth() - 30)
            position.x = GetScreenWidth() - 30;
        if (position.x < -10)
            position.x = -10;
        
    }
}

void MovingObject::CheckCollisionObject(ObjectFactory& objectfactory, Vector2& position, bool& isCollided) {
    if (typeLane == 2) {
        if ((type == 0 && CheckCollisionPointRec((Vector2) {position.x + 30, position.y + 55}, 
                                                (Rectangle) {this->position.x, this->position.y, 195, 140}))
        ||(type == 1 && CheckCollisionPointRec((Vector2) {position.x + 30, position.y + 55}, 
                                                (Rectangle) {this->position.x, this->position.y, 344, 140}))) 
            return;

        isCollided = true;
    }
    else if (typeLane == 3 && type == 3) {
        if ((isLeft && CheckCollisionPointRec((Vector2) {position.x + 30, position.y + 55}, 
                                            (Rectangle) {this->position.x + 25, this->position.y + GetHeight(objectfactory) - 30, 75, 30}))
        ||(!isLeft && CheckCollisionPointRec((Vector2) {position.x + 30, position.y + 55}, 
                                            (Rectangle) {this->position.x, this->position.y + GetHeight(objectfactory) - 30, 75, 30}))) 
            isCollided = true;
    }
    else{
        if (CheckCollisionPointRec((Vector2) {position.x + 30, position.y + 55}, 
                                (Rectangle) {this->position.x, this->position.y + GetHeight(objectfactory) - 30, GetWidth(objectfactory), 30}))
            isCollided = true;
    }
}

short MovingObject::GetHeight(ObjectFactory& objectFactory) {
    return objectFactory.GetHeight(typeLane, type);
}

short MovingObject::GetWidth(ObjectFactory& objectFactory) {
    return objectFactory.GetWidth(typeLane, type);
}

void MovingObject::Load(ifstream& fin) {
    fin >> typeLane >> type >> isLeft >> position.x >> position.y;
}

void MovingObject::Save(ofstream& fout) {
    fout << typeLane << " " << type << " " << isLeft << " " << position.x << " " << position.y << '\n';
}
bool MovingObject::GetDirection(){
    return isLeft;
}
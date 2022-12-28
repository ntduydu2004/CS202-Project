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
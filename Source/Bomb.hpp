
#pragma once
#ifndef _BOMB
#define _BOMB

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "globalVar.hpp"
using namespace std;
using namespace sf;


class Bomb
{
    float velX = 0.1f, velY = 0.1f; //Initialize and assign value for float velocity for X-axis and y-axis
    Vector2f Pos;                   //Initialize position of Bomb as vector 2-D float object
    Texture tBomb;                  //Initialize the texture of Bomb
    Sprite sBomb;                   //Initialize the sprite of Bomb

public:
    Bomb(float initX, float initY); //Initialize Bomb object
    Rect<float> getPos();           //Get rectangle position of the Bomb object
    void hitWall();                 //Manipulate the Bomb object if it hits wall
    void hitFloorTop();             //Manipulate the Bomb object if it hits top or floor
    void movement();                //Logic for the Bomb object
    Sprite getSprite();             //Return Bomb's sprite
};

#endif // _BOMB


#pragma once
#ifndef _FRUIT
#define _FRUIT

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <sstream>
#include "globalVar.hpp"
using namespace std;
using namespace sf;


class Fruit
{
    float velY=0.11f;                     //Initialize and assign value for float velocity for Y-axis
    Vector2f Pos;                         //Initialize position of Player as vector 2-D float object
    Texture tFruit;                       //Initialize texture for Fruit
    Sprite sFruit;                        //Initialize sprite for Fruit
    int type, area;                       //Initialize int for type and area

public:
    Fruit();                              //Default ctor
    void createFruit(int type, int area); //Initialize Fruit object
    void hitBasket();                     //Changes if the Fruit object hits the basket
    Rect<float> getPos();                 //Get rectangle position of the Fruit object
    void movement();                      //Logic for the Fruit object
    Sprite getSprite();                   //Return Fruit's sprite
    float getY();                         //Return Fruit object position of Y-axis
};

#endif // _FRUIT

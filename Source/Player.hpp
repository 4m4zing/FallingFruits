
#pragma once
#ifndef _PLAYER
#define _PLAYER

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include "globalVar.hpp"
using namespace std;
using namespace sf;


class Player
{
    float velX=12.0f;                             //Initialize and assign value for float velocity for X-axis
    Vector2f Pos;                                 //Initialize position of Player as vector 2-D float object
    Texture tBasket;                              //Initialize the texture for Player
    Sprite sBasket;                               //Initialize the sprite for Player
    int score;                                    //Initialize int score

public:
    Player(float initX, float initY, int score);  //Initialize Player object
    Rect<float> getPos();                         //Get position of the Player object
    void moveLeft();                              //Changes if Player object is moved to the left
    void moveRight();                             //Changes if Player object is moved to the right
    Sprite getSprite();                           //Return Player's sprite
    void setScore();                              //Set score of the Player's object
    int getScore();                               //Return score of the Player's object
};

#endif // _PLAYER

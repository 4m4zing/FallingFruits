
#pragma once
#ifndef _gameMENU
#define _gameMENU

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "globalVar.hpp"
using namespace std;
using namespace sf;


int const QUANTITY = 3;              //Global initialization int Quantity

class gameMenu
{
    Font font;                       //Initialize font for font
    Text item[QUANTITY];             //Initialize text for item array
    Texture tMenu;                   //Initialize texture for Menu
    Sprite sMenu;                    //Initialize sprite for Menu
    int indexSelected;               //Initialize int indexSelected

public:
    gameMenu();
    void draw(RenderWindow &window); //Draw and Display the gameMenu object
    int getCurrentItem();            //Return the selected item
    void MoveUp();                   //Changes if Up button is pressed
    void MoveDown();                 //Changes if Down button is pressed
};

#endif // _gameMENU

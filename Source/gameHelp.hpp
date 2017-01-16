
#pragma once
#ifndef _gameHELP
#define _gameHELP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
using namespace std;
using namespace sf;


class gameHelp
{
    Texture tHelp;                   //Initialize the texture for Help
    Sprite sHelp;                    //Initialize the sprite for Help

public:
    gameHelp();                      //Initialize the gameHelp object
    void draw(RenderWindow &window); //Draw and Display the gameHelp object
};

#endif // _gameHelp



#pragma once
#ifndef _gameSTART
#define _gameSTART

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "globalVar.hpp"
#include "Splash.hpp"
#include "gameMenu.hpp"
#include "Bomb.hpp"
#include "Fruit.hpp"
#include "Player.hpp"
#include "gameHelp.hpp"
using namespace std;
using namespace sf;


class gameStart
{
    SoundBuffer bDrum;                                //Initialize the buffer for Drum sound
    Sound sDrum;                                      //Initialize the sound for Drum
    SoundBuffer bClick;                               //Initialize the buffer for Click sound
    Sound sClick;                                     //Initialize the sound for Click
    SoundBuffer bKaboom;                              //Initialize the buffer for Kaboom sound
    Sound sKaboom;                                    //Initialize the sound for Kaboom
    SoundBuffer bCaught;                              //Initialize the buffer for Caught sound
    Sound sCaught;                                    //Initialize the sound for Caught
    Font font2;                                       //Initialize the font for font2
    Text Score;                                       //Initialize the text for Score
    Text showTime;                                    //Initialize the text for showTime
    Text Result;                                      //Initialize the text for Result
    Texture tResult;                                  //Initialize the texture for Result
    Sprite sResult;                                   //Initialize the sprite for Result
    Texture tBackground;                              //Initialize the texture for Background
    Sprite sBackground;                               //Initialize the sprite for Background
    Fruit fruit;                                      //Initialize Fruit object
    int score;                                        //Initialize int score

public:
    gameStart();                                      //Manage the game state
    void gamePlay(RenderWindow &window);              //Manage the game play
    void generateFruit(Fruit &fruit);                 //Manage the fruit object
    string toString(int integer);                     //Convert int to string
    void showResult(int score, RenderWindow &window); //Show result of the game play


};

#endif // _gameSTART

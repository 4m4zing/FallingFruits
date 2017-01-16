
#pragma once
#ifndef _SPLASH
#define _SPLASH

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "globalVar.hpp"
using namespace std;
using namespace sf;


 class Splash
{
    public:
        void draw(RenderWindow& window); //Initialize the Splash Object
};

#endif // _SPLASH

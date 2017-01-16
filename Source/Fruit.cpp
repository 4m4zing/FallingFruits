
#include "Fruit.hpp"


/*---------- ---------- ---------- ---------- ----------Default ctor---------- ---------- ---------- ---------- ----------*/
Fruit::Fruit(){}

/*---------- ---------- ---------- ---------- ----------Overloading ctor---------- ---------- ---------- ---------- ----------*/
void Fruit::createFruit(int type, int area)
{
    //~~Assign values for type and area
    this->type = type;
    this->area = area;

    //~~Initialize string image
    string image;

    //~~Type of fruits
    if(type==1)
    {
        //If random number generated is 1
        image = "Apple2.png";
    }
    else if(type==2)
    {
        //If random number generated is 2
        image = "Pineapple2.png";
    }
    else if(type==3)
    {
        //If random number generated is 3
        image = "Watermelon2.png";
    }

    //~~Load image for Fruit
    if (!tFruit.loadFromFile(image))
    {
        cout << "Error : Unable to load image!" << endl;
    }
    sFruit.setTexture(tFruit);  //Set texture for Fruit

    //~~Location of falling
    if(area==1)
    {
        //If random number generated is 1
        Pos.x=win_width/3-200;
        Pos.y=0;
    }
    else if(area==2)
    {
        //If random number generated is 2
        Pos.x=win_width/2-50;
        Pos.y=0;
    }
    else if(area==3)
    {
        //If random number generated is 3
        Pos.x=win_width-150;
        Pos.y=0;
    }
    sFruit.setScale(sf::Vector2f(0.3f, 0.3f));  //Scale down the Fruit sprite
}

/*---------- ---------- ---------- ---------- ----------hitBasket() method---------- ---------- ---------- ---------- ----------*/
void Fruit::hitBasket()
{
    //~~Scale down the Fruit sprite
    sFruit.setScale(sf::Vector2f(0.0f, 0.0f));
}

/*---------- ---------- ---------- ---------- ----------getPos() method---------- ---------- ---------- ---------- ----------*/
Rect<float> Fruit::getPos()
{
    return sFruit.getGlobalBounds(); //Get values of the Fruit covered area
}

/*---------- ---------- ---------- ---------- ----------movement() method---------- ---------- ---------- ---------- ----------*/
void Fruit::movement()
{
    //~~Move
    Pos.y += velY;
    //~~Update position for Fruit
    sFruit.setPosition(Pos);
}

/*---------- ---------- ---------- ---------- ----------getSprite() method---------- ---------- ---------- ---------- ----------*/
Sprite Fruit::getSprite()
{
    return sFruit;
}

/*---------- ---------- ---------- ---------- ----------getY() method---------- ---------- ---------- ---------- ----------*/
float Fruit::getY()
{
    return Pos.y;
}

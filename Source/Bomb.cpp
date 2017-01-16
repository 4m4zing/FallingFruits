
#include "Bomb.hpp"


/*---------- ---------- ---------- ---------- ----------Overloading ctor---------- ---------- ---------- ---------- ----------*/
Bomb::Bomb(float initX, float initY)
{
    //~~Assign values for position
    Pos.x = initX;
    Pos.y = initY;

    //~~load image for Bomb
    if (!tBomb.loadFromFile("Bomb2.png"))
    {
        cout << "Error : Unable to load image!" << endl;
    }
    sBomb.setTexture(tBomb);                  //Set texture for Bomb
    sBomb.setPosition(Pos);                   //Set position for Bomb
    sBomb.setScale(sf::Vector2f(0.2f, 0.2f)); //Scale down the Bomb sprite
}

/*---------- ---------- ---------- ---------- ----------Get Position of Bomb---------- ---------- ---------- ---------- ----------*/
Rect<float> Bomb::getPos()
{
    return sBomb.getGlobalBounds(); //Get values of the Bomb covered area
}

/*---------- ---------- ---------- ---------- ----------hitWall() method---------- ---------- ---------- ---------- ----------*/
void Bomb::hitWall()
{
    if (velX < 0)
    {
        //Increase velocity to the left
        velX -= velX/100;
    }
    else if (velX >= 0)
    {
        //Increase velocity to the right
        velX += velX/100;
    }
    //Change the Bomb's direction for X-axis
    velX = -velX;
}

/*---------- ---------- ---------- ---------- ----------hitFloorTop() method---------- ---------- ---------- ---------- ----------*/
void Bomb::hitFloorTop()
{
    if (velY< 0)
    {
        //Increase velocity to down
        velY -= velY/100;
    }
    else if (velY >= 0)
    {
        //Increase velocity to up
        velY += velY/100;
    }
    //Change the Bomb's direction for Y-axis
    velY = -velY;
}

/*---------- ---------- ---------- ---------- ----------movement() method---------- ---------- ---------- ---------- ----------*/
void Bomb::movement()
{
    //~~Move
    Pos.y += velY;
    Pos.x += velX;

    //~~Border check
    if(Pos.y < 0 || Pos.y > 540 )
    {
        //If the Bomb hits top or bottom
        hitFloorTop();
    }
    if (Pos.x < 0 || Pos.x > 740 )
    {
        //If the Bomb hits left or right wall
        hitWall();
    }
    //~~Update position for Bomb
    sBomb.setPosition(Pos);
}

/*---------- ---------- ---------- ---------- ----------getSprite() method---------- ---------- ---------- ---------- ----------*/
Sprite Bomb::getSprite()
{
    return sBomb;
}

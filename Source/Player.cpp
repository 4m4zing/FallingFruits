
#include "Player.hpp"


/*---------- ---------- ---------- ---------- ----------Default ctor---------- ---------- ---------- ---------- ----------*/
Player::Player(float initX, float initY, int score)
{
    //~~Assign values for position X-axis and Y-axis, and score
    Pos.x = initX;
    Pos.y = initY;
    this->score = score;

    //~~Load image for Player
    if (!tBasket.loadFromFile("Basket2.png"))
    {
        cout << "Error : Unable to load image!" << endl;
    }
    sBasket.setTexture(tBasket);                //Set texture for Bomb
    sBasket.setPosition(Pos);                   //Set position for Player
    sBasket.setScale(sf::Vector2f(0.3f, 0.3f)); //Scale down the Player sprite
}

/*---------- ---------- ---------- ---------- ----------getPos() method---------- ---------- ---------- ---------- ----------*/
Rect<float> Player::getPos()
{
    return sBasket.getGlobalBounds(); //Get values of the Bomb covered area
}

/*---------- ---------- ---------- ---------- ----------moveLeft() method---------- ---------- ---------- ---------- ----------*/
void Player::moveLeft()
{
    if (Pos.x > 0)
    {
        //~~Decrease position by velocity X-axis
        Pos.x -= velX;
        //~~Update position for Player
        sBasket.setPosition(Pos);
    }
}

/*---------- ---------- ---------- ---------- ----------moveRight() method---------- ---------- ---------- ---------- ----------*/
void Player::moveRight()
{
    if (Pos.x < 680)
    {
        //~~Decrease position by velocity X-axis
        Pos.x += velX;
        //~~Update position for Player
        sBasket.setPosition(Pos);
    }
}

/*---------- ---------- ---------- ---------- ----------getSprite() method---------- ---------- ---------- ---------- ----------*/
Sprite Player::getSprite()
{
    return sBasket;
}

/*---------- ---------- ---------- ---------- ----------setScore() method---------- ---------- ---------- ---------- ----------*/
void Player::setScore()
{
    score += 1; //Increase score by 1
}

/*---------- ---------- ---------- ---------- ----------getScore() method---------- ---------- ---------- ---------- ----------*/
int Player::getScore()
{
    return score;
}

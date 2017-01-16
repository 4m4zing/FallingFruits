
#include "gameMenu.hpp"


/*---------- ---------- ---------- ---------- ----------Default ctor---------- ---------- ---------- ---------- ----------*/
gameMenu::gameMenu()
{
    //~~Assign value
    indexSelected = 0;

    //~~Load image for Fruit
    if(!font.loadFromFile("verdana.ttf")){
        cout << "Error : Unable to load font" << endl;
    }

    if (!tMenu.loadFromFile("Menu2.jpg"))
    {
        cout << "Error : Unable to load image!" << endl;
    }
    sMenu.setTexture(tMenu);

    //~~Set font, color, string, position for items
    item[0].setFont(font);
    item[0].setColor(Color::Blue);
    item[0].setString("Play Game");
    item[0].setPosition(Vector2f(win_width-200,win_height/(QUANTITY+1)*1));

    item[1].setFont(font);
    item[1].setColor(Color::Black);
    item[1].setString("How To Play");
    item[1].setPosition(Vector2f(win_width-200,win_height/(QUANTITY+1)*2));

    item[2].setFont(font);
    item[2].setColor(Color::Black);
    item[2].setString("Exit Game");
    item[2].setPosition(Vector2f(win_width-200,win_height/(QUANTITY+1)*3));
}

/*---------- ---------- ---------- ---------- ----------draw() method---------- ---------- ---------- ---------- ----------*/
void gameMenu::draw(RenderWindow &window)
{
    window.draw(sMenu);
    for(int i=0; i<3; i++)
    {
        window.draw(item[i]);
    }
}

/*---------- ---------- ---------- ---------- ----------getCurrentItem() method---------- ---------- ---------- ---------- ----------*/
int gameMenu::getCurrentItem()
{
    return indexSelected;
}

/*---------- ---------- ---------- ---------- ----------MoveUp() method---------- ---------- ---------- ---------- ----------*/
void gameMenu::MoveUp()
{
    if (indexSelected-1>=0)
    {
        item[indexSelected].setColor(Color::Black); //Change current selected item color
        indexSelected--;                            //Change selection
        item[indexSelected].setColor(Color::Blue);  //Change new current selected item color
    }
}

/*---------- ---------- ---------- ---------- ----------MoveDown() method---------- ---------- ---------- ---------- ----------*/
void gameMenu::MoveDown()
{
    if(indexSelected+1<QUANTITY)
    {
        item[indexSelected].setColor(Color::Black);
        indexSelected++;
        item[indexSelected].setColor(Color::Blue);
    }
}

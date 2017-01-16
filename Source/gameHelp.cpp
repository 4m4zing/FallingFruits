
#include "gameHelp.hpp"


/*---------- ---------- ---------- ---------- ----------Default ctor---------- ---------- ---------- ---------- ----------*/
gameHelp::gameHelp()
{
    //~~Load image for Help
    if (!tHelp.loadFromFile("Help2.png"))
    {
        cout << "Error : Unable to load image!" << endl;
    }
    sHelp.setTexture(tHelp); //Set texture for Help
}

/*---------- ---------- ---------- ---------- ----------draw() method---------- ---------- ---------- ---------- ----------*/
void gameHelp::draw(RenderWindow &window)
{
    //Draw and display Help
    window.draw(sHelp);
    window.display();
}


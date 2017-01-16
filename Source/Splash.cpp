
#include "Splash.hpp"


/*---------- ---------- ---------- ---------- ----------draw() method---------- ---------- ---------- ---------- ----------*/
void Splash::draw(RenderWindow &window)
{
    Clock clock;                                    //Initialize Clock object
    Time elapsed = clock.getElapsedTime();          //Initialize and assign value for Time object

    Texture tSplash;                                //Initialize texture for Splash

    //~~Load image for Splash
    if(!tSplash.loadFromFile("Splash2.jpg"))
    {
            cout << "Error : Unable to load image!" << endl;
    }
    Sprite sSplash(tSplash);                        //Initialize sprite for Splash
    window.draw(sSplash);                           //Draw Splash to the window
    window.display();                               //Show window

    Event eventSplash;                              //Initialize event object

    while(true)
    {
        //Loop while it is true
        while(window.pollEvent(eventSplash))
        {
            //Calculate current elasped time
            elapsed = clock.getElapsedTime();
            cout << elapsed.asSeconds() << endl;

            if(elapsed.asSeconds() >= 1.0f)
            {
                //Check if elapsed time exceeded the time limit
                return;
            }

            if(eventSplash.type == Event::EventType::Closed)
            {
                //If close button is clicked
                window.close();
            }
        }
    }
}

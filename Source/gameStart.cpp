
#include "gameStart.hpp"


/*---------- ---------- ---------- ---------- ----------Default Ctor---------- ---------- ---------- ---------- ----------*/
gameStart::gameStart()
{
    //~~Render window
    RenderWindow window(VideoMode(win_width, win_height), "Falling Fruits v1.2", Style::Close | Style::Titlebar);

    //~~load image for Bomb
    if(!font2.loadFromFile("verdanaz.ttf"))
    {
        cout << "Error : Unable to load font" << endl;
    }

    //~~Set Score text's font, color and position
    Score.setFont(font2);
    Score.setColor(Color::Black);
    Score.setPosition(Vector2f(30,50));

    //~~Set showTime text's font, color and position
    showTime.setFont(font2);
    showTime.setColor(Color::Black);
    showTime.setPosition(Vector2f(win_width-240,50));

    //~~Set Result text's font, color and position
    Result.setFont(font2);
    Result.setColor(Color::White);
    Result.setPosition(Vector2f(375,220));

    //~~Initialize Splash object
    Splash splash;
    //~~draw Splash object into the window
    splash.draw(window);

    //~~Initialize gameMenu object
    gameMenu gamemenu;
    //~~draw gameMenu object into the window
    gamemenu.draw(window);

    //~~Boolean to manipulate loop for gameHelp
    bool loopHelp = true;

    //~~Initialize gameHelp object
    gameHelp help;

    //~~load image for Bomb
    if (!tBackground.loadFromFile("Landscape2.jpg"))
    {
        cout << "Error : Unable to load image!" << endl;
    }
    //~~Set texture for Background
    sBackground.setTexture(tBackground);

    //~~load sound for Caught
    if (!bCaught.loadFromFile("Sound - Caught.ogg"))
    {
        cout << "Error : Unable to load sound!" << endl;
    }
    //~~Set buffer for Caught
    sCaught.setBuffer(bCaught);

    //~~load sound for Kaboom
    if (!bKaboom.loadFromFile("Sound - Kaboom.ogg"))
    {
        cout << "Error : Unable to load sound!" << endl;
    }
    //~~Set buffer for Kaboom
    sKaboom.setBuffer(bKaboom);

    //~~load sound for Click
    if (!bClick.loadFromFile("Sound - Click.ogg"))
    {
        cout << "Error : Unable to load sound!" << endl;
    }
    //~~Set buffer for Click
    sClick.setBuffer(bClick);

    //~~load sound for Drum
    if (!bDrum.loadFromFile("Sound - Drum.wav"))
    {
        cout << "Error : Unable to load sound!" << endl;
    }
    //~~Set buffer for Drum
    sDrum.setBuffer(bDrum);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            //gameMenu navigation switch
            switch(event.type)
            {
            case Event::Closed :
                window.close();
                break;

            case Event::KeyReleased :

                switch(event.key.code)
                {
                case Keyboard::Up :
                    //Up button is pressed
                    sClick.play();
                    gamemenu.MoveUp();
                    break;

                case Keyboard::Down :
                    //Down button is pressed
                    sClick.play();
                    gamemenu.MoveDown();
                    break;

                case Keyboard::Return :
                    //Enter button is pressed

                    //Choose item switch
                    switch(gamemenu.getCurrentItem())
                    {
                    case 0:
                        //Play Game
                        cout << "Play Game button has been chosen!" << endl;
                        sClick.play();
                        gamePlay(window);
                        break;

                    case 1:
                        //How To Play
                        cout << "How To Play button has been chosen!" << endl;
                        sClick.play();
                        window.clear();

                        while(loopHelp)
                        {
                            //Press space bar to return to the gameMenu
                            help.draw(window);
                            if(event.type == Event::KeyReleased)
                                {
                                    if(Keyboard::isKeyPressed(Keyboard::Space))
                                    {
                                        sClick.play();
                                        loopHelp = false;
                                    }
                                }
                        }
                        break;

                    case 2:
                        //Exit Game
                        cout << "Exit Game button has been chosen!" << endl;
                        sClick.play();
                        window.clear();
                        window.close();
                        break;
                    }
                }
            }
        }
        window.clear();
        gamemenu.draw(window);
        window.display();
    }
}

/*---------- ---------- ---------- ---------- ----------gamePlay() method---------- ---------- ---------- ---------- ----------*/
void gameStart::gamePlay(RenderWindow &window)
{
    //~~Calling method to generate random fruit
    generateFruit(fruit);

    //~~Initialize Player object
    Player basket((win_width/2), (win_height-125), 0);

    //~~Initialize Player object
    Bomb bomb((win_width/2),0);

    //~~Set string for score
    Score.setString("Score :"+toString(basket.getScore()));

    //~~Initialize Clock object
    Clock gametime;
    //Initialize and assign value for Time object
    Time gameElaspedTime = gametime.getElapsedTime();

    //~~Boolean to manipulate loop for gamePlay
    bool loopGame=true;

    while(loopGame)
    {
        Event event;
        while (window.pollEvent(event))
        {
            switch(event.type)
            {
            case Event::Closed :
                window.close();
                break;

            case Event::KeyPressed :

                switch(event.key.code)
                {
                case Keyboard::Left :
                    //Left arrow button is pressed
                    basket.moveLeft();
                    break;

                case Keyboard::Right :
                    //Right arrow button is pressed
                    basket.moveRight();
                    break;

                default :;
                }

            default :;

             }

        }

        //~~Set string for score
        Score.setString("Score :"+toString(basket.getScore()));

        //~~Calculate the gameElaspedTime
        gameElaspedTime = gametime.getElapsedTime();

        //~~Set string for showTime
        showTime.setString("Time : "+toString(gameElaspedTime.asSeconds())+" Sec");

        //~~ENDING CONDITION 1
        if(basket.getPos().intersects(bomb.getPos()))
        {
            //If the bomb collide with the basket
            sKaboom.play();
            showResult(basket.getScore(),window);
            window.clear();
            loopGame = false;
        }
        //~~ENDING CONDITION 2
        if(basket.getPos().intersects(fruit.getPos()))
        {
            //If the basket collide with fruit
            sCaught.play();
            fruit.hitBasket();
            basket.setScore(); //Increase score
        }
        //~~ENDING CONDITION 3
        if (gameElaspedTime.asSeconds()>30)
        {
            //If elapsed time is more than 30 seconds
            sDrum.play();
            showResult(basket.getScore(),window);
            loopGame = false;
        }

        if(fruit.getY() > win_height-50)
        {
            //Generate new fruit if the existing fruit disappeared
            generateFruit(fruit);
        }
        //~~Update movements
        fruit.movement();
        bomb.movement();

        window.clear();

        //~~Draw into the window
        window.draw(sBackground);
        window.draw(fruit.getSprite());
        window.draw(bomb.getSprite());
        window.draw(basket.getSprite());
        window.draw(Score);
        window.draw(showTime);

        //~~Show the window
        window.display();
    }
}

/*---------- ---------- ---------- ---------- ----------generateFruit() method---------- ---------- ---------- ---------- ----------*/
void gameStart::generateFruit(Fruit &fruit)
{
    srand (time(0));                         //Initialize random
    int fruitType = rand()%3+1;              //Random for fruit type
    int fruitArea = rand()%3+1;              //Random for fruit area
    fruit.createFruit(fruitType, fruitArea); //Create fruit
}

/*---------- ---------- ---------- ---------- ----------toString() method---------- ---------- ---------- ---------- ----------*/
string gameStart::toString(int integer)
{
    //Converting int to string
    ostringstream os;
    os << integer;
    return os.str();
}

/*---------- ---------- ---------- ---------- ----------showResult() method---------- ---------- ---------- ---------- ----------*/
void gameStart::showResult(int score, RenderWindow &window)
{
    //~~Boolean to manipulate loop for gamePlay
    bool loopResult=true;

    while(loopResult)
    {
        //~~Load image for Fruit
        window.clear();
        if (!tResult.loadFromFile("Result.jpg"))
        {
            cout << "Error : Unable to load image!" << endl;
        }

        //~~Set texture for Result
        sResult.setTexture(tResult);

        //~~Set string for Result score
        Result.setString(toString(score));

        //~~Draw and show Result Background and score
        window.draw(sResult);
        window.draw(Result);
        window.display();

        Event event;
        while (window.pollEvent(event))
        {
            //Press space bar to return to the gameMenu
            switch(event.type)
            {
                case Event::Closed :
                        window.close();
                        break;

                case Event::KeyPressed :

                    switch(event.key.code)
                    {
                    case Keyboard::Space :
                        //If spacebar is pressed
                        sClick.play();
                        loopResult=false;

                    default:;
                    }
                default:;
            }
        }
    }
}

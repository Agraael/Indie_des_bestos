//
// Created by Ludovica Pagliarani on 31/05/2018.
//

#include <chrono>
#include <thread>
#include <memory>
#include "localMenu.hpp"

graphic::localMenu::localMenu(graphic::IrrlichtLib *lib) : _lib(lib)
{
    _count = -30;
}

void    graphic::localMenu::printLogo()
{
    graphic::infos_t logo;
    logo._x = 10;
    logo._y = 5;
    logo._w = 50;
    logo._h = 50;
    logo._maxH = 50;
    logo._maxW = 50;
    logo._path = "Assets/media/Neo_Bomberman_Logo.png";
    _lib->drawImage(logo);
}

void graphic::localMenu::printBackground()
{
    graphic::infos_t background;
    background._x = 0;
    background._y = 0;
    background._w = 640;
    background._h = 480;
    background._maxW = 740;
    background._maxH = 580;
    background._path = "Assets/media/pixel_skyline.png";
    _lib->drawImage(background);
}

void graphic::localMenu::printChoicePlayers()
{
    graphic::infos_t players;
    players._x = 160;
    players._y = 30;
    players._w = 100;
    players._h = 70;
    players._maxW = 100;
    players._maxH = 70;
    players._path = "./Assets/media/players.png";
    _lib->drawImage(players);

    graphic::infos_t moins;
    moins._x = 300;
    moins._y = 50;
    moins._w = 330;
    moins._h = 80;
    moins._type = graphic::LESS_PLAYER;
    moins._desc = "Less players";
    moins._name = "";
    moins._path = "./Assets/media/left_arrow.png";
    _lib->printButton(moins);

    graphic::infos_t nbrPlayers;
    nbrPlayers._x = 340;
    nbrPlayers._y = 50;
    nbrPlayers._w = 30;
    nbrPlayers._h = 30;
    nbrPlayers._maxW = 30;
    nbrPlayers._maxH = 30;
    nbrPlayers._path = "./Assets/media/one.png";
    _lib->drawImage(nbrPlayers);

    graphic::infos_t plus;
    plus._x = 390;
    plus._y = 50;
    plus._w = 420;
    plus._h = 80;
    plus._path = "./Assets/media/right_arrow.png";
    plus._desc = "Sound up";
    plus._name = "";
    plus._type = graphic::MORE_PLAYER;
    _lib->printButton(plus);
}

void graphic::localMenu::printChoiceIA()
{
    graphic::infos_t ai;
    ai._x = 160;
    ai._y = 100;
    ai._w = 100;
    ai._h = 40;
    ai._maxW = 100;
    ai._maxH = 70;
    ai._path = "./Assets/media/ia.png";
    _lib->drawImage(ai);

    graphic::infos_t moins;
    moins._x = 300;
    moins._y = 120;
    moins._w = 330;
    moins._h = 150;
    moins._type = graphic::LESS_PLAYER;
    moins._desc = "Less players";
    moins._name = "";
    moins._path = "./Assets/media/left_arrow.png";
    _lib->printButton(moins);

    graphic::infos_t nbrPlayers;
    nbrPlayers._x = 340;
    nbrPlayers._y = 120;
    nbrPlayers._w = 30;
    nbrPlayers._h = 30;
    nbrPlayers._maxW = 30;
    nbrPlayers._maxH = 30;
    nbrPlayers._path = "./Assets/media/one.png";
    _lib->drawImage(nbrPlayers);

    graphic::infos_t plus;
    plus._x = 390;
    plus._y = 120;
    plus._w = 420;
    plus._h = 150;
    plus._path = "./Assets/media/right_arrow.png";
    plus._desc = "Sound up";
    plus._name = "";
    plus._type = graphic::MORE_PLAYER;
    _lib->printButton(plus);
}

void    graphic::localMenu::returnToMenu()
{
    graphic::infos_t buttonExit;
    buttonExit._x = 200;
    buttonExit._y = 330;
    buttonExit._w = 380;
    buttonExit._h = 360;
    buttonExit._path = "Assets/media/button_menu.png";
    buttonExit._desc = "Return to main menu";
    buttonExit._name = "Return to menu";
    buttonExit._type = graphic::EXIT_MAINMENU;
    _lib->printButton(buttonExit);
}

void    graphic::localMenu::display()
{
    printBackground();
    printChoicePlayers();
    printChoiceIA();
    printLogo();
    returnToMenu();
}

void graphic::localMenu::updateDisplay()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

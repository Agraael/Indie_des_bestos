//
// Created by Ludovica Pagliarani on 31/05/2018.
//

#include <chrono>
#include <thread>
#include <memory>
#include "localMenu.hpp"

graphic::localMenu::localMenu(graphic::IrrlichtLib *lib) : _lib(lib)
{
    _nbrPlayers = 1;
    _nbrIa = 1;
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
    moins._desc = "oh less players.. play with Ia.. ";
    moins._name = "";
    moins._path = "./Assets/media/left_arrow.png";
    _lib->printButton(moins);

    _infosPlayers._x = 340;
    _infosPlayers._y = 50;
    _infosPlayers._w = 30;
    _infosPlayers._h = 30;
    _infosPlayers._maxW = 30;
    _infosPlayers._maxH = 30;
    _infosPlayers._path = "./Assets/media/one.png";
    _playerNbrImg = _lib->drawImage(_infosPlayers);

    graphic::infos_t plus;
    plus._x = 390;
    plus._y = 50;
    plus._w = 420;
    plus._h = 80;
    plus._path = "./Assets/media/right_arrow.png";
    plus._desc = "Game Party, dude?";
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
    moins._type = graphic::LESS_IA;
    moins._desc = "Yes men, play with your friends!";
    moins._name = "";
    moins._path = "./Assets/media/left_arrow.png";
    _lib->printButton(moins);

    _infosIa._x = 340;
    _infosIa._y = 120;
    _infosIa._w = 30;
    _infosIa._h = 30;
    _infosIa._maxW = 30;
    _infosIa._maxH = 30;
    _infosIa._path = "./Assets/media/one.png";
    _iaNbrImg = _lib->drawImage(_infosIa);

    graphic::infos_t plus;
    plus._x = 390;
    plus._y = 120;
    plus._w = 420;
    plus._h = 150;
    plus._path = "./Assets/media/right_arrow.png";
    plus._desc = "More ia is like 'forever alone'!";
    plus._name = "";
    plus._type = graphic::MORE_IA;
    _lib->printButton(plus);
}

void graphic::localMenu::choiceMap()
{
    graphic::infos_t map;
    map._x = 50;
    map._y = 150;
    map._w = 100;
    map._h = 40;
    map._maxW = 100;
    map._maxH = 70;
    map._path = "./Assets/media/map.png";
    _lib->drawImage(map);

    graphic::infos_t dist;
    dist._x = 180;
    dist._y = 180;
    dist._w = 360;
    dist._h = 210;
    dist._type = graphic::DIST_MAP;
    dist._desc = "only distructibles cubes";
    dist._name = "FULL DISTRUCTIBLE";
    dist._path = "./Assets/media/blue_button.png";
    _lib->printButton(dist);

    graphic::infos_t stand;
    stand._x = 390;
    stand._y = 180;
    stand._w = 570;
    stand._h = 210;
    stand._path = "./Assets/media/blue_button.png";
    stand._desc = "indistructibles and distructibles cubes";
    stand._name = "STANDARD";
    stand._type = graphic::STAND_MAP;
    _lib->printButton(stand);
}

void graphic::localMenu::choiceSizeMap()
{
    graphic::infos_t map;
    map._x = 50;
    map._y = 210;
    map._w = 100;
    map._h = 40;
    map._maxW = 100;
    map._maxH = 70;
    map._path = "./Assets/media/map_size.png";
    _lib->drawImage(map);

    graphic::infos_t small;
    small._x = 180;
    small._y = 240;
    small._w = 300;
    small._h = 270;
    small._type = graphic::SMALL_MAP;
    small._desc = "small map";
    small._name = "SMALL";
    small._path = "./Assets/media/blue_button.png";
    _lib->printButton(small);

    graphic::infos_t medium;
    medium._x = 330;
    medium._y = 240;
    medium._w = 450;
    medium._h = 270;
    medium._path = "./Assets/media/blue_button.png";
    medium._desc = "medium map";
    medium._name = "MEDIUM";
    medium._type = graphic::MEDIUM_MAP;
    _lib->printButton(medium);

    graphic::infos_t large;
    large._x = 480;
    large._y = 240;
    large._w = 600;
    large._h = 270;
    large._path = "./Assets/media/blue_button.png";
    large._desc = "large map";
    large._name = "LARGE";
    large._type = graphic::LARGE_MAP;
    _lib->printButton(large);
}

void    graphic::localMenu::playGame()
{
    graphic::infos_t buttonExit;
    buttonExit._x = 200;
    buttonExit._y = 330;
    buttonExit._w = 380;
    buttonExit._h = 360;
    buttonExit._path = "Assets/media/button_menu.png";
    buttonExit._desc = "Play game";
    buttonExit._name = "START";
    buttonExit._type = graphic::EXIT_MAINMENU;
    _lib->printButton(buttonExit);
}

void    graphic::localMenu::returnToMenu()
{
    graphic::infos_t buttonExit;
    buttonExit._x = 200;
    buttonExit._y = 390;
    buttonExit._w = 380;
    buttonExit._h = 420;
    buttonExit._path = "Assets/media/button_menu.png";
    buttonExit._desc = "Return to main menu";
    buttonExit._name = "RETURN TO MENU";
    buttonExit._type = graphic::EXIT_MAINMENU;
    _lib->printButton(buttonExit);
}

void graphic::localMenu::printNbrChoice(int nbr, graphic::infos_t *nbrEntity, irr::gui::IGUIImage *img)
{
    img->remove();
    if (nbr == 1)
        (*nbrEntity)._path = "./Assets/media/one.png";
    if (nbr == 2)
        (*nbrEntity)._path = "./Assets/media/two.png";
    if (nbr == 3)
        (*nbrEntity)._path = "./Assets/media/three.png";

}

void     graphic::localMenu::setNbrIa(int nbr) {

    if (nbr == 1 && _nbrPlayers < 3 && _nbrIa < 3)
        _nbrIa++;
    if (nbr == 1 && _nbrPlayers == 3 && _nbrIa == 1)
        _nbrIa++;
    if (nbr == -1 && _nbrIa > 1)
        _nbrIa--;
    printNbrChoice(_nbrIa, &_infosIa, _iaNbrImg);
    _iaNbrImg = _lib->drawImage(_infosIa);
}

void     graphic::localMenu::setNbrPlayer(int nbr)
{
    if (nbr == 1 && _nbrPlayers < 3 && _nbrIa < 3)
        _nbrPlayers++;
    if (nbr == 1 && _nbrPlayers == 1 && _nbrIa == 3)
        _nbrIa++;
    if (nbr == -1 && _nbrPlayers > 1)
        _nbrPlayers--;
    printNbrChoice(_nbrPlayers, &_infosPlayers, _playerNbrImg);
    std::cout << _infosPlayers._path << std::endl;
    std::cout << _nbrPlayers << std::endl;
    _playerNbrImg = _lib->drawImage(_infosPlayers);
}

void    graphic::localMenu::display()
{
    printBackground();
    choiceMap();
    choiceSizeMap();
    printLogo();
    playGame();
    printChoicePlayers();
    printChoiceIA();
    returnToMenu();
}

void graphic::localMenu::updateDisplay()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

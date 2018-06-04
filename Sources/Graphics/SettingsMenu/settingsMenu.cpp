//
// Created by Ludovica Pagliarani on 31/05/2018.
//

#include <chrono>
#include <thread>
#include <memory>
#include "settingsMenu.hpp"

graphic::settingsMenu::settingsMenu(graphic::IrrlichtLib *lib) : _lib(lib)
{
}

void    graphic::settingsMenu::printLogo()
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

void graphic::settingsMenu::printBackground()
{
    graphic::infos_t background;
    background._x = 0;
    background._y = 0;
    background._w = 640;
    background._h = 480;
    background._maxH = 740;
    background._maxW = 580;
    background._path = "Assets/media/Neo_Bomberman_Logo.png";
    _lib->drawImage(background);
}

void graphic::settingsMenu::brightnessBar()
{
    /*graphic::infos_t brightness;
    brightness._x = 200;
    brightness._y = 250;
    brightness._w = 400;
    brightness._h = 150;
    brightness._type = graphic::GUI_ID_TRANSPARENCY_SCROLL_BAR;
    _lib->scrollBarButton(brightness);*/
}

void graphic::settingsMenu::printSound()
{
    graphic::infos_t moins;
    moins._x = 200;
    moins._y = 150;
    moins._w = 30;
    moins._h = 30;
    moins._maxW = 30;
    moins._maxH = 30;
    moins._type = graphic::SOUND_DOWN;
    moins._path = "./Assets/media/moins.png";
    _lib->drawImage(moins);

    graphic::infos_t sound;
    sound._x = 240;
    sound._y = 130;
    sound._w = 100;
    sound._h = 80;
    sound._maxW = 100;
    sound._maxH = 80;
    sound._path = "../../../Assets/media/moins.png";
    _lib->drawImage(sound);

    graphic::infos_t plus;
    plus._x = 350;
    plus._y = 150;
    plus._w = 30;
    plus._h = 30;
    plus._maxW = 30;
    plus._maxW = 30;
    plus._type = graphic::SOUND_UP;
    plus._path = "../../../Assets/media/plus.png";
    _lib->drawImage(plus);
}

void    graphic::settingsMenu::display()
{
    printBackground();
    printLogo();
    printSound();
    //printUserName();
    //drawChoiceButtons();
    //_dirigible = drawDirigible();
}

void graphic::settingsMenu::updateDisplay()
{
    brightnessBar();
    //std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

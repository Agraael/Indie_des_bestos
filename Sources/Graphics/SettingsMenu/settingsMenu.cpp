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
    _lib->drawImage(10, 5, 50, 50, "../../../Assets/media/Neo_Bomberman_Logo.png");
}

void graphic::settingsMenu::printBackground()
{
    _lib->drawImage(0, 0, 640, 480, "../../../Assets/media/pixel_skyline.png");
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
    moins._y = 250;
    moins._w = 400;
    moins._h = 300;
    moins._type = IndieEvents::SOUND_UP;
    moins._path = "../../../Assets/media/moins.png";
    _lib->drawImage(200, 150, 30, 30, "../../../Assets/media/moins.png");

    _lib->drawImage(240, 130, 100, 80, "../../../Assets/media/formation-au-son-1.png");

    graphic::infos_t plus;
    plus._x = 200;
    plus._y = 250;
    plus._w = 400;
    plus._h = 300;
    plus._type = IndieEvents::SOUND_UP;
    plus._path = "../../../Assets/media/plus.png";
    _lib->drawImage(350, 150, 30, 30, "../../../Assets/media/plus.png");
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

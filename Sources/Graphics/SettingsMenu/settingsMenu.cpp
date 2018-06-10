//
// Created by Ludovica Pagliarani on 31/05/2018.
//

#include <chrono>
#include <thread>
#include <memory>
#include "settingsMenu.hpp"

graphic::settingsMenu::settingsMenu(graphic::IrrlichtLib *lib, graphic::irrKlangLib sound) : _lib(lib), _sound(sound)
{
    _count = -30;
}

void    graphic::settingsMenu::printLogo()
{
	vec2d size = _lib->getScreenSize();
	graphic::infos_t logo;
	logo._x = (size.x / 2) - 125;
	logo._y = 5;
	logo._w = (size.x / 2) + 125;
	logo._h = 200;
	logo._maxH = 250;
	logo._maxW = 250;
	logo._path = "Assets/media/Neo_Bomberman_Logo.png";
	_lib->drawImage(logo);
}

void graphic::settingsMenu::printBackground()
{
	vec2d size = _lib->getScreenSize();
    graphic::infos_t background;
    background._x = 0;
    background._y = 0;
    background._w = size.x;
    background._h = size.y;
    background._maxW = size.x;
    background._maxH = size.y;
    background._path = "Assets/media/pixel_skyline.png";
    _lib->drawImage(background);
}

void graphic::settingsMenu::printSound()
{
	vec2d size = _lib->getScreenSize();

    graphic::infos_t moins;
    moins._x = 200;
    moins._y = 150;
    moins._w = 230;
    moins._h = 180;
    moins._type = graphic::SOUND_DOWN;
    moins._desc = "Sound down";
    moins._name = "";
    moins._path = "./Assets/media/moins.png";
    _lib->printButton(moins);

    graphic::infos_t sound;
    sound._x = (size.x /2) - 100;
    sound._y = 260;
    sound._w = 200;
    sound._h = 160;
    sound._maxW = 200;
    sound._maxH = 160;
    sound._path = "./Assets/media/formation-au-son-1.png";
    _lib->drawImage(sound);

    graphic::infos_t plus;
    plus._x = 350;
    plus._y = 150;
    plus._w = 380;
    plus._h = 180;
    plus._path = "./Assets/media/plus.png";
    plus._desc = "Sound up";
    plus._name = "";
    plus._type = graphic::SOUND_UP;
    _lib->printButton(plus);
}

void graphic::settingsMenu::printBrightness()
{
    graphic::infos_t moins;
    moins._x = 200;
    moins._y = 250;
    moins._w = 230;
    moins._h = 280;
    moins._type = graphic::BRIGTHNESS_DOWN;
    moins._desc = "Light down";
    moins._name = "";
    moins._path = "./Assets/media/moins.png";
    _lib->printButton(moins);

    graphic::infos_t light;
    light._x = 240;
    light._y = 230;
    light._w = 100;
    light._h = 80;
    light._maxW = 100;
    light._maxH = 80;
    light._path = "./Assets/media/lantern.png";
    _lib->drawImage(light);

    graphic::infos_t plus;
    plus._x = 350;
    plus._y = 250;
    plus._w = 380;
    plus._h = 280;
    plus._path = "./Assets/media/plus.png";
    plus._desc = "Light up";
    plus._name = "";
    plus._type = graphic::BRIGTHNESS_UP;
    _lib->printButton(plus);
}

void    graphic::settingsMenu::returnToMenu()
{
    graphic::infos_t buttonExit;
    buttonExit._x = 200;
    buttonExit._y = 330;
    buttonExit._w = 380;
    buttonExit._h = 360;
    buttonExit._path = "Assets/media/button_menu.png";
    buttonExit._desc = "Return to main menu";
    buttonExit._name = "Quit";
    buttonExit._type = graphic::controllerUser::EXIT_SETTINGS;
    _lib->printButton(buttonExit);
}

irr::gui::IGUIImage *graphic::settingsMenu::printClouds()
{
    graphic::infos_t cloudsInfos;
    cloudsInfos._x = 0;
    cloudsInfos._y = 0;
    cloudsInfos._w = 50;
    cloudsInfos._h = 50;
    cloudsInfos._maxH = 150;
    cloudsInfos._maxW = 150;
    cloudsInfos._path = "Assets/media/clouds.png";
    irr::gui::IGUIImage *clouds =  _lib->drawImage(cloudsInfos);
    return (clouds);
}

void    graphic::settingsMenu::startClouds()
{
    if (_count < 700) {
        auto rect = irr::core::position2d<int>(_count, 50);
        _clouds->setRelativePosition(rect);
    }
    if (_count == 700)
        _count = -30;
}

void    graphic::settingsMenu::modifyBrightness(graphic::Action action)
{
    if (action == graphic::MORE)
        _lib->modifyLight(10);
    else if (action == graphic::LESS)
        _lib->modifyLight(-10);
}

void    graphic::settingsMenu::modifySound(graphic::Action)
{

}

void    graphic::settingsMenu::quitSettingsMenu(graphic::Action)
{

}

void    graphic::settingsMenu::display()
{
    printBackground();
    _clouds = printClouds();
    printLogo();
}

void graphic::settingsMenu::updateDisplay()
{
    startClouds();
    printSound();
    printBrightness();
    returnToMenu();
    _count += 10;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

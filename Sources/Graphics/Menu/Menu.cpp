/*
** EPITECH PROJECT, 2018
** indie
** File description:
** source
*/

#include <chrono>
#include <thread>
#include "Menu.hpp"

graphic::Menu::Menu(graphic::IrrlichtLib *lib) : _lib(lib)
{
    _count = -30;
}

void    graphic::Menu::drawChoiceButtons()
{
    graphic::infos_t buttonPlay;
    buttonPlay._x = 200;
    buttonPlay._y = 250;
    buttonPlay._w = 400;
    buttonPlay._h = 280;
    buttonPlay._path = "Assets/media/button_menu.png";
    buttonPlay._desc = "Play the game";
    buttonPlay._name = "Play";
    buttonPlay._type = graphic::START_SOLO;
    _lib->printButton(buttonPlay);

    graphic::infos_t buttonChoise;
    buttonChoise._x = 200;
    buttonChoise._y = 310;
    buttonChoise._w = 400;
    buttonChoise._h = 340;
    buttonChoise._path = "Assets/media/button_menu.png";
    buttonChoise._desc = "Change settings game";
    buttonChoise._name = "Settings";
    buttonChoise._type = graphic::SETTINGS;
    _lib->printButton(buttonChoise);

    graphic::infos_t buttonExit;
    buttonExit._x = 200;
    buttonExit._y = 360;
    buttonExit._w = 400;
    buttonExit._h = 390;
    buttonExit._path = "Assets/media/button_menu.png";
    buttonExit._desc = "Exit the game";
    buttonExit._name = "Quit";
    buttonExit._type = graphic::EXIT_MAINMENU;
    _lib->printButton(buttonExit);
}

irr::gui::IGUIImage *graphic::Menu::drawDirigible()
{
    graphic::infos_t dirgInfos;
    dirgInfos._x = 0;
    dirgInfos._y = 0;
    dirgInfos._w = 50;
    dirgInfos._h = 50;
    dirgInfos._maxH = 150;
    dirgInfos._maxW = 150;
    dirgInfos._path = "Assets/media/dirigible.png";
	irr::gui::IGUIImage *dirigible =  _lib->drawImage(dirgInfos);
	return (dirigible);
}

void    graphic::Menu::startDirigible()
{
    if (_count < 700) {
        auto rect = irr::core::position2d<int>(_count, 50);
        _dirigible->setRelativePosition(rect);
    }
    if (_count == 700)
        _count = -30;
}

void    graphic::Menu::printLogo()
{
    graphic::infos_t logo;
    logo._x = 150;
    logo._y = 5;
    logo._w = 200;
    logo._h = 200;
    logo._maxH = 250;
    logo._maxW = 250;
    logo._path = "Assets/media/Neo_Bomberman_Logo.png";
	_lib->drawImage(logo);
}

void graphic::Menu::printBackground()
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

void    graphic::Menu::printUserName()
{
    graphic::infos_t infos;
    infos._name = "your bomberName";
    infos._x = 200;
    infos._y = 200;
    infos._w = 400;
    infos._h = 230;
    _lib->drawEditBox(infos);
}

void    graphic::Menu::display()
{
    printBackground();
    printUserName();
    drawChoiceButtons();
    _dirigible = drawDirigible();
}

void graphic::Menu::updateDisplay()
{
    startDirigible();
    printLogo();
    _count += 10;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

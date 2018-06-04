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
    buttonPlay._type = IndieEvents::START_SOLO;
    _lib->printButton(buttonPlay);

    graphic::infos_t buttonChoise;
    buttonChoise._x = 200;
    buttonChoise._y = 310;
    buttonChoise._w = 400;
    buttonChoise._h = 340;
    buttonChoise._path = "Assets/media/button_menu.png";
    buttonChoise._desc = "Change settings game";
    buttonChoise._name = "Settings";
    buttonChoise._type = IndieEvents::SETTINGS;
    _lib->printButton(buttonChoise);

    graphic::infos_t buttonExit;
    buttonExit._x = 200;
    buttonExit._y = 360;
    buttonExit._w = 400;
    buttonExit._h = 390;
    buttonExit._path = "Assets/media/button_menu.png";
    buttonExit._desc = "Exit the game";
    buttonExit._name = "Quit";
    buttonExit._type = IndieEvents::EXIT_MAINMENU;
    _lib->printButton(buttonExit);
}

irr::gui::IGUIImage *graphic::Menu::drawDirigible()
{
	irr::gui::IGUIImage *dirigible =  _lib->drawImage(0, 0, 50, 50, "Assets/media/dirigible.png");
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
	_lib->drawImage(150, 5, 200, 200, "Assets/media/Neo_Bomberman_Logo.png");
}

void graphic::Menu::printBackground()
{
	_lib->drawImage(0, 0, 640, 480, "Assets/media/pixel_skyline.png");
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
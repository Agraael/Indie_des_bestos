/*
** EPITECH PROJECT, 2018
** indie
** File description:
** source
*/

#include <chrono>
#include <thread>
#include "ResumeGame.hpp"

graphic::ResumeGame::ResumeGame(graphic::IrrlichtLib *lib) : _lib(lib)
{
    _count = -30;
}

void    graphic::ResumeGame::drawChoiceButtons()
{
    graphic::infos_t buttonExit;
    buttonExit._x = 200;
    buttonExit._y = 360;
    buttonExit._w = 400;
    buttonExit._h = 390;
    buttonExit._path = "Assets/media/button_menu.png";
    buttonExit._desc = "Return to menu";
    buttonExit._name = "RETURN TO MENU";
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
    logo._x = 5;
    logo._y = 5;
    logo._w = 100;
    logo._h = 100;
    logo._maxH = 100;
    logo._maxW = 100;
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
    background._maxW = _lib.getHeight();
    background._maxH = 580;
    background._path = "Assets/media/pixel_skyline.png";
	_lib->drawImage(background);
}

void    graphic::Menu::display()
{
    printBackground();
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

/*
** EPITECH PROJECT, 2018
** indie
** File description:
** source
*/

#include <chrono>
#include <thread>
#include "Menu.hpp"

graphic::Menu::Menu()
{
}

void    graphic::Menu::drawChoiceButtons()
{
    graphic::infos_t buttonExit;
    buttonExit._x = 200;
    buttonExit._y = 240;
    buttonExit._w = 400;
    buttonExit._h = 280;
    buttonExit._path = "./media/button_menu.png";
    buttonExit._desc = "Exit the game";
    buttonExit._name = "Quit";
    buttonExit._type = graphic::GUI_ID_QUIT_BUTTON;
    _lib.printButton(buttonExit);

    /*graphic::Button settingButton("Settings", "Settings of game", 200, 300);
    settingButton.setHeight(340);
    settingButton.setType(graphic::GUI_ID_QUIT_BUTTON);
    _lib.printButton(settingButton, "./media/button_menu.png");*/
}

irr::gui::IGUIImage *graphic::Menu::drawDirigible()
{
    irr::gui::IGUIImage *dirigible = _lib.drawImage(-30, 50, 50, 50, "./media/dirigible.png");
    return (dirigible);
}

void    graphic::Menu::startDirigible(irr::gui::IGUIImage *dirigible, size_t &i)
{
    if (i < 700) {
        auto rect = irr::core::position2d<int>(i, 50);
        dirigible->setRelativePosition(rect);
    }
    if (i == 700)
        i = -30;
}

void    graphic::Menu::printLogo()
{
    _lib.drawImage(150, 5, 200, 200, "./media/Neo_Bomberman_Logo.png");
}

void graphic::Menu::printBackground()
{
    _lib.drawImage(0, 0, 640, 480, "./media/pixel_skyline.png");
}

void    graphic::Menu::printUserName()
{
    //_guiEnv->addEditBox(L"your bomberName", irr::core::rect<irr::s32>(200, 200, 400, 230));
}

void    graphic::Menu::display()
{
    printBackground();
    printUserName();
    drawChoiceButtons();
    irr::gui::IGUIImage *dirigible = drawDirigible();
    size_t i = -30;
    while (_lib.getDevice()->run()) {
         startDirigible(dirigible, i);
        printLogo();
        _lib.displayAll();
        i += 10;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

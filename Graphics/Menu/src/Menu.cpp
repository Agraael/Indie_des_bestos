/*
** EPITECH PROJECT, 2018
** indie
** File description:
** source
*/

#include "Menu.hpp"

graphic::Menu::Menu()
{
    _device = _lib.getDevice();
    _guiEnv = _lib.getGuiEnv();
    _driver = _lib.getDriver();
    _managerScene = _lib.getManagerScene();
}

void    graphic::Menu::drawChoiceButtons()
{
    _guiEnv->addButton(irr::core::rect<irr::s32>(200,240,400,280), 0, graphic::GUI_ID_QUIT_BUTTON, L"Quit", L"Exits game");
    _guiEnv->addButton(irr::core::rect<irr::s32>(200,300,400,340), 0, graphic::GUI_ID_NEW_WINDOW_BUTTON,
                   L"Play Game", L"Launches a new game");
}

void    graphic::Menu::drawDirigible()
{
    /*irr::gui::IGUIImage *dirigible = _guiEnv->addImage(_driver->getTexture("./media/dirigible.png"), irr::core::position2d<int>(0,100));
    dirigible->setScaleImage(true);
    dirigible->setMinSize(irr::core::dimension2du(300,300));
    dirigible->setMaxSize(irr::core::dimension2du(400,400));
    for (size_t i; i < 640; i += 50) {
        dirigible->setRelativePosition(irr::core::rect<irr::s32>(irr::core::position2d<int>(i,100)),irr::core::dimension2d<irr::s32>(300,300));
    }*/
}

void    graphic::Menu::printLogo()
{
    irr::gui::IGUIImage *image = _guiEnv->addImage(_driver->getTexture("./media/Neo_Bomberman_Logo.png"), irr::core::position2d<int>(150,5));
    image->setScaleImage(true);
    image->setMinSize(irr::core::dimension2du(200,200));
    image->setMaxSize(irr::core::dimension2du(600,600));
}

void graphic::Menu::printBackground()
{
    irr::gui::IGUIImage *background = _guiEnv->addImage(_driver->getTexture("./media/pixel_skyline.png"), irr::core::position2d<int>(0,0));
    background->setScaleImage(true);
    background->setMinSize(irr::core::dimension2du(640,480));
    background->setMaxSize(irr::core::dimension2du(640,480));
}

void    graphic::Menu::printUserName()
{
    _guiEnv->addEditBox(L"your bomberName", irr::core::rect<irr::s32>(200, 200, 400, 230));
}

void    graphic::Menu::display()
{
    printBackground();
    drawDirigible();
    printLogo();
    printUserName();
    drawChoiceButtons();
    while (_device->run()) {
        _lib.displayAll();
    }
}

graphic::Menu::~Menu()
{
}
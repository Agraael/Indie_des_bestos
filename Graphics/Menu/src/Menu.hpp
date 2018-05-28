//
// Created by Ludovica Pagliarani on 08/05/2018.
//

#ifndef MENU_HPP
#define MENU_HPP

#include "IrrlichtLib.hpp"
#include "LibEventManager.hpp"

namespace graphic
{
    class Menu
    {
        irr::IrrlichtDevice *_device;
        irr::video::IVideoDriver* _driver;
        irr::gui::IGUIEnvironment* _guiEnv;
        irr::scene::ISceneManager* _managerScene;
        graphic::IrrlichtLib _lib;
    public:
        Menu();
        ~Menu();
        void printLogo();
        void drawChoiceButtons();
        void drawDirigible();
        void printBackground();
        void printUserName();
        void display();
        void drawChoice();
    };
}

#endif //MENU_HPP

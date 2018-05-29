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
        graphic::IrrlichtLib _lib;
    public:
        Menu();
        ~Menu() = default;
        void printLogo();
        void startDirigible(irr::gui::IGUIImage *dirigible, size_t &i);
        void drawChoiceButtons();
        irr::gui::IGUIImage *drawDirigible();
        void printBackground();
        void printUserName();
        void display();
        void drawChoice();
    };
}

#endif //MENU_HPP

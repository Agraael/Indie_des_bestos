//
// Created by Ludovica Pagliarani on 08/05/2018.
//

#ifndef MENU_HPP
#define MENU_HPP

#include "../../lib/src/IrrlichtLib.hpp"
#include "../../lib/src/LibEventManager.hpp"

namespace graphic
{

    class Menu
    {
    public:
        Menu(graphic::IrrlichtLib *lib);
        ~Menu() = default;
        void printLogo();
        void startDirigible();
        void drawChoiceButtons();
        irr::gui::IGUIImage *drawDirigible();
        void printBackground();
        void printUserName();
        void display();
        void updateDisplay();
        void drawChoice();
    private:
        graphic::IrrlichtLib *_lib;
        irr::gui::IGUIImage *_dirigible;
        size_t _count;
    };
}

#endif //MENU_HPP

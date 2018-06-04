//
// Created by Ludovica Pagliarani on 31/05/2018.
//

#ifndef SETTINGSMENU_HPP
#define SETTINGSMENU_HPP

#include "IrrlichtLib.hpp"
#include "EventManager.hpp"

namespace graphic
{

    class settingsMenu
    {
    public:
        settingsMenu(graphic::IrrlichtLib *lib);
        ~settingsMenu() = default;
        void printLogo();
        void brightnessBar();
        void printBackground();
        void display();
        void updateDisplay();
        void printSound();
    private:
        graphic::IrrlichtLib *_lib;
        irr::gui::IGUIImage *_dirigible;
        size_t _count;
    };
}

#endif //SETTINGSMENU_HPP

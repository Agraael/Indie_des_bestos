//
// Created by Ludovica Pagliarani on 31/05/2018.
//

#ifndef LOCALSMENU_HPP
#define LOCALSMENU_HPP

#include <functional>
#include <unordered_map>
#include "IrrlichtLib.hpp"
#include "EventManager.hpp"

namespace graphic
{
    class localMenu {
    public:
        localMenu(graphic::IrrlichtLib *lib);
        ~localMenu() = default;
        void printLogo();
        void startClouds();
        irr::gui::IGUIImage *printClouds();
        void printBackground();
        void display();
        void returnToMenu();
        void updateDisplay();
        void printChoicePlayers();
        void printChoiceIA();
        //std::unordered_map <graphic::controllerUser, std::function<void(graphic::IrrlichtLib&)>> getEventTab() { return _eventTab; };
    private:
        graphic::IrrlichtLib *_lib;
        irr::gui::IGUIImage *_clouds;
        size_t _count;
        /*const std::unordered_map <graphic::controllerUser, std::function<void(graphic::IrrlichtLib&)>> _eventTab =
                {
                        {graphic::BRIGTHNESS_DOWN, [](graphic::IrrlichtLib &_lib){ _lib.modifyLight(-10); }},
                        {graphic::BRIGTHNESS_UP, [](graphic::IrrlichtLib &_lib){ _lib.modifyLight(10); }},
                        {graphic::SOUND_DOWN, [](graphic::IrrlichtLib &_lib){ _lib = _lib; }},
                        {graphic::SOUND_UP, [](graphic::IrrlichtLib &_lib){ _lib = _lib; }},
                        //{graphic::EXIT_MAINMENU, [](graphic::IrrlichtLib &_lib){}},
        };*/
    };
}

#endif //LOCALMENU_HPP

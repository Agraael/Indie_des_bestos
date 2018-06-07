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
        void playGame();
        void choiceMap();
        void choiceSizeMap();
        void updateDisplay();
        void printChoicePlayers();
        void printChoiceIA();
        //std::unordered_map <graphic::controllerUser, std::function<void(graphic::IrrlichtLib&)>> getEventTab() { return _eventTab; };
    private:
        graphic::IrrlichtLib *_lib;
        irr::gui::IGUIImage *_clouds;
        size_t _count;
        const std::unordered_map <graphic::controllerUser, std::function<void()>> _eventTab =
                {
                        {graphic::LARGE_MAP, [this](){ _size = LARGE; }},
                        {graphic::BRIGTHNESS_UP, [this](){ _size = SMALL; }},
                        {graphic::SOUND_DOWN, [this](){ _size = MEDIUM; }},
                        {graphic::SOUND_UP, [](){ }},
                        //{graphic::EXIT_MAINMENU, [](graphic::IrrlichtLib &_lib){}},
        };
    };
}

#endif //LOCALMENU_HPP

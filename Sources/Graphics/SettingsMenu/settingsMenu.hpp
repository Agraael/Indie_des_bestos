//
// Created by Ludovica Pagliarani on 31/05/2018.
//

#ifndef SETTINGSMENU_HPP
#define SETTINGSMENU_HPP

#include <functional>
#include <unordered_map>
#include "IrrlichtLib.hpp"
#include "EventManager.hpp"

namespace graphic
{
    enum Action
    {
        MORE,
        LESS
    };
    class settingsMenu {
    public:
        settingsMenu(graphic::IrrlichtLib *lib);
        ~settingsMenu() = default;
        void printLogo();
        void brightnessBar();
        void startClouds();
        irr::gui::IGUIImage *printClouds();
        void printBackground();
        void display();
        void printBrightness();
        void returnToMenu();
        void updateDisplay();
        void printSound();
        void modifyBrightness(graphic::Action);
        void modifySound(graphic::Action);
        void quitSettingsMenu(graphic::Action);
        std::unordered_map <graphic::controllerUser, std::function<void(graphic::IrrlichtLib&)>> getEventTab() { return _eventTab; };
    private:
        graphic::IrrlichtLib *_lib;
        irr::gui::IGUIImage *_clouds;
        size_t _count;
        const std::unordered_map <graphic::controllerUser, std::function<void(graphic::IrrlichtLib&)>> _eventTab =
                {
                        {graphic::BRIGTHNESS_DOWN, [](graphic::IrrlichtLib &_lib){ _lib.modifyLight(-10); }},
                        {graphic::BRIGTHNESS_UP, [](graphic::IrrlichtLib &_lib){ _lib.modifyLight(10); }},
                        {graphic::SOUND_DOWN, [](graphic::IrrlichtLib &_lib){ _lib->setVolume(_lib->getVolume() - 0.1); }},
                        {graphic::SOUND_UP, [](graphic::IrrlichtLib &_lib){ _lib->setVolume(_lib->getVolume() + 0.1); }},
                        //{graphic::EXIT_MAINMENU, [](graphic::IrrlichtLib &_lib){}},
        };
    };
}

#endif //SETTINGSMENU_HPP

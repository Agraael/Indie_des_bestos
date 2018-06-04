//
// Created by Ludovica Pagliarani on 31/05/2018.
//

#ifndef SETTINGSMENU_HPP
#define SETTINGSMENU_HPP

#include <unordered_map>
#include "IrrlichtLib.hpp"
#include "EventManager.hpp"

namespace graphic
{

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

    private:
        graphic::IrrlichtLib *_lib;
        irr::gui::IGUIImage *_clouds;
        size_t _count;
        const std::unordered_map <IndieEvents::IndieKeys, CoreState> _eventTab = {
                {IndieEvents::IndieKeys::SETTINGS,         CoreState::IN_SETTINGS},
                {IndieEvents::IndieKeys::EXIT_MAINMENU,    CoreState::EXIT},
                {IndieEvents::IndieKeys::START_LOCAL,      CoreState::IN_LOCAL},
                {IndieEvents::IndieKeys::START_SOLO,       CoreState::IN_SOLO},
                {IndieEvents::IndieKeys::EXIT_LOCAL,       CoreState::IN_MENU},
                {IndieEvents::IndieKeys::MENU,             CoreState::IN_MENU},
                {IndieEvents::IndieKeys::START_LOCAL_GAME, CoreState::IN_LOCAL_GAME},
                {IndieEvents::IndieKeys::RESTART,          CoreState::IN_LOCAL_GAME},
                {IndieEvents::IndieKeys::QUIT,             CoreState::IN_MENU},
                {IndieEvents::IndieKeys::ECHAP,            CoreState::GAME_PAUSE}
        };
    };
}

#endif //SETTINGSMENU_HPP

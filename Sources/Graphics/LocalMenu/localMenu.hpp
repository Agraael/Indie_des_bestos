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
    enum sizeMap {
        SMALL,
        MEDIUM,
        LARGE
    };
    enum entityMap {
        STANDARD,
        DISTRUCTIBLE
    };
    class localMenu {
    public:
        localMenu(graphic::IrrlichtLib *lib);
        ~localMenu() = default;
        void printLogo();
        void startClouds();
        irr::gui::IGUIImage *printClouds();
        void printBackground();
        void display();
        void setNbrPlayer(int nbr);
        void setNbrIa(int nbr);
        void returnToMenu();
        void playGame();
        void choiceMap();
        void choiceSizeMap();
        void updateDisplay();
        void printChoicePlayers();
        void printChoiceIA();
        size_t getIaNbr() { return _nbrIa; }
        size_t getPlayersNbr() { return _nbrPlayers; }
        graphic::sizeMap getMapSize() { return _sizeMap; }
        graphic::entityMap getEntityMap() { return _entityMap; }
        void printNbrChoice(int nbr, graphic::infos_t *nbrEntity, irr::gui::IGUIImage *img);
        std::unordered_map <graphic::controllerUser, std::function<void()>> getEventTab() { return _eventTab; };
    private:
        graphic::IrrlichtLib *_lib;
        irr::gui::IGUIImage *_clouds;
        graphic::sizeMap _sizeMap;
        graphic::entityMap _entityMap;
        size_t _nbrIa;
        size_t _nbrPlayers;
        irr::gui::IGUIImage *_iaNbrImg;
        irr::gui::IGUIImage *_playerNbrImg;
        graphic::infos_t _infosPlayers;
        graphic::infos_t _infosIa;

        const std::unordered_map <graphic::controllerUser, std::function<void()>> _eventTab =
                {
                        {graphic::LARGE_MAP, [this](){ _sizeMap = LARGE; }},
                        {graphic::SMALL_MAP, [this](){ _sizeMap = SMALL; }},
                        {graphic::MEDIUM_MAP, [this](){ _sizeMap = MEDIUM; }},
                        {graphic::DIST_MAP, [this](){ _entityMap = DISTRUCTIBLE; }},
                        {graphic::STAND_MAP, [this](){ _entityMap = STANDARD; }},
                        {graphic::MORE_PLAYER, [this](){ setNbrPlayer(1); }},
                        {graphic::LESS_PLAYER, [this](){ setNbrPlayer(-1); }},
                        {graphic::MORE_IA, [this](){ setNbrIa(1); }},
                        {graphic::LESS_IA, [this](){ setNbrIa(-1); }},
                        {graphic::EXIT_MAINMENU, [](){}},
        };
    };
}

#endif //LOCALMENU_HPP

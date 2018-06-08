/*
** EPITECH PROJECT, 2018
** indie
** File description:
** source
*/

#include <string>
#include <experimental/filesystem>
#include <chrono>
#include <thread>
#include "resumeGame.hpp"

graphic::ResumeGame::ResumeGame(graphic::IrrlichtLib *lib) : _lib(lib)
{
    _size = _lib->getScreenSize();
    _count = 0;
}

void    graphic::ResumeGame::drawChoiceButtons()
{
    graphic::infos_t buttonExit;
    buttonExit._x = 200;
    buttonExit._y = 360;
    buttonExit._w = 400;
    buttonExit._h = 390;
    buttonExit._path = "Assets/media/button_menu.png";
    buttonExit._desc = "Return to ResumeGame";
    buttonExit._name = "RETURN TO ResumeGame";
    buttonExit._type = graphic::EXIT_MAINMENU;
    _lib->printButton(buttonExit);
}

irr::gui::IGUIImage *graphic::ResumeGame::drawDirigible()
{
    graphic::infos_t dirgInfos;
    dirgInfos._x = 0;
    dirgInfos._y = 0;
    dirgInfos._w = 50;
    dirgInfos._h = 50;
    dirgInfos._maxH = 150;
    dirgInfos._maxW = 150;
    dirgInfos._path = "Assets/media/dirigible.png";
	irr::gui::IGUIImage *dirigible =  _lib->drawImage(dirgInfos);
	return (dirigible);
}

void    graphic::ResumeGame::startDirigible()
{
    if (_count < _size.x) {
        auto rect = irr::core::position2d<int>(_count, 50);
        _dirigible->setRelativePosition(rect);
    }
    if (_count == _size.x)
        _count = -30;
}

void    graphic::ResumeGame::printLogo()
{
    graphic::infos_t logo;
    logo._x = 5;
    logo._y = 5;
    logo._w = 100;
    logo._h = 100;
    logo._maxH = 100;
    logo._maxW = 100;
    logo._path = "Assets/media/Neo_Bomberman_Logo.png";
	_lib->drawImage(logo);
}

void    graphic::ResumeGame::saveFilesToVector()
{
    std::string path = "./gameMap/";
    for (auto &p : std::experimental::filesystem::directory_iterator(path)) {
        std::ostringstream str;
        str << p;
        std::string name = str.str();
        name = name.substr(11, name.size());
        _fileName.push_back(name);
    }
}

void    graphic::ResumeGame::printListBox()
{
    graphic::infos_t mapImg;
    mapImg._x = 200;
    mapImg._y = 100;
    mapImg._w = 300;
    mapImg._h = 100;
    mapImg._maxH = 100;
    mapImg._maxW = 300;
    mapImg._path = "Assets/media/load_your_map.png";
    _lib->drawImage(mapImg);

    saveFilesToVector();
    graphic::infos_t plus;
    plus._x = (_size.x / 2) + 50;
    plus._y = 100;
    plus._w = (_size.x / 2) + 90;
    plus._h = 150;
    plus._type = graphic::controllerUser::PLAYER_UP;
    plus._desc = "";
    plus._name = "";
    plus._path = "./Assets/media/right_arrow.png";
    _lib->printButton(plus);

    _lib->drawText((_size.x / 2) , 110, 30, _fileName[0]);

    graphic::infos_t minus;
    minus._x = (_size.x / 2) - 50;
    minus._y = 100;
    minus._w = (_size.x / 2) - 10;
    minus._h = 150;
    minus._type = graphic::controllerUser::PLAYER_DOWN;
    minus._desc = "";
    minus._name = "";
    minus._path = "./Assets/media/left_arrow.png";
    _lib->printButton(minus);
}

void graphic::ResumeGame::printBackground()
{
    graphic::infos_t background;
    background._x = 0;
    background._y = 0;
    background._w = 640;
    background._h = 480;
    background._maxW = _size.x;
    background._maxH = _size.y;
    background._path = "Assets/media/pixel_skyline.png";
	_lib->drawImage(background);
}

void    graphic::ResumeGame::display()
{
    printBackground();
    printListBox();
    drawChoiceButtons();
    _dirigible = drawDirigible();
}

void graphic::ResumeGame::updateDisplay()
{
    startDirigible();
    printLogo();
    _count += 10;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

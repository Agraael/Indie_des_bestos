OB/*
  ** EPITECH PROJECT, 2018
  ** indie
  ** File description:
  ** source
  */

#include <string>
#include <experimental/filesystem>
#include <chrono>
#include <thread>
#include <sstream>
#include "resumeGame.hpp"

graphic::ResumeGame::ResumeGame(graphic::IrrlichtLib *lib) : _lib(lib)
{
	_itFiles = 0;
	_size = _lib->getScreenSize();
	_count = 0;
}

void    graphic::ResumeGame::drawChoiceButtons()
{
    graphic::infos_t buttonPlay;
    buttonPlay._x = (_size.x / 2) - 100;
    buttonPlay._y = 400;
    buttonPlay._w = (_size.x / 2) + 100;
    buttonPlay._h = 450;
    buttonPlay._path = "Assets/media/button_menu.png";
    buttonPlay._desc = "Play the game";
    buttonPlay._name = "PLAY THE GAME";
    buttonPlay._type = graphic::controllerUser::START_LOCAL_GAME;
    _lib->printButton(buttonPlay);

    graphic::infos_t buttonExit;
    buttonExit._x = (_size.x / 2) - 100;
    buttonExit._y = 500;
    buttonExit._w = (_size.x / 2) + 100;
    buttonExit._h = 550;
    buttonExit._path = "Assets/media/button_menu.png";
    buttonExit._desc = "Return to MENU";
    buttonExit._name = "RETURN TO MENU";
    buttonExit._type = graphic::controllerUser::MENU;
    _lib->printButton(buttonExit);

}

irr::gui::IGUIImage *graphic::ResumeGame::drawDirigible()
{
    graphic::infos_t dirgInfos;
    dirgInfos._x = 0;
    dirgInfos._y = 0;
    dirgInfos._w = 30;
    dirgInfos._h = 30;
    dirgInfos._maxH = 100;
    dirgInfos._maxW = 100;
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
        _fileName = str.str();
        _files.push_back(_fileName);
    }
}

void    graphic::ResumeGame::drawFileName()
{
    std::string name(_fileName);
    name = name.substr(11, name.size());
    std::transform(name.begin(), name.end(),name.begin(), ::toupper);
    int i = (_size.x / 2) - 100;
    for (auto &character : name) {
        graphic::infos_t letter;
        letter._x = i;
        letter._y = 310;
        letter._w = 30;
        letter._h = 30;
        letter._maxH = 30;
        letter._maxW = 30;
        std::unordered_map<char,std::string>::iterator it =  _alphaMap.find(character);
        if (it != _alphaMap.end()) {
            letter._path = _alphaMap[character];
            auto img = _lib->drawImage(letter);
           _filesImg.push_back(img);
            i += 25;
        }
    }
}

void    graphic::ResumeGame::removeImgFiles()
{
    for (auto &img : _filesImg) {
        img->remove();
    }
    _filesImg.clear();
}

void    graphic::ResumeGame::manageFiles(int nbr)
{
    removeImgFiles();
    if (nbr == 1 && _itFiles == (_files.size() - 1))
        _itFiles = 0;
    else if (nbr == -1 && _itFiles == 0)
        _itFiles = _files.size() - 1;
    else
        _itFiles += nbr;
    _fileName = _files[_itFiles];
    drawFileName();
}

void    graphic::ResumeGame::printListBox()
{
    graphic::infos_t mapImg;
    mapImg._x = (_size.x / 2) - 150;
    mapImg._y = 100;
    mapImg._w = 300;
    mapImg._h = 100;
    mapImg._maxH = 100;
    mapImg._maxW = 300;
    mapImg._path = "Assets/media/load_your_map.png";
    _lib->drawImage(mapImg);

    saveFilesToVector();

    graphic::infos_t minus;
    minus._x = (_size.x / 2) - 150;
    minus._y = 300;
    minus._w = (_size.x / 2) - 100;
    minus._h = 350;
    minus._type = graphic::controllerUser::PREV_FILE;
    minus._desc = "";
    minus._name = "";
    minus._path = "./Assets/media/left_arrow.png";
    _lib->printButton(minus);

    drawFileName();

    graphic::infos_t plus;
    plus._x = (_size.x / 2) + 150;
    plus._y = 300;
    plus._w = (_size.x / 2) + 200;
    plus._h = 350;
    plus._type = graphic::controllerUser::NEXT_FILE;
    plus._desc = "";
    plus._name = "";
    plus._path = "./Assets/media/right_arrow.png";
    _lib->printButton(plus);
}

void graphic::ResumeGame::printBackground()
{
    graphic::infos_t background;
    background._x = 0;
    background._y = 0;
    background._w = _size.x;
    background._h = _size.y;
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
    for (auto elem : _manageEvent) {
        if (_lib->getEventManager()->IsButtonClicked(elem.first) == true) {
            elem.second();
        }
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

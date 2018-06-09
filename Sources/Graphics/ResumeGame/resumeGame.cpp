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
    graphic::infos_t buttonPlay;
    buttonPlay._x = (_size.x / 2) - 300;
    buttonPlay._y = 400;
    buttonPlay._w = (_size.x / 2) - 100;
    buttonPlay._h = 430;
    buttonPlay._path = "Assets/media/button_menu.png";
    buttonPlay._desc = "Play the game";
    buttonPlay._name = "PLAY THE GAME";
    buttonPlay._type = graphic::EXIT_MAINMENU;
    _lib->printButton(buttonPlay);

    graphic::infos_t buttonExit;
    buttonExit._x = (_size.x / 2) - 300;
    buttonExit._y = 460;
    buttonExit._w = (_size.x / 2) - 100;
    buttonExit._h = 490;
    buttonExit._path = "Assets/media/button_menu.png";
    buttonExit._desc = "Return to MENU";
    buttonExit._name = "RETURN TO MENU";
    buttonExit._type = graphic::EXIT_MAINMENU;
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
    int i = (_size.x / 2) - 270;
    for (auto &character : fileName) {
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
           _fileImg =  _lib->drawImage(letter);
            i += 25;
        }
    }
}

void    graphic::ResumeGame::manageFiles(size_t nbr)
{
    _fileImg->remove();
    if (nbr == 1 && _itFiles == _filesName.size())
        _itFiles = 0;
    if (nbr == -1 && _itFiles == 0)
        _itFiles = _filesName.size();
    else
    _itFiles += nbr;
    _fileName = _files[_itFiles];
    drawFileName(_files[_itFiles]);
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

    graphic::infos_t minus;
    minus._x = (_size.x / 2) - 300;
    minus._y = 300;
    minus._w = (_size.x / 2) - 260;
    minus._h = 350;
    minus._type = IndieEvents::PREV_FILE;
    minus._desc = "";
    minus._name = "";
    minus._path = "./Assets/media/left_arrow.png";
    _lib->printButton(minus);

    drawFileName();

    graphic::infos_t plus;
    plus._x = (_size.x / 2) - 110;
    plus._y = 300;
    plus._w = (_size.x / 2) - 70;
    plus._h = 350;
    plus._type = IndieEvents::IndieKeys::NEXT_FILE;
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
    for (auto elem : _updateNumberEntity) {
        if (_lib->getEventManager()->IsButtonClicked(elem.first) == true) {
            elem.second();
            if (elem.first == graphic::controllerUser::MAP_SIZE_DOWN || elem.first == graphic::controllerUser::MAP_SIZE_UP)
                printGoodOneSize();
            else if (elem.first == graphic::controllerUser::MAP_NEXT || elem.first == graphic::controllerUser::MAP_PREV)
                printGoodOneMod();
            else if (elem.first == graphic::controllerUser::PLAYER_DOWN || elem.first == graphic::controllerUser::PLAYER_UP)
                printNumber(_playerNbInfos, _playerNbImg, _playersNb);
            else if (elem.first == graphic::controllerUser::IA_DOWN || elem.first == graphic::controllerUser::IA_UP)
                printNumber(_iaNbInfos, _iaNbImg, _aisNb);
        }
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

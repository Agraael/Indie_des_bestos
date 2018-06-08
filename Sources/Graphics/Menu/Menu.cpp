/*
** EPITECH PROJECT, 2018
** indie
** File description:
** source
*/

#include <chrono>
#include <thread>
#include "Menu.hpp"

graphic::Menu::Menu(graphic::IrrlichtLib *lib) : _lib(lib)
{
	_count = -30;
}

void	graphic::Menu::drawChoiceButtons()
{
	vec2d size = _lib->getScreenSize();
	
	graphic::infos_t btnCreate;
	btnCreate._x = (size.x / 2) - 100;
	btnCreate._y = 300;
	btnCreate._w = (size.x / 2) + 100;
	btnCreate._h = 350;
	btnCreate._type = graphic::controllerUser::START_LOCAL;
	btnCreate._desc = "Create game";
	btnCreate._name = "Create game";
	btnCreate._path = "Assets/media/button_menu.png";
	_lib->printButton(btnCreate);

	graphic::infos_t btnResume;
	btnResume._x = (size.x / 2) - 100;
	btnResume._y = 400;
	btnResume._w = (size.x / 2) + 100;
	btnResume._h = 450;
	btnResume._type = graphic::controllerUser::RESUME_GAME;
	btnResume._desc = "Resume game";
	btnResume._name = "Resume game";
	btnResume._path = "Assets/media/button_menu.png";
	_lib->printButton(btnResume);

	graphic::infos_t btnSetting;
	btnSetting._x = (size.x / 2) - 100;
	btnSetting._y = 500;
	btnSetting._w = (size.x / 2) + 100;
	btnSetting._h = 550;
	btnSetting._type = graphic::SETTINGS;
	btnSetting._desc = "Change settings";
	btnSetting._name = "Settings";
	btnSetting._path = "Assets/media/button_menu.png";
	_lib->printButton(btnSetting);

	graphic::infos_t btnExit;
	btnExit._x = (size.x / 2) - 100;
	btnExit._y = 600;
	btnExit._w = (size.x / 2) + 100;
	btnExit._h = 650;
	btnExit._type = graphic::EXIT_MAINMENU;
	btnExit._desc = "Exit the game";
	btnExit._name = "Quit";
	btnExit._path = "Assets/media/button_menu.png";
	_lib->printButton(btnExit);
}

irr::gui::IGUIImage *graphic::Menu::drawDirigible()
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

void    graphic::Menu::startDirigible()
{
	if (_count < 700) {
		auto rect = irr::core::position2d<int>(_count, 50);
		_dirigible->setRelativePosition(rect);
	}
	if (_count == 700)
		_count = -30;
}

void	graphic::Menu::printLogo()
{
	vec2d size = _lib->getScreenSize();
	graphic::infos_t logo;
	logo._x = (size.x / 2) - 125;
	logo._y = 5;
	logo._w = (size.x / 2) + 125;
	logo._h = 200;
	logo._maxH = 250;
	logo._maxW = 250;
	logo._path = "Assets/media/Neo_Bomberman_Logo.png";
	_lib->drawImage(logo);
}

void graphic::Menu::printBackground()
{
	vec2d size = _lib->getScreenSize();
	graphic::infos_t background;
	background._x = 0;
	background._y = 0;
	background._w = size.x;
	background._h = size.y;
	background._maxW = size.x;
	background._maxH = size.y;
	background._path = "Assets/media/pixel_skyline.png";
	_lib->drawImage(background);
}

void    graphic::Menu::display()
{
	printBackground();
	drawChoiceButtons();
	_dirigible = drawDirigible();
}

void graphic::Menu::updateDisplay()
{
	startDirigible();
	printLogo();
	_count += 10;
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

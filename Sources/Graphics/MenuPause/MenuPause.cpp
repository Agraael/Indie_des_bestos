/*
** EPITECH PROJECT, 2018
** Indie
** File description:
** MenuPause
*/

#include "MenuPause.hpp"

graphic::MenuPause::~MenuPause()
{
}

void	graphic::MenuPause::display()
{
	printContinue();
	printQuit();
	printSave();
	printTitle();
}

void	graphic::MenuPause::updateDisplay(HandleGame &)
{
	if (_lib->getEventManager()->IsButtonClicked(graphic::controllerUser::SAVE) == true)
		std::cout << "SAVING GAME" << std::endl;
}

void	graphic::MenuPause::printTitle()
{
	graphic::infos_t title;
	vec2d size = _lib->getScreenSize();
	title._x = (size.x / 2) - 80;
	title._y = 100;
	title._w = (size.x / 2) + 100;
	title._h = 150;
	title._maxW = 150;
	title._maxH = 60;
	title._path = "Assets/media/Pausetxt.png";
	_lib->drawImage(title);
}

void	graphic::MenuPause::printContinue()
{
	graphic::infos_t btn;
	vec2d size = _lib->getScreenSize();
	btn._x = (size.x / 2) - 100;
	btn._y = 200;
	btn._w = (size.x / 2) + 100;
	btn._h = 250;
	btn._type = graphic::controllerUser::CONTINUE;
	btn._desc = "Continue";
	btn._name = "Continue";
	btn._path = "Assets/media/button_menu.png";
	_lib->printButton(btn);
}

void	graphic::MenuPause::printSave()
{
	graphic::infos_t btn;
	vec2d size = _lib->getScreenSize();
	btn._x = (size.x / 2) - 100;
	btn._y = 300;
	btn._w = (size.x / 2) + 100;
	btn._h = 350;
	btn._type = graphic::controllerUser::SAVE;
	btn._desc = "Save";
	btn._name = "Save";
	btn._path = "Assets/media/button_menu.png";
	_lib->printButton(btn);
}

void	graphic::MenuPause::printQuit()
{
	graphic::infos_t btn;
	vec2d size = _lib->getScreenSize();
	btn._x = (size.x / 2) - 100;
	btn._y = 400;
	btn._w = (size.x / 2) + 100;
	btn._h = 450;
	btn._type = graphic::controllerUser::MENU;
	btn._desc = "Quit";
	btn._name = "Quit";
	btn._path = "Assets/media/button_menu.png";
	_lib->printButton(btn);
}


//
// Created by Ludovica Pagliarani on 31/05/2018.
//

#include <chrono>
#include <thread>
#include <memory>
#include "localMenu.hpp"

void	graphic::localMenu::printGoodOneMod()
{
	if (_genModeTab[_genMode] == GenerationMod::FullDest)
		_mapModInfos._path = "./Assets/media/FullDest.png";
	else
		_mapModInfos._path = "./Assets/media/OldSchool.png";
	_mapModImg->remove();
	_mapModImg = _lib->drawImage(_mapModInfos);
}

void	graphic::localMenu::printNumber(graphic::infos_t &info, irr::gui::IGUIImage *&graph, int nb)
{
	if (nb == 0)
		info._path = "./Assets/media/zero.png";
	else if (nb == 1)
		info._path = "./Assets/media/one.png";
	else if (nb == 2)
		info._path = "./Assets/media/two.png";
	else
		info._path = "./Assets/media/three.png";
	graph->remove();
	graph = _lib->drawImage(info);
}

void	graphic::localMenu::printGoodOneSize()
{
	if (_genSizeTab[_genSize] == GenerationSize::Small)
		_mapSizeInfos._path = "./Assets/media/small.png";
	else if (_genSizeTab[_genSize] == GenerationSize::Medium)
		_mapSizeInfos._path = "./Assets/media/medium.png";
	else
		_mapSizeInfos._path = "./Assets/media/big.png";
	_mapSizeImg->remove();
	_mapSizeImg = _lib->drawImage(_mapSizeInfos);
}

void	graphic::localMenu::display()
{
	_genSize = 1;
	_genMode = 1;
	_playersNb = 1;
	_aisNb = 3;
	_name = "map";
	printBackground();
	printMenuTitle();
	printCoreButtons();
	printButtonsPlayer();
	printButtonsIa();
	printButtonsChooseMap();
}

void	graphic::localMenu::updateDisplay()
{
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
}

void	graphic::localMenu::printMapName()
{
	// textBox = new CGUITextBox(env->getFont("myfont.xml"),"",env,rect<s32>(50,120,750,500),0,-1);
	// textBox->setText("");
	// textBox->setScrollModeLines(false);
	// textBox->setVisible(true);
}

void	graphic::localMenu::printButtonsPlayer()
{
	vec2d size = _lib->getScreenSize();

	graphic::infos_t players;
	players._x = (size.x / 2) - 200;
	players._y = 300;
	players._w = (size.x / 2) - 100;
	players._h = 350;
	players._maxW = 100;
	players._maxH = 70;
	players._path = "./Assets/media/players.png";
	_lib->drawImage(players);

	graphic::infos_t plus;
	plus._x = (size.x / 2) + 50;
	plus._y = 300;
	plus._w = (size.x / 2) + 90;
	plus._h = 350;
	plus._type = graphic::controllerUser::PLAYER_UP;
	plus._desc = "";
	plus._name = "";
	plus._path = "./Assets/media/right_arrow.png";
	_lib->printButton(plus);

	_playerNbInfos._x = (size.x / 2) - 10;
	_playerNbInfos._y = 300;
	_playerNbInfos._w = 50;
	_playerNbInfos._h = 50;
	_playerNbInfos._maxW = 50;
	_playerNbInfos._maxH = 50;
	_playerNbInfos._path = "./Assets/media/one.png";
	_playerNbImg = _lib->drawImage(_playerNbInfos);

	graphic::infos_t minus;
	minus._x = (size.x / 2) - 50;
	minus._y = 300;
	minus._w = (size.x / 2) - 10;
	minus._h = 350;
	minus._type = graphic::controllerUser::PLAYER_DOWN;
	minus._desc = "";
	minus._name = "";
	minus._path = "./Assets/media/left_arrow.png";
	_lib->printButton(minus);
}

void	graphic::localMenu::printButtonsIa()
{
	vec2d size = _lib->getScreenSize();

	graphic::infos_t players;
	players._x = (size.x / 2) - 200;
	players._y = 400;
	players._w = (size.x / 2) - 150;
	players._h = 450;
	players._maxW = 40;
	players._maxH = 40;
	players._path = "./Assets/media/ia.png";
	_lib->drawImage(players);

	graphic::infos_t plus;
	plus._x = (size.x / 2) + 50;
	plus._y = 400;
	plus._w = (size.x / 2) + 90;
	plus._h = 450;
	plus._type = graphic::controllerUser::IA_UP;
	plus._desc = "";
	plus._name = "";
	plus._path = "./Assets/media/right_arrow.png";
	_lib->printButton(plus);

	_iaNbInfos._x = (size.x / 2) - 10;
	_iaNbInfos._y = 400;
	_iaNbInfos._w = 50;
	_iaNbInfos._h = 50;
	_iaNbInfos._maxW = 50;
	_iaNbInfos._maxH = 50;
	_iaNbInfos._path = "./Assets/media/three.png";
	_iaNbImg = _lib->drawImage(_iaNbInfos);

	graphic::infos_t minus;
	minus._x = (size.x / 2) - 50;
	minus._y = 400;
	minus._w = (size.x / 2) - 10;
	minus._h = 450;
	minus._type = graphic::controllerUser::IA_DOWN;
	minus._desc = "";
	minus._name = "";
	minus._path = "./Assets/media/left_arrow.png";
	_lib->printButton(minus);
}

void	graphic::localMenu::printButtonsChooseMap()
{
	vec2d size = _lib->getScreenSize();

	graphic::infos_t players;
	players._x = (size.x / 2) - 200;
	players._y = 500;
	players._w = (size.x / 2) - 100;
	players._h = 550;
	players._maxW = 100;
	players._maxH = 50;
	players._path = "./Assets/media/map.png";
	_lib->drawImage(players);

	graphic::infos_t plus;
	plus._x = (size.x / 2) + 150;
	plus._y = 500;
	plus._w = (size.x / 2) + 190;
	plus._h = 550;
	plus._type = graphic::controllerUser::MAP_NEXT;
	plus._desc = "";
	plus._name = "";
	plus._path = "./Assets/media/right_arrow.png";
	_lib->printButton(plus);

	_mapModInfos._x = (size.x / 2) - 10;
	_mapModInfos._y = 500;
	_mapModInfos._w = 150;
	_mapModInfos._h = 50;
	_mapModInfos._maxW = 160;
	_mapModInfos._maxH = 50;
	_mapModInfos._path = "./Assets/media/OldSchool.png";
	_mapModImg = _lib->drawImage(_mapModInfos);

	graphic::infos_t minus;
	minus._x = (size.x / 2) - 50;
	minus._y = 500;
	minus._w = (size.x / 2) - 10;
	minus._h = 550;
	minus._type = graphic::controllerUser::MAP_PREV;
	minus._desc = "";
	minus._name = "";
	minus._path = "./Assets/media/left_arrow.png";
	_lib->printButton(minus);

	graphic::infos_t plusS;
	plusS._x = (size.x / 2) + 320;
	plusS._y = 500;
	plusS._w = (size.x / 2) + 360;
	plusS._h = 550;
	plusS._type = graphic::controllerUser::MAP_SIZE_UP;
	plusS._desc = "";
	plusS._name = "";
	plusS._path = "./Assets/media/right_arrow.png";
	_lib->printButton(plusS);

	_mapSizeInfos._x = (size.x / 2) + 240;
	_mapSizeInfos._y = 500;
	_mapSizeInfos._w = 80;
	_mapSizeInfos._h = 50;
	_mapSizeInfos._maxW = 80;
	_mapSizeInfos._maxH = 50;
	_mapSizeInfos._path = "./Assets/media/medium.png";
	_mapSizeImg = _lib->drawImage(_mapSizeInfos);

	graphic::infos_t minusS;
	minusS._x = (size.x / 2) + 200;
	minusS._y = 500;
	minusS._w = (size.x / 2) + 240;
	minusS._h = 550;
	minusS._type = graphic::controllerUser::MAP_SIZE_DOWN;
	minusS._desc = "";
	minusS._name = "";
	minusS._path = "./Assets/media/left_arrow.png";
	_lib->printButton(minusS);
}

void	graphic::localMenu::printCoreButtons()
{
	graphic::infos_t btnStart;
	vec2d size = _lib->getScreenSize();
	btnStart._x = (size.x / 2) + 100;
	btnStart._y = 600;
	btnStart._w = (size.x / 2) + 200;
	btnStart._h = 650;
	btnStart._type = graphic::controllerUser::START_LOCAL_GAME;
	btnStart._desc = "Start";
	btnStart._name = "Start";
	btnStart._path = "Assets/media/button_menu.png";
	_lib->printButton(btnStart);

	graphic::infos_t btnReturn;
	btnReturn._x = (size.x / 2) - 200;
	btnReturn._y = 600;
	btnReturn._w = (size.x / 2) - 100;
	btnReturn._h = 650;
	btnReturn._type = graphic::controllerUser::MENU;
	btnReturn._desc = "Return to menu";
	btnReturn._name = "Return to menu";
	btnReturn._path = "Assets/media/button_menu.png";
	_lib->printButton(btnReturn);
}

void	graphic::localMenu::printMenuTitle()
{
	graphic::infos_t title;
	vec2d size = _lib->getScreenSize();
	title._x = (size.x / 2) - 80;
	title._y = 100;
	title._w = (size.x / 2) + 100;
	title._h = 150;
	title._maxW = 150;
	title._maxH = 60;
	title._path = "Assets/media/TitleCreateGame.png";
	_lib->drawImage(title);
}

void	graphic::localMenu::printBackground()
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

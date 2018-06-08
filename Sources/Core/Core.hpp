/*
** EPITECH PROJECT, 2018
** indie
** File description:
** header
*/

#ifndef CORE_HPP_
	#define CORE_HPP_

#include <unordered_map>
#include <functional>
#include "HandleGame.hpp"
#include "EventCore.hpp"
#include "Menu.hpp"
#include "settingsMenu.hpp"
#include "IrrlichtLib.hpp"
#include "EventManager.hpp"

class Core
{
public:
	Core();
	~Core();
	int	run();
private:
	void	chooseCorePart(const CoreState &);
	void	menu(const CoreState &);
	void	gameLocal(const CoreState &);
	void	gameSolo(const CoreState &);
	void	menuSetting(const CoreState &);
	void	menuLocal(const CoreState &);
	int	exitCore();

	CoreState			_state;
	graphic::IrrlichtLib		*_lib;
	EventCore			_eventCore;
	graphic::Menu			*_menu;
	HandleGame			hGame;
	graphic::settingsMenu		*_menuSetting;
	bool				_playing;
	//using ptr = void	(Core::*)(const CoreState &);
	//const std::unordered_map<CoreState, ptr>	_fcnTab = {
	//	{CoreState::IN_MENU, &menu},
	//	{CoreState::IN_SETTINGS, &menu_setting},
	//	{CoreState::IN_LOCAL, &menu_local},
	//	{CoreState:: IN_SOLO, &game_solo},
	//	{CoreState::IN_LOCAL_GAME, &game_local}
	//};
};

#endif /* !CORE_HPP_ */

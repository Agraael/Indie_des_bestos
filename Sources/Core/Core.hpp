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
	void	game_local(const CoreState &);
	void	game_solo(const CoreState &);
	void	menu_setting(const CoreState &);
	void	menu_local(const CoreState &);
	int	exitCore();

	CoreState			_state;
	graphic::IrrlichtLib		*_lib;
	EventCore			_eventCore;
	graphic::Menu			*_menu;
	HandleGame			hGame;
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

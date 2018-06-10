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
#include "localMenu.hpp"
#include "MenuPause.hpp"
#include "IrrlichtLib.hpp"
#include "resumeGame.hpp"
#include "EventManager.hpp"
class Core
{
public:
	Core();
	~Core();
	int	run();
private:
	void	chooseCorePart(const CoreState &);
	void	game(const CoreState &);
	void	menu(const CoreState &);
	void	menuResume(const CoreState &);
	void	menuSetting(const CoreState &);
	void	menuCreateGame(const CoreState &);
	void	menuGamePaused(const CoreState &);
	void    reset();

	CoreState			_state;
	graphic::IrrlichtLib		*_lib;
	EventCore			_eventCore;
	graphic::Menu			*_menu;
	HandleGame			*hGame;
	graphic::settingsMenu		*_menuSetting;
	graphic::localMenu		*_menuCreateGame;
	graphic::MenuPause		*_menuPause;
	graphic::ResumeGame		*_menuResume;
	bool				_playing;
	bool				_gamePaused;
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

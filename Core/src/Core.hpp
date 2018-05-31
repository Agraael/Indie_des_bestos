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
#include "EventCore.hpp"
#include "IrrlichtLib.hpp"
#include "EventManager.hpp"

class Core
{
	public:
		Core();
		~Core();
		int	run();
	private:
		void	chooseCorePart(const CoreState const &);
		void	menu(const CoreState const &);
		void	game_local(const CoreState const &);
		void	game_solo(const CoreState const &);
		void	menu_setting(const CoreState const &);
		void	menu_local(const CoreState const &);
		int	exitCore();
		CoreState			_state;
		IndieEvents::EventManager	*_events;
		graphic::IrrlichtLib		*_lib;
		EventCore			_eventCore;
		graphic::Menu			_menu;
		const std::unordered_map<CoreState, std::function<void(const CoreState const &)>>	_fcnTab = {
			{CoreState::IN_MENU, menu},
			{CoreState::IN_SETTINGS, menu_setting},
			{CoreState::IN_LOCAL, menu_local},
			{CoreState:: IN_SOLO, game_solo},
			{CoreState::IN_LOCAL_GAME, game_local}
		};
};

#endif /* !CORE_HPP_ */

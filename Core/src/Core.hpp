/*
** EPITECH PROJECT, 2018
** indie
** File description:
** header
*/

#ifndef CORE_HPP_
	#define CORE_HPP_

#include "EventManager.hpp"

enum	CoreState {
	IN_MENU,
	IN_SOLO,
	IN_LOCAL,
	IN_LOCAL_GAME,
	IN_SETTINGS
};

class Core
{
	public:
		Core();
		~Core();
		int	run();
	private:
		CoreState			_state;
		IndieEvents::EventManager	*_events;
};

#endif /* !CORE_HPP_ */

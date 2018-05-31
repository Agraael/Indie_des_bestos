/*
** EPITECH PROJECT, 2018
** indie
** File description:
** event core
*/

#ifndef EVENTCORE_HPP_
	#define EVENTCORE_HPP_

#include "EventManager.hpp"
#include <unordered_map>

enum	CoreState {
	IN_MENU,
	IN_SOLO,
	IN_LOCAL,
	IN_LOCAL_GAME,
	IN_SETTINGS,
	EXIT,
	GAME_PAUSE
};

class EventCore
{
	public:
		EventCore(IndieEvents::EventManager *&events) : _events(events) {}
		~EventCore();
		CoreState	updateCore(CoreState) const noexcept;
	private:
		IndieEvents::EventManager	*_events;
		static const std::unordered_map<IndieEvents::IndieKeys, CoreState>	_statesTab;
};

#endif /* !EVENTCORE_HPP_ */
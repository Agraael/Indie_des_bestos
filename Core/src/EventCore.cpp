/*
** EPITECH PROJECT, 2018
** indie
** File description:
** Event core
*/

#include <algorithm>
#include "EventCore.hpp"

EventCore::~EventCore()
{
}

const std::unordered_map<IndieEvents::IndieKeys, CoreState>	EventCore::_statesTab = {
	{IndieEvents::IndieKeys::SETTINGS, CoreState::IN_SETTINGS},
	{IndieEvents::IndieKeys::EXIT_MAINMENU, CoreState::EXIT},
	{IndieEvents::IndieKeys::START_LOCAL, CoreState::IN_LOCAL},
	{IndieEvents::IndieKeys::START_SOLO, CoreState::IN_SOLO},
	{IndieEvents::IndieKeys::EXIT_LOCAL, CoreState::IN_MENU},
	{IndieEvents::IndieKeys::MENU, CoreState::IN_MENU},
	{IndieEvents::IndieKeys::START_LOCAL_GAME, CoreState::IN_LOCAL_GAME},
	{IndieEvents::IndieKeys::RESTART, CoreState::IN_LOCAL_GAME},
	{IndieEvents::IndieKeys::QUIT, CoreState::IN_MENU},
	{IndieEvents::IndieKeys::ECHAP, CoreState::GAME_PAUSE}
};

CoreState	EventCore::updateCore(CoreState currentState) const noexcept
{
	CoreState	state;
	std::list<IndieEvents::IndieKeys>	keys = _events->getKey();

	for (auto key = keys.begin(); key != keys.end(); key++) {
		if (_statesTab.find(*key) != _statesTab.end())
			return _statesTab.at(*key);
	}
	return currentState;
}
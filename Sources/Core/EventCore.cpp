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

const std::unordered_map<graphic::controllerUser, CoreState>	EventCore::_statesTab = {
	{graphic::controllerUser::SETTINGS, CoreState::IN_SETTINGS},
	{graphic::controllerUser::EXIT_MAINMENU, CoreState::EXIT},
	{graphic::controllerUser::START_LOCAL, CoreState::IN_LOCAL},
	{graphic::controllerUser::START_SOLO, CoreState::IN_SOLO},
	{graphic::controllerUser::EXIT_LOCAL, CoreState::IN_MENU},
	{graphic::controllerUser::MENU, CoreState::IN_MENU},
	{graphic::controllerUser::START_LOCAL_GAME, CoreState::IN_LOCAL_GAME},
	{graphic::controllerUser::RESTART, CoreState::IN_LOCAL_GAME},
	{graphic::controllerUser::QUIT, CoreState::IN_MENU},
	{graphic::controllerUser::ECHAP, CoreState::GAME_PAUSE}
};

CoreState	EventCore::updateCore(CoreState currentState) const noexcept
{
	for (auto button = _statesTab.begin(); button != _statesTab.end(); button++) {
		if (_lib->getEventManager()->IsButtonClicked(static_cast<graphic::controllerUser>(button->first)) == true)
			return button->second;
	}
	return currentState;
}

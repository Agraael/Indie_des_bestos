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
	{graphic::controllerUser::EXIT_SETTINGS, CoreState::IN_MENU},
	{graphic::controllerUser::START_LOCAL, CoreState::IN_LOCAL},
	{graphic::controllerUser::RESUME_GAME, CoreState::IN_GAME},
	{graphic::controllerUser::EXIT_LOCAL, CoreState::IN_MENU},
	{graphic::controllerUser::MENU, CoreState::IN_MENU},
	{graphic::controllerUser::CONTINUE, CoreState::IN_GAME},
	{graphic::controllerUser::START_LOCAL_GAME, CoreState::IN_GAME},
	{graphic::controllerUser::QUIT, CoreState::IN_MENU}
};

CoreState	EventCore::updateCore(CoreState currentState) const noexcept
{
	for (auto button = _statesTab.begin(); button != _statesTab.end(); button++) {
		if (_lib->getEventManager()->IsButtonClicked(button->first) == true)
			return button->second;
	}
	return currentState;
}

/*
** EPITECH PROJECT, 2018
** indie
** File description:
** Event core
*/

#include <algorithm>
#include "EventCore.hpp"
#include "SoundManager.hpp"

EventCore::~EventCore()
{
}

const std::unordered_map<graphic::controllerUser, CoreState>	EventCore::_statesTab = {
	{graphic::controllerUser::SETTINGS, CoreState::IN_SETTINGS},
	{graphic::controllerUser::EXIT_MAINMENU, CoreState::EXIT},
	{graphic::controllerUser::EXIT_SETTINGS, CoreState::IN_MENU},
	{graphic::controllerUser::START_LOCAL, CoreState::IN_LOCAL},
	{graphic::controllerUser::RESUME_GAME, CoreState::IN_RESUME},
	{graphic::controllerUser::EXIT_LOCAL, CoreState::IN_MENU},
	{graphic::controllerUser::MENU, CoreState::IN_MENU},
	{graphic::controllerUser::CONTINUE, CoreState::IN_GAME},
	{graphic::controllerUser::START_LOCAL_GAME, CoreState::IN_GAME},
	{graphic::controllerUser::QUIT, CoreState::IN_MENU}
};

const std::unordered_map<CoreState, std::string> soundButton = {
	{CoreState::IN_SETTINGS, "Audio/settings.wav"},
	{CoreState::IN_MENU, "Audio/return_to_menu.wav"},
};

CoreState	EventCore::updateCore(CoreState currentState) const noexcept
{
	Singleton::SoundManager& soundManager = Singleton::SoundManager::Instance();

	for (auto button = _statesTab.begin(); button != _statesTab.end(); button++) {
		if (_lib->getEventManager()->IsButtonClicked(button->first) == true) {
			if (soundButton.find(button->second) != soundButton.end())
				soundManager.playSound(soundButton.at(button->second));
			return button->second;
		}
	}
	return currentState;
}

/*
** EPITECH PROJECT, 2018
** indie
** File description:
** source
*/

#include <iostream>
#include <string>
#include "Gen.hpp"
#include "Core.hpp"

Core::Core()
	: _state(CoreState::IN_MENU), _events(new IndieEvents::EventManager()), _lib(new graphic::IrrlichtLib()), _eventCore(_events), _menu(new graphic::Menu(_lib)), hGame(_lib)
{
}

Core::~Core()
{
	delete _events;
	delete _lib;
}

int	Core::run()
{
	CoreState	newState;

	//_menu->display();
	hGame.InitGame(GenerationSize::Big, GenerationMod::FullDest);
	while (_lib->getDevice()->run()) {
		newState = _eventCore.updateCore(_state);
		if (newState == CoreState::EXIT)
			return exitCore();
		//chooseCorePart(newState);
		_lib->displayAll();
	}
	return 0;
}

void	Core::chooseCorePart(const CoreState &state)
{
	// if (_fcnTab.find(_state) != _fcnTab.end())
	// 	_fcnTab.at(_state)(state);
	if (_state == CoreState::IN_MENU)
		menu(state);
	_state = state;
}

void	Core::menu(const CoreState &state)
{
	(void)(state);
	_menu->updateDisplay();
	if (state == CoreState::IN_SOLO)
		hGame.InitGame(GenerationSize::Medium, GenerationMod::Standard);
}

void	Core::game_local(const CoreState &state)
{
	(void)(state);
}

void	Core::game_solo(const CoreState &state)
{
	hGame.updateMap();
	(void)(state);
}

void	Core::menu_setting(const CoreState &state)
{
	(void)(state);
}

void	Core::menu_local(const CoreState &state)
{
	(void)(state);
}

int	Core::exitCore()
{
	return 0;
}


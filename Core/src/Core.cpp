/*
** EPITECH PROJECT, 2018
** indie
** File description:
** source
*/

#include <iostream>
#include <string>
#include "Core.hpp"

Core::Core()
: _events(new IndieEvents::EventManager()), _state(CoreState::IN_MENU), _lib(new graphic::IrrlichtLib()), _eventCore(_events), _menu(new graphic::Menu(_lib))
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

	_menu->display();
	while (_lib->getDevice()->run()) {
		newState = _eventCore.updateCore(_state);
		if (newState == CoreState::EXIT)
			return exitCore();
		chooseCorePart(newState);
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
	_menu->updateDisplay();
}

void	Core::game_local(const CoreState &state)
{

}

void	Core::game_solo(const CoreState &state)
{

}

void	Core::menu_setting(const CoreState &state)
{

}

void	Core::menu_local(const CoreState &state)
{

}

int	Core::exitCore()
{
	return 0;
}


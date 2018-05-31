/*
** EPITECH PROJECT, 2018
** indie
** File description:
** source
*/

#include <iostream>
#include <string>
#include "Menu.hpp"
#include "Core.hpp"

Core::Core()
: _events(new IndieEvents::EventManager()), _state(CoreState::IN_MENU), _lib(new graphic::IrrlichtLib()), _eventCore(_events)
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

	while (_lib->getDevice()->run()) {
		newState = _eventCore.updateCore(_state);
		if (newState == CoreState::EXIT)
			return exitCore();
		chooseCorePart(newState);
		_lib->displayAll();
	}
	return 0;
}

void	Core::chooseCorePart(const CoreState const &state)
{
	if (_fcnTab.find(_state) != _fcnTab.end())
		_fcnTab.at(_state)(state);
	_state = state;
}

void	Core::menu(const CoreState const &state)
{

}

void	Core::game_local(const CoreState const &state)
{

}

void	Core::game_solo(const CoreState const &state)
{

}

void	Core::menu_setting(const CoreState const &state)
{

}

void	Core::menu_local(const CoreState const &state)
{

}

int	Core::exitCore()
{
	return 0;
}


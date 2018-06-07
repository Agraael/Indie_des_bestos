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
	: _state(CoreState::IN_MENU), _lib(new graphic::IrrlichtLib()), _eventCore(_lib), _menu(new graphic::Menu(_lib)), hGame(_lib)
{
}

Core::~Core()
{
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
		if (newState == CoreState::IN_SOLO || newState == CoreState::IN_LOCAL_GAME)
			_lib->displayAll(false);
		else
			_lib->displayAll(true);
	}
	return 0;
}

#include <time.h>
#include <unistd.h>
void	Core::chooseCorePart(const CoreState &state)
{
	// if (_fcnTab.find(_state) != _fcnTab.end())
	// 	_fcnTab.at(_state)(state);
	if (_state == CoreState::IN_MENU)
		menu(state);
	if (_state == CoreState::IN_SOLO) {
//		sleep(2);
		std::cout <<  "----------------------------------" << std::endl;
		game_solo(state);
	}
}

void	Core::menu(const CoreState &state)
{
	(void)(state);
	_menu->updateDisplay();
	if (state == CoreState::IN_SOLO) {
		hGame.InitGame({GenerationSize::Medium, GenerationMod::Standard, 1, 3});
		_state = state;
		return;
	}
}

void	Core::game_local(const CoreState &state)
{
	(void)(state);
}

void	Core::game_solo(const CoreState &state)
{
	if (_lib->getEventManager()->IsKeyDown(irr::EKEY_CODE::KEY_ESCAPE) == true) {
		hGame.quitGame();
		_menu->updateDisplay();
		_state = CoreState::IN_MENU;
		return;
	}
	hGame.updateMap();
	if (hGame.CheckEndGame() == true) {
		_state = CoreState::IN_MENU;
	}
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


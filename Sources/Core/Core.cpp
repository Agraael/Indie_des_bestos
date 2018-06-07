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
	: _state(CoreState::IN_MENU), _lib(new graphic::IrrlichtLib()), _eventCore(_lib), _menu(new graphic::Menu(_lib)), hGame(_lib), _playing(false)
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
	if (_state == CoreState::IN_SOLO)
		game_solo(state);
}

void	Core::menu(const CoreState &state)
{
	_menu->updateDisplay();
	if (state == _state)
		return;
	else if (state == CoreState::IN_SOLO) {
		_playing = true;
		hGame.InitGame({GenerationSize::Medium, GenerationMod::Standard, 1, 0});
	} else if (state == CoreState::IN_SETTINGS) {
		//init menu setting
	} else if (state == CoreState::IN_LOCAL) {
	}
	_state = state;
	_lib->clearGui();
}

void	Core::game_local(const CoreState &state)
{
	if (_lib->getEventManager()->IsKeyDown(irr::EKEY_CODE::KEY_ESCAPE) == true || !_playing) {
		hGame.quitGame();
		_lib->clearGui();
		_menu->display();
		_state = CoreState::IN_MENU;
		return;
	}
	hGame.updateMap(_playing);
	(void)(state);
}

void	Core::game_solo(const CoreState &state)
{
	if (_lib->getEventManager()->IsKeyDown(irr::EKEY_CODE::KEY_ESCAPE) == true) {
		hGame.quitGame();
		_lib->clearGui();
		_menu->display();
//		_menu->updateDisplay();
		_state = CoreState::IN_MENU;
		return;
	} else if (!_playing) {
		hGame.dumpPlayerName();
		return;
	}
	hGame.updateMap(_playing);	
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


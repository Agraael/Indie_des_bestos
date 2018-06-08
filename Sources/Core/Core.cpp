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
	: _state(CoreState::IN_MENU), _lib(new graphic::IrrlichtLib()), _eventCore(_lib), _menu(new graphic::Menu(_lib)), hGame(_lib), _menuSetting(new graphic::settingsMenu(_lib)), _playing(false)
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
	if (_state == CoreState::IN_SOLO) {
		//sleep(2);
		gameSolo(state);
	}
	if (_state == CoreState::IN_SETTINGS) {
		menuSetting(state);
	}
}

void	Core::menu(const CoreState &state)
{
	_menu->updateDisplay();
	if (state == _state)
		return;
	_lib->clearGui();
	if (state == CoreState::IN_SOLO) {
		_playing = true;
		hGame.InitGame({GenerationSize::Medium, GenerationMod::Standard, 1, 3});
	} else if (state == CoreState::IN_SETTINGS) {
		//init menu setting
		_menuSetting->display();
	} else if (state == CoreState::IN_LOCAL) {
	}
	_state = state;
}

void	Core::gameLocal(const CoreState &state)
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

void	Core::gameSolo(const CoreState &state)
{
	sleep (0.5);
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

void	Core::menuSetting(const CoreState &state)
{
	if (state == CoreState::IN_MENU) {
		_lib->clearGui();
		_menu->display();
		_state = CoreState::IN_MENU;
		return;
	}
	_menuSetting->updateDisplay();
	(void)(state);
}

void	Core::menuLocal(const CoreState &state)
{
	(void)(state);
}

int	Core::exitCore()
{
	return 0;
}

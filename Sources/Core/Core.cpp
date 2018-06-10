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
#include <unistd.h>

Core::Core()
	: _state(CoreState::IN_MENU), _lib(new graphic::IrrlichtLib()),
	_eventCore(_lib), _menu(new graphic::Menu(_lib)), hGame(nullptr),
	_menuSetting(new graphic::settingsMenu(_lib)), _menuCreateGame(new graphic::localMenu(_lib)),
	_menuPause(new graphic::MenuPause(_lib)), _menuResume(new graphic::ResumeGame(_lib)), _playing(false), _gamePaused(false)
{
}

Core::~Core()
{
	delete _lib;
	delete hGame;
}

int	Core::run()
{
	CoreState	newState;

	_menu->display();
	while (_lib->getDevice()->run()) {
		newState = _eventCore.updateCore(_state);
		if (newState == CoreState::EXIT)
			return 0;
		chooseCorePart(newState);
		_lib->displayAll();
	}
	return 0;
}
void	Core::chooseCorePart(const CoreState &state)
{
	if (_state == CoreState::IN_MENU)
		menu(state);
	else if (_state == CoreState::IN_GAME)
		game(state);
	else if (_state == CoreState::IN_SETTINGS)
		menuSetting(state);
	else if (_state == CoreState::GAME_PAUSE)
		menuGamePaused(state);
	else if (_state == CoreState::IN_RESUME)
		menuResume(state);
	else if (_state == CoreState::IN_LOCAL)
		menuCreateGame(state);
}

void	Core::menu(const CoreState &state)
{
	_menu->updateDisplay();
	if (state == _state)
		return;
	_lib->clearGui();
	if (state == CoreState::IN_LOCAL)
		_menuCreateGame->display();
	else if (state == CoreState::IN_SETTINGS)
		_menuSetting->display();
	else if (state == CoreState::IN_RESUME)
		_menuResume->display();
	_state = state;
}

void	Core::game(const CoreState &)
{
//	sleep (0.5);
	if (_lib->getEventManager()->IsKeyDown(irr::EKEY_CODE::KEY_ESCAPE) == true) {
		_menuPause->display();
		_state = CoreState::GAME_PAUSE;
		return;
	} else if (!_playing) {
		hGame->dumpPlayerName();
		return;
	}
	hGame->updateMap(_playing);
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
}


void Core::reset()
{
	if (hGame)
		delete hGame;
	hGame = new HandleGame(_lib);
}


void	Core::menuCreateGame(const CoreState &state)
{
	if (state == CoreState::IN_GAME) {
		_playing = true;
		reset();
		hGame->InitGame({_menuCreateGame->getMapName(), _menuCreateGame->getGenSize(),
			               _menuCreateGame->getGenMode(), _menuCreateGame->getPlayerNb(), _menuCreateGame->getIaNb()});
		_lib->clearGui();
		_state = state;
		return;
	} else if (state == CoreState::IN_MENU) {
		_lib->clearGui();
		_menu->display();
		_state = state;
		return;
	}
	_menuCreateGame->updateDisplay();
}

void	Core::menuGamePaused(const CoreState &state)
{
	if (state == CoreState::IN_MENU) {
		_lib->clearGui();
		_lib->clearScene();
		_menu->display();
		_state = state;
		return;
	} else if (state == CoreState::IN_GAME) {
		_lib->clearGui();
		_state = state;
		return;
	}
	_menuPause->updateDisplay(*hGame);
}

void	Core::menuResume(const CoreState &state)
{
	if (state == CoreState::IN_GAME) {
		_playing = true;
		reset();
		_lib->clearGui();
		_state = state;
		//
		return;
	} else if (state  == CoreState::IN_MENU) {
		_lib->clearGui();
		_state = state;
		return;
	}
	_menuResume->updateDisplay();
}

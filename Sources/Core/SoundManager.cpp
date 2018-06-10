/*
** EPITECH PROJECT, 2021
** IndieStudio
** File description:
** Created by kraken, 10/06/18
*/

#include <algorithm>
#include "SoundManager.hpp"

Singleton::SoundManager Singleton::SoundManager::_instance = Singleton::SoundManager();

Singleton::SoundManager::SoundManager()
	: _engine(irrklang::createIrrKlangDevice())
{}

Singleton::SoundManager::~SoundManager()
{
	_engine->drop();
}

Singleton::SoundManager& Singleton::SoundManager::Instance()
{
	return _instance;
}

void Singleton::SoundManager::playSound(std::string const& file)
{
	_engine->play2D(file.c_str(), false);
}

void Singleton::SoundManager::playLoop(std::string const& file)
{
	if (_loops.find(file) == _loops.end()) {
		_loops[file] = _engine->play2D(file.c_str(), true);;
	}
}

void Singleton::SoundManager::stopLoop(std::string const& file)
{
	if (_loops.find(file) != _loops.end()) {
		_loops[file]->stop();
		_loops.erase(file);
	}
}




/*
** EPITECH PROJECT, 2021
** IndieStudio
** File description:
** Created by kraken, 08/06/18
*/

#include <caca_conio.h>
#include "TimeManager.hpp"

Singleton::TimeManager Singleton::TimeManager::_instance = Singleton::TimeManager();
unsigned int Singleton::TimeManager::_chronoNb = 0;

Singleton::TimeManager& Singleton::TimeManager::Instance()
{
	return _instance;
}

void    Singleton::TimeManager::fpsDelay(unsigned int fps) const
{
	double calc{(1 / static_cast<double>(fps)) * 1000};

	this->delay(static_cast<unsigned int>(calc));
}

Singleton::ChronoId Singleton::TimeManager::createChrono()
{
	_chronoNb++;
	_chronoMap[_chronoNb] = std::chrono::steady_clock::now();
	return _chronoNb;
}

double Singleton::TimeManager::getChronoDuration(Singleton::ChronoId id)
{
	if (_chronoMap.find(id) == _chronoMap.end())
		return -1;
	auto t2 = std::chrono::steady_clock::now();
	std::chrono::duration<double> time_span =
		std::chrono::duration_cast<std::chrono::duration<double>>(t2 - _chronoMap[id]);
	return time_span.count();
}

bool Singleton::TimeManager::resetChrono(Singleton::ChronoId id)
{
	if (_chronoMap.find(id) == _chronoMap.end())
		return false;
	_chronoMap[_chronoNb] = std::chrono::steady_clock::now();
	return true;
}

void Singleton::TimeManager::delay(unsigned int value) const
{
	std::this_thread::sleep_for(std::chrono::milliseconds(value));
}

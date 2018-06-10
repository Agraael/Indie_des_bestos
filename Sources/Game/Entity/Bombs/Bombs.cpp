/*
** EPITECH PROJECT, 2018
** Bombs
** File description:
** source
*/

#include <SoundManager.hpp>
#include "Bombs.hpp"

void	Bombs::update()
{
	Singleton::TimeManager &timer = Singleton::TimeManager::Instance();
	Singleton::SoundManager& soundManager = Singleton::SoundManager::Instance();
	static bool trigger = false;

	if (timer.getChronoDuration(_chrono)  > 2) {
		if (!trigger)
			soundManager.playSound("Audio/Bomb1.wav");
		trigger = true;
		for (auto entity : _exploseTab) {
			if (timer.getChronoDuration(_chrono)  > 2.5f) {
				entity->die(true);
				_isDead = true;
				trigger = false;
			}
			else {
				entity->setLayout(0);
				reinterpret_cast<GonnaExplose &>(*entity).update();;
			}
		}
	}
}
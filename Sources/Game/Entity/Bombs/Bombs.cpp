/*
** EPITECH PROJECT, 2018
** Bombs
** File description:
** source
*/

#include "Bombs.hpp"

void	Bombs::update()
{
	Singleton::TimeManager &timer = Singleton::TimeManager::Instance();

	std::cout << "non" << std::endl;
	if (timer.getChronoDuration(_chrono)  > 2) {
		for (auto entity : _exploseTab) {
			if (timer.getChronoDuration(_chrono)  > 2.5f) {
				entity->die(true);
				_isDead = true;
			}
			else {
				entity->setLayout(0);
				reinterpret_cast<GonnaExplose &>(*entity).update();;
			}
		}
	}
}
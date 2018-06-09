/*
** EPITECH PROJECT, 2018
** Bombs
** File description:
** source
*/

#include "Bombs.hpp"

void	Bombs::update()
{
        if ((std::time(nullptr) - _saveTime) > 2) {
		for (auto entity : _exploseTab) {
			entity->setLayout(0);
			reinterpret_cast<GonnaExplose &>(*entity).update();;
		}
	}
}

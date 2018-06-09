/*
** EPITECH PROJECT, 2018
** indie
** File description:
** source
*/

#include "GonnaExplose.hpp"

void    GonnaExplose::update()
{
	std::cout << "non" << std::endl;
	if (_map == nullptr) {
		std::cout << "nullptr" << std::endl;
	}
	_map->checkExplosionCollision(_pos);
}
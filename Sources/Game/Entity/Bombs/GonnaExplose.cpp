/*
** EPITECH PROJECT, 2018
** indie
** File description:
** source
*/

#include "GonnaExplose.hpp"

void    GonnaExplose::update()
{
	_map.checkExplosionCollision(_pos);
}
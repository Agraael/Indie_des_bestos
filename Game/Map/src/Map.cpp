/*
** EPITECH PROJECT, 2018
** indie
** File description:
** source
*/

#include "Map.hpp"
#include "../../Entity/Bombs/src/Bombs.hpp"

void    Map::placeBomb(entities::entityPosition pos)
{
	_map[pos.first][pos.second].push_back(std::make_shared<entities::Entity>(Bombs(pos, false, 0)));
}
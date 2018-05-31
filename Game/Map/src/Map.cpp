/*
** EPITECH PROJECT, 2018
** indie
** File description:
** source
*/

#include "Map.hpp"
#include "../../Entity/Bombs/src/Bombs.hpp"
#include "../../Entity/Bombs/src/GonnaExplose.hpp"

void    Map::placeBomb(entities::entityPosition pos, std::size_t shining)
{
	_map[pos.first][pos.second].push_back(std::make_shared<entities::Entity>(Bombs(pos, false, 0)));
	for (int i = 1; i <= shining; ++i) {
		if ((pos.first - i) >= 0)
			_map[pos.first - i][pos.second].push_back(std::make_shared<entities::Entity>(GonnaExplose(pos, false, 0)));
		if ((pos.first + i) >= 0)
			_map[pos.first + i][pos.second].push_back(std::make_shared<entities::Entity>(GonnaExplose(pos, false, 0)));
		if ((pos.second - i) >= 0)
			_map[pos.first][pos.second - i].push_back(std::make_shared<entities::Entity>(GonnaExplose(pos, false, 0)));
		if ((pos.second + i) >= 0)
			_map[pos.first][pos.second + i].push_back(std::make_shared<entities::Entity>(GonnaExplose(pos, false, 0)));
	}
}

void	Map::updatePos()
{

}
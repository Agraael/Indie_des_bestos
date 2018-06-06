/*
** EPITECH PROJECT, 2018
** indie
** File description:
** source
*/

#include "Map.hpp"
#include "Bombs.hpp"
#include "GonnaExplose.hpp"

void    Map::placeBomb(entities::entityPosition pos, std::size_t shining)
{
	_map[pos.first][pos.second].push_back(std::make_shared<entities::Entity>(Bombs(pos, false, 0)));
	for (int i = 1; i <= static_cast<int>(shining); ++i) {
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

void	Map::deleteElem(std::shared_ptr<entities::Entity> entity)
{
	std::size_t	index = 0;

	for (auto elem : _map[entity.get()->getPos().first][entity.get()->getPos().second]) {
		++index;
		if (elem == entity)
			_map[entity.get()->getPos().first][entity.get()->getPos().second].erase(_map[entity.get()->getPos().first][entity.get()->getPos().second].begin()+index);
	}
}

void	Map::updatePos(std::shared_ptr<entities::Entity> entity, entities::entityPosition pos)
{
	for (auto line : _map) {
		for (auto tab : line) {
			for (auto shared : tab) {
				if (shared == entity) {
					_map[pos.first][pos.second].push_back(entity);
					deleteElem(entity);
				}
			}
		}
	}
}
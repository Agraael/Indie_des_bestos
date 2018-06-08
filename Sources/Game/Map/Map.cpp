/*
** EPITECH PROJECT, 2018
** indie
** File description:
** source
*/

#include "Map.hpp"
#include "Bombs.hpp"
#include "GonnaExplose.hpp"

void	Map::placeExplosion(std::shared_ptr<entities::Entity> &newEntity, entities::entityPosition pos)
{
	newEntity = std::make_shared<GonnaExplose>(pos, false, 1);
	_map[pos.first][pos.second].push_back(newEntity);
}

void    Map::placeBomb(entities::entityPosition pos, std::size_t power)
{
	std::vector<std::shared_ptr<entities::Entity>>	exploseTab;
	std::shared_ptr<entities::Entity>		newEntity;

	for (int i = 1; i <= static_cast<int>(power); ++i) {
		if ((pos.first - i) >= 0)
			placeExplosion(newEntity, std::make_pair(pos.first - i, pos.second));
		else if ((pos.first + i) >= 0)
			placeExplosion(newEntity, std::make_pair(pos.first + i, pos.second));
		else if ((pos.second - i) >= 0)
			placeExplosion(newEntity, std::make_pair(pos.first, pos.second - i));
		else if ((pos.second + i) >= 0)
			placeExplosion(newEntity, std::make_pair(pos.first, pos.second + i));
		exploseTab.push_back(newEntity);
	}
 	_map[pos.first][pos.second].push_back(std::make_shared<Bombs>(pos, false, 0, exploseTab));
}

#include <algorithm>

void	Map::deleteElem(std::shared_ptr<entities::Entity> entity)
{

	auto x = entity->getPos().first;
	auto y = entity->getPos().second;
	
	auto find = std::find(std::begin(_map[x][y]), std::end(_map[x][y]), entity);
	if (find == std::end(_map[x][y]))
		std::cout << "no found" << std::endl;
	else
		_map[x][y].erase(find);
}

void Map::addBombs(std::shared_ptr<entities::Entity> &character, const entities::entityPosition &pos)
{
        for (auto entity : _map[pos.first][pos.second]) {
                if (entity == character) {
                        std::static_pointer_cast<Character>(entity).get()->upgradeBombs();
                }
        }
}

void Map::addSpeed(std::shared_ptr<entities::Entity> &character, const entities::entityPosition &pos)
{
        for (auto entity : _map[pos.first][pos.second]) {
                if (entity == character) {
                        std::static_pointer_cast<Character>(entity).get()->upgradeSpeed();
                }
        }
}

void Map::addFire(std::shared_ptr<entities::Entity> &character, const entities::entityPosition &pos)
{
        for (auto entity : _map[pos.first][pos.second]) {
                if (entity == character) {
                        std::static_pointer_cast<Character>(entity).get()->upgradePower();
                }
        }
}

void Map::allowWallpass(std::shared_ptr<entities::Entity> &character, const entities::entityPosition &pos)
{
        for (auto entity : _map[pos.first][pos.second]) {
                if (entity == character) {
                        std::static_pointer_cast<Character>(entity).get()->upgradeWallpass();
                }
        }
}

void Map::checkCollision(std::shared_ptr<entities::Entity> character, const entities::entityPosition &pos)
{
        for (auto entity : _map[pos.first][pos.second]) {
                if (entity.get()->getType() == entities::entityType::BOMB_UP_TYPE) {
                        addBombs(character, pos);
                } else if (entity.get()->getType() == entities::entityType::SPEED_UP_TYPE) {
                        addSpeed(character, pos);
                } else if (entity.get()->getType() == entities::entityType::FIRE_UP_TYPE) {
                        addFire(character, pos);
                } else if (entity.get()->getType() == entities::entityType::WALL_PASS_TYPE) {
                        allowWallpass(character, pos);
                }
        }
}

void	Map::displayMap()
{
/*	for (auto line : _map) {
		for (auto tab : line) {
			for (std::size_t i = 0; i < tab.size(); ++i) {
				if (tab[i].get()->getType() == entities::entityType::IA_TYPE)
					std::cout << "a";
				else
					std::cout << "l";
			}
			if (tab.empty())
				std::cout << " ";
		}
		std::cout << std::endl;
	}*/
}

void	Map::updatePos(entities::Entity* entity, entities::entityPosition newPos)
{
	std::cout << entity << std::endl;
	auto x = entity->getPos().first;
	auto y = entity->getPos().second;
	auto find = std::find_if(std::begin(_map[x][y]), std::end(_map[x][y]), 
				[entity](const std::shared_ptr<entities::Entity>& elem){return elem.get() == entity;});

	std::cout << "entity nb : " << entity->getId() << std::endl;
	std::cout << x << ":" << y << " -> " << newPos.first << ":" << newPos.second << std::endl;
	if (find == std::end(_map[x][y]))
		std::cout << "no found" << std::endl;
	else {
		//_map[newPos.first][newPos.second].push_back(*find);
		//_map[x][y].erase(find);
	}
}

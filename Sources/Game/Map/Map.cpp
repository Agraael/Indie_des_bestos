/*
** EPITECH PROJECT, 2018
** indie
** File description:
** source
*/

#include "Map.hpp"
#include <algorithm>
#include "Bombs.hpp"
#include "Walls.hpp"
#include "Entity.hpp"
#include "Algorithm.hpp"
#include "GonnaExplose.hpp"

void	Map::placeExplosion(std::vector<std::shared_ptr<entities::Entity>> &exploseTab, std::shared_ptr<entities::Entity> &newEntity, entities::entityPosition pos)
{
	for (auto oldEntity :_map[pos.first][pos.second]) {
		if (oldEntity.get()->getType() == entities::entityType::INDESTRUCTIBLE_TYPE)
			return;
	}
	newEntity = std::make_shared<GonnaExplose>(pos, false, 1, *this);
	_map[pos.first][pos.second].push_back(newEntity);
	exploseTab.push_back(newEntity);
	addAddedEntity(newEntity);
}

bool Map::isWallHere(int first, int second)
{
	if (first <= 0 || second <= 0 || static_cast<unsigned int>(first) >= _map.size() || static_cast<unsigned int>(second) >= _map[first].size())
                return true;
        for (auto &entity : _map[first][second]) {
                if (entity.get()->getType() ==
                    entities::entityType::DESTRUCTIBLE_TYPE ||
                    entity.get()->getType() ==
                    entities::entityType::INDESTRUCTIBLE_TYPE)
                        return true;
        }
        return false;
}

void    Map::placeBomb(entities::entityPosition pos, std::size_t power)
{
	std::vector<std::shared_ptr<entities::Entity>>	exploseTab;
	std::shared_ptr<entities::Entity>		newEntity;

	for (auto oldEntity :_map[pos.first][pos.second])
		if (oldEntity.get()->getType() == entities::entityType::BOMBS_TYPE)
			return;
	for (int i = 1; i <= static_cast<int>(power) && isWallHere(pos.first - i, pos.second) == false; i++)
		if ((pos.first - i) > 0)
			placeExplosion(exploseTab, newEntity, std::make_pair(pos.first - i, pos.second));
	for (int i = 1; i <= static_cast<int>(power) && isWallHere(pos.first + i, pos.second) == false; i++)
		if ((pos.first + i) < 25)
			placeExplosion(exploseTab, newEntity, std::make_pair(pos.first + i, pos.second));
	for (int i = 1; i <= static_cast<int>(power) && isWallHere(pos.first, pos.second + i) == false; i++)
		if ((pos.second - i) > 0)
			placeExplosion(exploseTab, newEntity, std::make_pair(pos.first, pos.second - i));
	for (int i = 1; i <= static_cast<int>(power) && isWallHere(pos.first, pos.second + i) == false; i++)
		if ((pos.second + i) < 25)
			placeExplosion(exploseTab, newEntity, std::make_pair(pos.first, pos.second + i));
	newEntity = std::make_shared<GonnaExplose>(pos, false, 1, *this);
	exploseTab.push_back(newEntity);
	_map[pos.first][pos.second].push_back(newEntity);
	addAddedEntity(newEntity);
	newEntity = std::make_shared<Bombs>(pos, false, 0, exploseTab, *this);
	addAddedEntity(newEntity);
 	_map[pos.first][pos.second].push_back(newEntity);
}

void Map::addModifiedEntity(const std::shared_ptr<entities::Entity> &entity)
{
	std::shared_ptr<entities::Entity> new_entity(entity);

	_modifiedEntities.push_back(new_entity);
}

void Map::addDeletedEntity(const std::shared_ptr<entities::Entity> &entity)
{
	std::cout << "deleted entity : " << entity->getId() << std::endl;
	_deletedEntities.push_back(entity->getId());
}

void Map::addAddedEntity(const std::shared_ptr<entities::Entity> &entity)
{
	_addedEntities.push_back(entity);
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

void	Map::checkExplosionCollision(const entities::entityPosition &pos)
{
	std::size_t x = 0;

	//std::cout << "collision" << pos.first << " " << pos.second << std::endl;
	for (unsigned int i = 0; i < _map[pos.first][pos.second].size(); i++) {
		x = 0;
		for (auto entity :_map[pos.first][pos.second]) {
			x++;
			if ( entity.get()->getType() == entities::entityType::PLAYER_TYPE ||
				entity.get()->getType() == entities::entityType::IA_TYPE ||
				entity.get()->getType() == entities::entityType::DESTRUCTIBLE_TYPE) {
					addDeletedEntity(entity);
					_map[pos.first][pos.second].erase(_map[pos.first][pos.second].begin() + x);
					break;
			}
			if (entity.get()->getType() == entities::entityType::GONNAEXPLOSE_TYPE) {
				entity->setLayout(0);
				addModifiedEntity(entity);
			}
		}
	}
}

void Map::checkBonusCollision(std::shared_ptr<entities::Entity> character, const entities::entityPosition &pos)
{
	std::size_t x = 0;
	for (unsigned int i = 0; i < _map[pos.first][pos.second].size(); i++) {
		x = 0;
		for (auto entity : _map[pos.first][pos.second]) {
			x++;
			if (entity.get()->getType() == entities::entityType::BOMB_UP_TYPE) {
				addBombs(character, pos);
				addDeletedEntity(entity);
				_map[pos.first][pos.second].erase(_map[pos.first][pos.second].begin() + x);
				break;
			} else if (entity.get()->getType() == entities::entityType::SPEED_UP_TYPE) {
				addSpeed(character, pos);
				addDeletedEntity(entity);
				_map[pos.first][pos.second].erase(_map[pos.first][pos.second].begin() + x);
				break;
			} else if (entity.get()->getType() == entities::entityType::FIRE_UP_TYPE) {
				addFire(character, pos);
				addDeletedEntity(entity);
				_map[pos.first][pos.second].erase(_map[pos.first][pos.second].begin() + x);
				break;
			} else if (entity.get()->getType() == entities::entityType::WALL_PASS_TYPE) {
				allowWallpass(character, pos);
				addDeletedEntity(entity);
				_map[pos.first][pos.second].erase(_map[pos.first][pos.second].begin() + x);
				break;
			}
		}
	}
}

void    Map::updatePos(entities::Entity *entity, entities::entityPosition pos)
{
        entities::entityPosition        newPos = entity->getPos();
	std::size_t x = 0;	

        for (unsigned int i = 0; i < _map[newPos.first][newPos.second].size(); i++) {
		x = 0;
                for (auto oldEntity :_map[newPos.first][newPos.second]) {
			++x;
                        if (oldEntity->getId() == entity->getId()) {
                                _map[pos.first][pos.second].push_back(oldEntity);
                                _map[newPos.first][newPos.second].erase(_map[newPos.first][newPos.second].begin() + x);
                                return ;
                        }
                }
        }
}

bool	Map::verifPosition(entities::entityPosition &pos)
{
	if (pos.first < 0)
		return (false);
	if (pos.second < 0)
		return (false);
	if (pos.first > _mapPos.first)
		return (false);
	if (pos.second > _mapPos.second)
		return (false);
	return (true);
}

/*
** EPITECH PROJECT, 2018
** indie
** File description:
** source
*/

#include <algorithm>
#include "Map.hpp"
#include <algorithm>
#include "Bombs.hpp"
#include "DestructibleWalls.hpp"
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

std::shared_ptr<entities::Entity>	Map::placeBomb(entities::entityPosition pos, std::size_t power)
{
	std::vector<std::shared_ptr<entities::Entity>>	exploseTab;
	std::shared_ptr<entities::Entity>		newEntity;

	for (auto oldEntity :_map[pos.first][pos.second])
		if (oldEntity.get()->getType() == entities::entityType::BOMBS_TYPE)
			return nullptr;
	for (int i = 1; i <= static_cast<int>(power); i++)
		if ((pos.first - i) > 0) {
			placeExplosion(exploseTab, newEntity, std::make_pair(pos.first - i, pos.second));
			if (isWallHere(pos.first - i, pos.second) == true)
				break;
		}
	for (int i = 1; i <= static_cast<int>(power); i++)
		if ((pos.first + i) < _mapPos.first) {
			placeExplosion(exploseTab, newEntity, std::make_pair(pos.first + i, pos.second));
			if (isWallHere(pos.first + i, pos.second) == true)
				break;
		}
	for (int i = 1; i <= static_cast<int>(power); i++)
		if ((pos.second - i) > 0) {
			placeExplosion(exploseTab, newEntity, std::make_pair(pos.first, pos.second - i));
			if (isWallHere(pos.first, pos.second - i) == true)
				break;
		}
	for (int i = 1; i <= static_cast<int>(power); i++)
		if ((pos.second + i) < _mapPos.second) {
			placeExplosion(exploseTab, newEntity, std::make_pair(pos.first, pos.second + i));
			if (isWallHere(pos.first, pos.second + i) == true)
				break;
		}
	newEntity = std::make_shared<GonnaExplose>(pos, false, 1, *this);
	exploseTab.push_back(newEntity);
	_map[pos.first][pos.second].push_back(newEntity);
	addAddedEntity(newEntity);
	newEntity = std::make_shared<Bombs>(pos, true, 0, exploseTab, *this);
	addAddedEntity(newEntity);
	addModifiedEntity(newEntity);
 	_map[pos.first][pos.second].push_back(newEntity);
	return (newEntity);
}

void Map::addModifiedEntity(const std::shared_ptr<entities::Entity> &entity)
{
	std::shared_ptr<entities::Entity> new_entity(entity);

	if (entity == nullptr)
		return;
	_modifiedEntities.push_back(new_entity);
}

void Map::addDeletedEntity(const std::shared_ptr<entities::Entity> &entity)
{
	_deletedEntities.push_back(entity->getId());
}

void Map::addAddedEntity(const std::shared_ptr<entities::Entity> &entity)
{
	_addedEntities.push_back(entity);
}

void Map::addBombs(entities::Entity *character, const entities::entityPosition &pos)
{
        for (auto entity : _map[pos.first][pos.second]) {
                if (entity->getId() == character->getId()) {
                        std::static_pointer_cast<Character>(entity).get()->upgradeBombs();
                }
        }
}

void Map::addSpeed(entities::Entity *character, const entities::entityPosition &pos)
{
        for (auto entity : _map[pos.first][pos.second]) {
                if (entity->getId() == character->getId()) {
                        std::static_pointer_cast<Character>(entity).get()->upgradeSpeed();
                }
        }
}

void Map::addFire(entities::Entity *character, const entities::entityPosition &pos)
{
        for (auto entity : _map[pos.first][pos.second]) {
                if (entity->getId() == character->getId()) {
			std::static_pointer_cast<Character>(entity).get()->upgradePower();
                }
        }
}

void Map::allowWallpass(entities::Entity *character, const entities::entityPosition &pos)
{
        for (auto entity : _map[pos.first][pos.second]) {
                if (entity->getId() == character->getId()) {
                        std::static_pointer_cast<Character>(entity).get()->upgradeWallpass();
                }
        }
}

void	Map::checkExplosionCollision(const entities::entityPosition &pos)
{
	std::size_t x = 0;

	for (unsigned int i = 0; i < _map[pos.first][pos.second].size(); i++) {
		x = 0;
		for (auto entity :_map[pos.first][pos.second]) {
			x++;
			if (entity.get()->getType() == entities::entityType::DESTRUCTIBLE_TYPE) {
				addModifiedEntity(reinterpret_cast<DestructibleWalls &>(*entity).getBonus());
				addModifiedEntity(entity);
				reinterpret_cast<DestructibleWalls &>(*entity).setLayout(0);				
			}
			if ( entity.get()->getType() == entities::entityType::PLAYER_TYPE ||
			entity.get()->getType() == entities::entityType::IA_TYPE ||
			entity.get()->getType() == entities::entityType::DESTRUCTIBLE_TYPE) {
				entity->die(true);
				break;
			}
			if (entity.get()->getType() == entities::entityType::GONNAEXPLOSE_TYPE) {
				entity->setLayout(0);
				addModifiedEntity(entity);
			}

		}
	}
}

void Map::checkBonusCollision(entities::Entity *character, const entities::entityPosition &pos)
{
	for (auto entity : _map[pos.first][pos.second]) {
		if (entity.get()->getType() == entities::entityType::BOMB_UP_TYPE) {
			std::cout << "bomb" << std::endl;
			addBombs(character, pos);
			entity.get()->die(true);
			break;
		} else if (entity.get()->getType() == entities::entityType::SPEED_UP_TYPE) {
			addSpeed(character, pos);
			entity.get()->die(true);
			break;
		} else if (entity.get()->getType() == entities::entityType::FIRE_UP_TYPE) {
			addFire(character, pos);
			entity.get()->die(true);
			break;
		} else if (entity.get()->getType() == entities::entityType::WALL_PASS_TYPE) {
			allowWallpass(character, pos);
			entity.get()->die(true);
			break;
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
			if (oldEntity->getId() == entity->getId()) {
				_map[pos.first][pos.second].push_back(oldEntity);
				_map[newPos.first][newPos.second].erase(_map[newPos.first][newPos.second].begin() + x);
				checkBonusCollision(entity, pos);
				break;
			}
			++x;
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

void Map::clean()
{
	std::for_each(_map.begin(), _map.end(), [this](EntitiesVec& elem1){
		std::for_each(elem1.begin(), elem1.end(), [this](SharedEntity& elem2){
			elem2.erase(std::remove_if(elem2.begin(), elem2.end(), [this](std::shared_ptr<entities::Entity>& ptr){
				if (ptr->isDead())
					this->addDeletedEntity(ptr);
				return ptr->isDead();
			}), elem2.end());
		});
	});
}
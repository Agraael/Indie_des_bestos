/*
** EPITECH PROJECT, 2018
** indie
** File description:
** source
*/

#include "Map.hpp"
#include <algorithm>
#include "Bombs.hpp"
#include "GonnaExplose.hpp"

void	Map::placeExplosion(std::vector<std::shared_ptr<entities::Entity>> &exploseTab, std::shared_ptr<entities::Entity> &newEntity, entities::entityPosition pos)
{
	newEntity = std::make_shared<GonnaExplose>(pos, false, 1, *this);
	_map[pos.first][pos.second].push_back(newEntity);
	exploseTab.push_back(newEntity);
}

void    Map::placeBomb(entities::entityPosition pos, std::size_t power)
{
	std::vector<std::shared_ptr<entities::Entity>>	exploseTab;
	std::shared_ptr<entities::Entity>		newEntity;

	for (auto oldEntity :_map[pos.first][pos.second]) {
		if (oldEntity.get()->getType() == entities::entityType::BOMBS_TYPE)
			return;
	}
	for (int i = 1; i <= static_cast<int>(power); ++i) {
		if ((pos.first - i) > 0)
			placeExplosion(exploseTab, newEntity, std::make_pair(pos.first - i, pos.second));
		if ((pos.first + i) < 25)
			placeExplosion(exploseTab, newEntity, std::make_pair(pos.first + i, pos.second));
		if ((pos.second - i) > 0)
			placeExplosion(exploseTab, newEntity, std::make_pair(pos.first, pos.second - i));
		if ((pos.second + i) < 25)
			placeExplosion(exploseTab, newEntity, std::make_pair(pos.first, pos.second + i));
	}
	newEntity = std::make_shared<GonnaExplose>(pos, false, 1, *this);
	exploseTab.push_back(newEntity);
	_map[pos.first][pos.second].push_back(newEntity);
	newEntity = std::make_shared<Bombs>(pos, false, 0, exploseTab, *this);
 	_map[pos.first][pos.second].push_back(newEntity);
}

void Map::addModifiedEntity(const std::shared_ptr<entities::Entity> &entity)
{
	std::shared_ptr<entities::Entity> new_entity(entity);

	_modifiedEntities.push_back(new_entity);
}

void Map::addDeletedEntity(const std::shared_ptr<entities::Entity> &entity)
{
	_deletedEntities.push_back(entity->getId());
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
	for (auto entity :_map[pos.first][pos.second]) {
		if (!(entity.get()->getType() == entities::entityType::BOMB_UP_TYPE ||
		     	entity.get()->getType() == entities::entityType::SPEED_UP_TYPE ||
		     	entity.get()->getType() == entities::entityType::FIRE_UP_TYPE ||
		     	entity.get()->getType() == entities::entityType::WALL_PASS_TYPE ||
			entity.get()->getType() == entities::entityType::INDESTRUCTIBLE_TYPE)) {
				addDeletedEntity(entity);
				_map[pos.first][pos.second].erase(_map[pos.first][pos.second].begin());
				break;
		}
	}
}

void Map::checkBonusCollision(std::shared_ptr<entities::Entity> character, const entities::entityPosition &pos)
{
	for (unsigned int i = 0; i < _map[pos.first][pos.second].size(); i++) {
		for (auto entity : _map[pos.first][pos.second]) {
			if (entity.get()->getType() == entities::entityType::BOMB_UP_TYPE) {
				addBombs(character, pos);
				addDeletedEntity(entity);
				_map[pos.first][pos.second].erase(_map[pos.first][pos.second].begin());
				break;
			} else if (entity.get()->getType() == entities::entityType::SPEED_UP_TYPE) {
				addSpeed(character, pos);
				addDeletedEntity(entity);
				_map[pos.first][pos.second].erase(_map[pos.first][pos.second].begin());
				break;
			} else if (entity.get()->getType() == entities::entityType::FIRE_UP_TYPE) {
				addFire(character, pos);
				addDeletedEntity(entity);
				_map[pos.first][pos.second].erase(_map[pos.first][pos.second].begin());
				break;
			} else if (entity.get()->getType() == entities::entityType::WALL_PASS_TYPE) {
				allowWallpass(character, pos);
				addDeletedEntity(entity);
				_map[pos.first][pos.second].erase(_map[pos.first][pos.second].begin());
				break;
			}
		}
	}
}

void	Map::updatePos(entities::Entity *entity, entities::entityPosition pos)
{
	entities::entityPosition	newPos = entity->getPos();
	std::size_t	i = 0;

	for (auto entity :_map[newPos.first][newPos.second]) {
		entity->getId();
	}
	for (auto oldEntity :_map[newPos.first][newPos.second]) {
		if (oldEntity->getId() == entity->getId()) {
			_map[pos.first][pos.second].push_back(oldEntity);
		     	_map[newPos.first][newPos.second].erase(_map[newPos.first][newPos.second].begin() + i);
			return ;
		}
		i++;
	}
}

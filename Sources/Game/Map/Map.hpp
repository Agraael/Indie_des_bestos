/*
** EPITECH PROJECT, 2018
** indie
** File description:
** header
*/

#ifndef MAP_HPP_
	#define MAP_HPP_

#include "InterpreteGeneration.hpp"
#include "Entity.hpp"

//namespace entities;

class Map {
public:
	Map(GameMap map) :_map(map) { _mapPos = std::make_pair(map.size(), map[0].size()); }
	GameMap &get3dMap() { return _map; }
	void	updatePos(entities::Entity *, entities::entityPosition);
	void	displayMap();
	void	checkAfterExplosion() {};
	void	playerDeath() {};
	void	placeBomb(entities::entityPosition, std::size_t);
	void    checkBonusCollision(std::shared_ptr<entities::Entity>, const entities::entityPosition &);
	void	checkExplosionCollision(const entities::entityPosition &_pos);
	std::vector<std::shared_ptr<entities::Entity>>	getModifiedEntities(void) const noexcept { return _modifiedEntities; }
	std::vector<std::size_t>			getDeleteEntities() const noexcept { return _deletedEntities; }
	std::vector<std::shared_ptr<entities::Entity>>	getAddedEntity() const noexcept { return _addedEntities; }
	void	clearDeletedEntities() { _deletedEntities.clear(); }
	void	clearAddedEntities() { _addeddEntities.clear(); }
	void	clearModifiedEntities() { _modifiedEntities.clear(); }
	bool	verifPosition(entities::entityPosition &);
	void    clean();
private:
	void	placeExplosion(std::vector<std::shared_ptr<entities::Entity>> &, std::shared_ptr<entities::Entity> &, entities::entityPosition pos);	
	void	addModifiedEntity(const std::shared_ptr<entities::Entity> &entity);
	void	addDeletedEntity(const std::shared_ptr<entities::Entity> &entity);
	void	addAddedEntity(const std::shared_ptr<entities::Entity> &entity);
	void    addBombs(std::shared_ptr<entities::Entity> &character, const entities::entityPosition &pos);
        void    addSpeed(std::shared_ptr<entities::Entity> &character, const entities::entityPosition &pos);
        void    addFire(std::shared_ptr<entities::Entity> &character, const entities::entityPosition &pos);
        void    allowWallpass(std::shared_ptr<entities::Entity> &character, const entities::entityPosition &pos);
	bool isWallHere(int first, int second);
	std::vector<std::shared_ptr<entities::Entity>> _modifiedEntities;
	std::vector<std::shared_ptr<entities::Entity>> _addedEntities;
	std::vector<std::size_t> _deletedEntities;
	GameMap _map;
	std::pair<int, int>	_mapPos;
};

#endif /* !MAP_HPP_ */

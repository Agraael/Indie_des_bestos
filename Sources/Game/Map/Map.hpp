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
	Map(GameMap map) : _map(map) {};
	GameMap &get3dMap() { return _map; }
	void	placeBomb(entities::entityPosition, std::size_t);
	void	updatePos(entities::Entity *, entities::entityPosition);
	void	displayMap();
	void	checkAfterExplosion() {};
	void	playerDeath() {};
	std::vector<std::shared_ptr<entities::Entity>> getModifiedEntities(void) const noexcept { return _modifiedEntities; }
	std::vector<int> getDeletedEntities(void) const noexcept { return _deletedEntities; }
	void    checkBonusCollision(std::shared_ptr<entities::Entity>, const entities::entityPosition &);
	void	checkExplosionCollision(const entities::entityPosition &_pos);
	void	test() { std::cout << "oui" << std::endl;}
private:
	void	placeExplosion(std::vector<std::shared_ptr<entities::Entity>> &, std::shared_ptr<entities::Entity> &, entities::entityPosition pos);	
	void	addModifiedEntity(const std::shared_ptr<entities::Entity> &entity);
	void	addDeletedEntity(const std::shared_ptr<entities::Entity> &entity);
	void    addBombs(std::shared_ptr<entities::Entity> &character, const entities::entityPosition &pos);
        void    addSpeed(std::shared_ptr<entities::Entity> &character, const entities::entityPosition &pos);
        void    addFire(std::shared_ptr<entities::Entity> &character, const entities::entityPosition &pos);
        void    allowWallpass(std::shared_ptr<entities::Entity> &character, const entities::entityPosition &pos);
	std::vector<std::shared_ptr<entities::Entity>> _modifiedEntities;
	std::vector<int> _deletedEntities;
	GameMap _map;
};

#endif /* !MAP_HPP_ */

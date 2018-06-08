
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
	GameMap	get3dMap() const noexcept { return _map; }
	void	placeBomb(entities::entityPosition, std::size_t);
	void	updatePos(entities::Entity*, entities::entityPosition);
	void	deleteElem(std::shared_ptr<entities::Entity>);
	void	displayMap();
	void	checkAfterExplosion() {};
	void	playerDeath() {};
	void	placeExplosion(std::shared_ptr<entities::Entity> &, entities::entityPosition pos);	
	void    checkBonusCollision(std::shared_ptr<entities::Entity>, const entities::entityPosition &);
	void	checkExplosionCollision(const entities::entityPosition &_pos);
private:
	void    addBombs(std::shared_ptr<entities::Entity> &character, const entities::entityPosition &pos);
        void    addSpeed(std::shared_ptr<entities::Entity> &character, const entities::entityPosition &pos);
        void    addFire(std::shared_ptr<entities::Entity> &character, const entities::entityPosition &pos);
        void    allowWallpass(std::shared_ptr<entities::Entity> &character, const entities::entityPosition &pos);
	GameMap _map;
};

#endif /* !MAP_HPP_ */

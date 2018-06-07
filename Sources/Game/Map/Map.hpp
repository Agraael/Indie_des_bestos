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
	void	updatePos(std::shared_ptr<entities::Entity>, entities::entityPosition);
	void	deleteElem(std::shared_ptr<entities::Entity>);
	void	displayMap();
	std::shared_ptr<entities::Entity>	placeExplosion(entities::entityPosition pos);	
private:
	GameMap _map;
};

#endif /* !MAP_HPP_ */

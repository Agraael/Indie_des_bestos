/*
** EPITECH PROJECT, 2018
** indie
** File description:
** header
*/

#ifndef MAP_HPP_
	#define MAP_HPP_

#include "InterpreteGeneration.hpp"
#include "../../Entity/Entity.hpp"

class Map {
public:
	Map(GameMap map) : _map(map) {};
	std::vector<std::vector<std::vector<std::shared_ptr<entities::Entity>>>>	get3dMap() { return _map; }
	void										placeBomb(entities::entityPosition);
private:
	std::vector<std::vector<std::vector<std::shared_ptr<entities::Entity>>>> _map;
};

#endif /* !MAP_HPP_ */
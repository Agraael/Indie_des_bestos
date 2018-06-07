//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include <iostream>
#include <utility>
#include <functional>
#include <vector>
#include "../Entity.hpp"

#ifndef CHARACTER_HPP_
	#define CHARACTER_HPP_

/* class Character {
public:
	Character(std::vector<std::string> &positionMap, std::vector<std::string>
	&dynamicMap) : _positionMap(positionMap), _dynamicMap(dynamicMap) {};
protected:
	std::vector<std::string> &_positionMap;
	std::vector<std::string> &_dynamicMap;
	std::pair<int, int> _pos;
}; */

class Character : public entities::Entity {
public:
	Character(entities::entityPosition pos, bool iskinematic, std::size_t layout, entities::entityType type, std::string name) :
	Entity(pos, iskinematic, layout, type, name) {}
	~Character() override = default;
	virtual void	update() {};
protected:
};

#endif /* !CHARACTER_HPP */
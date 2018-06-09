/*
** EPITECH PROJECT, 2018
** indie
** File description:
** source
*/

#include "Entity.hpp"

entities::Entity::Entity(entityPosition pos, bool iskinematic, std::size_t layout, entities::entityType type, std::string name) :
_pos(pos), _iskinematic(iskinematic), _layout(layout), _typeEnum(type), _name(name), _mooved(false), _isDead(false)
{
	static std::size_t	id = 2000;
	
	_id = id;
//	std::cout << id << std::endl;
	_graphicPos = std::make_pair(static_cast<float>(_pos.first), static_cast<float>(_pos.second));
	++id;
}
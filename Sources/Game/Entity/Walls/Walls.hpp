/*
** EPITECH PROJECT, 2018
** indie
** File description:
** header
*/

#ifndef WALLS_HPP_
	#define WALLS_HPP_

#include "../../Entity.hpp"

class Walls : public entities::Entity {
	public:
		Walls(entities::entityPosition pos, bool iskinematic, std::size_t layout, entities::entityType type) :
		Entity(pos, iskinematic, layout, type, "") {}
		~Walls() override = default;
	protected:
};

#endif /* !WALLS_HPP_ */

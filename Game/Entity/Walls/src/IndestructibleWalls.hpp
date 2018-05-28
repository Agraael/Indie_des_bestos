/*
** EPITECH PROJECT, 2018
** indie
** File description:
** header
*/

#ifndef DESTRUCTIBLEWALLS_HPP_
	#define DESTRUCTIBLEWALLS_HPP_

#include "Walls.hpp"

class IndestructibleWalls : public Walls {
	public:
		IndestructibleWalls(entities::entityPosition pos, bool iskinematic, std::size_t layout) :
		Walls(pos, true, 3, "I") {}
		~IndestructibleWalls() {};

	private:
};

#endif /* !DESTRUCTIBLEWALLS_HPP_ */

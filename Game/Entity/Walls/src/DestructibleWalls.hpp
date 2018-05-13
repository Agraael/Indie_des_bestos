/*
** EPITECH PROJECT, 2018
** indie
** File description:
** header
*/

#ifndef DESTRUCTIBLEWALLS_HPP_
	#define DESTRUCTIBLEWALLS_HPP_

#include "Walls.hpp"

class DestructibleWalls : public Walls {
	public:
		DestructibleWalls(entities::entityPosition pos, bool iskinematic, std::size_t layout) :
		Walls(pos, true, 3) {}
		~DestructibleWalls() {};

	private:
};

#endif /* !DESTRUCTIBLEWALLS_HPP_ */

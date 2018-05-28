/*
** EPITECH PROJECT, 2018
** indie
** File description:
** header
*/

#ifndef INDESTRUCTIBLEWALLS_HPP_
	#define INDESTRUCTIBLEWALLS_HPP_

#include "Walls.hpp"
#include "../../Bonuses/src/BombUp.hpp"

class DestructibleWalls : public Walls {
	public:
		DestructibleWalls(entities::entityPosition pos, bool iskinematic,
		std::size_t layout, std::shared_ptr<BonusSpace::Bonus>, BonusSpace::BonusesTypes) :
		Walls(pos, true, 3, "D") {}
		~DestructibleWalls() {};

	private:
};

#endif /* !INDESTRUCTIBLEWALLS_HPP_ */

/*
** EPITECH PROJECT, 2018
** indie
** File description:
** header
*/

#ifndef INDESTRUCTIBLEWALLS_HPP_
	#define INDESTRUCTIBLEWALLS_HPP_

#include "Walls.hpp"
#include "../Bonuses/BombUp.hpp"

class IndestructibleWalls : public Walls {
public:
	IndestructibleWalls(entities::entityPosition pos, bool iskinematic,
			    std::size_t layout, std::shared_ptr<BonusSpace::Bonus>, BonusSpace::BonusesTypes) :
		Walls(pos, iskinematic, layout) {}
	~IndestructibleWalls() {};

private:
};

#endif /* !INDESTRUCTIBLEWALLS_HPP_ */

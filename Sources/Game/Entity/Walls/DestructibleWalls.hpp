/*
** EPITECH PROJECT, 2018
** indie
** File description:
** header
*/

#ifndef INDESTRUCTIBLEWALLS_HPP_
	#define INDESTRUCTIBLEWALLS_HPP_

#include "Walls.hpp"
#include "BombUp.hpp"

class DestructibleWalls : public Walls {
	public:
		DestructibleWalls(entities::entityPosition pos, bool iskinematic,
		std::size_t layout, std::shared_ptr<entities::Entity> bonus, BonusSpace::BonusesTypes) :
		Walls(pos, iskinematic, layout, entities::entityType::DESTRUCTIBLE_TYPE), _bonus(bonus) {}
		~DestructibleWalls() final {};
		std::shared_ptr<entities::Entity>	&getBonus() { return _bonus; };
	private:
		std::shared_ptr<entities::Entity>	_bonus;
};

#endif /* !INDESTRUCTIBLEWALLS_HPP_ */

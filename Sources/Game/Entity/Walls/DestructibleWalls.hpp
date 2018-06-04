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
<<<<<<< HEAD:Game/Entity/Walls/src/DestructibleWalls.hpp
	public:
		DestructibleWalls(entities::entityPosition pos, bool iskinematic,
		std::size_t layout, std::shared_ptr<BonusSpace::Bonus>, BonusSpace::BonusesTypes) :
		Walls(pos, iskinematic, layout, entities::entityType::DESTRUCTIBLE) {}
		~DestructibleWalls() {};
=======
public:
	DestructibleWalls(entities::entityPosition pos, bool iskinematic,
			  std::size_t layout, std::shared_ptr<BonusSpace::Bonus>, BonusSpace::BonusesTypes) :
		Walls(pos, iskinematic, layout, "D") {}
	~DestructibleWalls() {};
>>>>>>> 5e27efff015b9c8f505c3e916a707c0ba3b45a42:Sources/Game/Entity/Walls/DestructibleWalls.hpp

private:
};

#endif /* !INDESTRUCTIBLEWALLS_HPP_ */

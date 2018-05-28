/*
** EPITECH PROJECT, 2018
** indie
** File description:
** Bonuses
*/

#ifndef BONUSES_HPP_
	#define BONUSES_HPP_

#include "../Entity.hpp"

namespace BonusSpace {

	enum BonusesTypes {
		NO_BONUS,
		BOMBUP,
		SPEEDUP,
		FIREUP,
		WALLPASS
	};

	class Bonus : public entities::Entity {
	public:
		Bonus(entities::entityPosition pos, bool iskinematic, std::size_t layout) :
			entities::Entity(pos, iskinematic, layout) {}
		~Bonus() {};
	};
}

#endif /* !BONUSES_HPP_ */

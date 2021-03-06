/*
** EPITECH PROJECT, 2018
** indie
** File description:
** header
*/

#ifndef SPEEDUP_HPP_
	#define SPEEDUP_HPP_

#include "Bonus.hpp"

class SpeedUp : public BonusSpace::Bonus {
	public:
                SpeedUp(std::pair<float, float> pos, bool iskinematic, std::size_t layout) :
		BonusSpace::Bonus(pos, iskinematic, layout, entities::entityType::SPEED_UP_TYPE) {}
		~SpeedUp() final  = default;
		void	update() {};
	protected:
};

#endif /* !SPEEDUP_HPP_ */

/*
** EPITECH PROJECT, 2018
** indie
** File description:
** header
*/

#ifndef BOMBUP_HPP_
	#define BOMBUP_HPP_

#include "Bonus.hpp"

class BombUp : public BonusSpace::Bonus {
	public:
	BombUp(std::pair<float, float> pos, bool iskinematic, std::size_t layout) :
		BonusSpace::Bonus(pos, iskinematic, layout) {}
	~BombUp() {};
private:
};

#endif /* !BOMBUP_HPP_ */

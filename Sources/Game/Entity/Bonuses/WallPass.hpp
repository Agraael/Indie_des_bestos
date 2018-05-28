/*
** EPITECH PROJECT, 2018
** indie
** File description:
** header
*/

#ifndef WALLPASS_HPP_
	#define WALLPASS_HPP_

#include "Bonus.hpp"

class WallPass : public BonusSpace::Bonus {
	public:
	WallPass(entities::entityPosition pos, bool iskinematic, std::size_t layout) :
		BonusSpace::Bonus(pos, iskinematic, layout) {}

protected:
private:
};

#endif /* !WALLPASS_HPP_ */

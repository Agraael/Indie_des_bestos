/*
** EPITECH PROJECT, 2018
** FireUp
** File description:
** source
*/

#ifndef FIREUP_HPP_
	#define FIREUP_HPP_

#include "Bonus.hpp"

class FireUp : public BonusSpace::Bonus {
	public:
                FireUp(std::pair<float, float> pos, bool iskinematic, std::size_t layout) :
		BonusSpace::Bonus(pos, true, 3, "") {}

	protected:
	private:
};

#endif /* !FIREUP_HPP_ */

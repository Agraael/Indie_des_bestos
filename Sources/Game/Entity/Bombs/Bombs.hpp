/*
** EPITECH PROJECT, 2018
** Bombs
** File description:
** header
*/

#ifndef BOMBS_HPP_
	#define BOMBS_HPP_

#include "../../Entity.hpp"

class Bombs : public entities::Entity {
	public:
                Bombs(entities::entityPosition pos, bool iskinematic, std::size_t layout) :
		entities::Entity(pos, iskinematic, layout, "b") {}
};

#endif /* !BOMBS_HPP_ */

/*
** EPITECH PROJECT, 2018
** indie
** File description:
** indie
*/

#ifndef GONNAEXPLOSE_HPP_
	#define GONNAEXPLOSE_HPP_

#include "../../Entity.hpp"

class GonnaExplose : public entities::Entity {
	public:
                GonnaExplose(entities::entityPosition pos, bool iskinematic, std::size_t layout) :
		entities::Entity(pos, iskinematic, layout, entities::entityType::GONNAEXPLOSE_TYPE, "") {}
		~GonnaExplose() final = default;
		void	update() {};
};

#endif /* !GONNAEXPLOSE_HPP_ */

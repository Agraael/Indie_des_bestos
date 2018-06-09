/*
** EPITECH PROJECT, 2018
** indie
** File description:
** indie
*/

#ifndef GONNAEXPLOSE_HPP_
	#define GONNAEXPLOSE_HPP_

#include "Entity.hpp"
#include "Map.hpp"

class GonnaExplose : public entities::Entity {
	public:
                GonnaExplose(entities::entityPosition pos, bool iskinematic, std::size_t layout, Map &map) :
		entities::Entity(pos, iskinematic, layout, entities::entityType::GONNAEXPLOSE_TYPE, ""), _map(map) {}
		~GonnaExplose() {};
		void	update();
	private:
		Map	&_map;
};

#endif /* !GONNAEXPLOSE_HPP_ */

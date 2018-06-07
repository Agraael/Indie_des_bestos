/*
** EPITECH PROJECT, 2018
** Bombs
** File description:
** header
*/

#ifndef BOMBS_HPP_
	#define BOMBS_HPP_

#include "../../Entity.hpp"
#include <thread>

class Bombs : public entities::Entity {
	public:
                Bombs(entities::entityPosition pos, bool iskinematic, std::size_t layout) :
		entities::Entity(pos, iskinematic, layout, entities::entityType::BOMBS_TYPE, ""), _saveTime(std::time(nullptr)) {}
		~Bombs() final = default;
		bool	checkExplosion();
		void	update() {};
	private:
		time_t 	_saveTime;
};

#endif /* !BOMBS_HPP_ */

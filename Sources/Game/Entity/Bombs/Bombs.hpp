/*
** EPITECH PROJECT, 2018
** Bombs
** File description:
** header
*/

#ifndef BOMBS_HPP_
	#define BOMBS_HPP_

#include "Entity.hpp"
#include <ctime>
#include "GonnaExplose.hpp"
#include <thread>

class Bombs : public entities::Entity {
	public:
                Bombs(entities::entityPosition pos, bool iskinematic, std::size_t layout, std::vector<std::shared_ptr<entities::Entity>> &exploseTab) :
		entities::Entity(pos, iskinematic, layout, entities::entityType::BOMBS_TYPE, ""), _saveTime(std::time(nullptr)), _exploseTab(exploseTab) {
			for (auto &explosed : _exploseTab) {
				explosed->setMap(_map);
			}
		}
		~Bombs() final = default;
	void	update();
	private:
		time_t						_saveTime;
		std::vector<std::shared_ptr<entities::Entity>>	_exploseTab;
};

#endif /* !BOMBS_HPP_ */

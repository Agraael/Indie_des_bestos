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
#include <vector>

class Bombs : public entities::Entity {
	public:
                Bombs(entities::entityPosition pos, bool iskinematic, std::size_t layout, std::vector<std::shared_ptr<entities::Entity>> &exploseTab, Map &map) :
		entities::Entity(pos, iskinematic, layout, entities::entityType::BOMBS_TYPE, ""), _saveTime(std::time(nullptr)), _exploseTab(exploseTab), _map(map) {_chrono = Singleton::TimeManager::Instance().createChrono();}
		~Bombs() final = default;
	void	update();
	private:
		time_t						_saveTime;
		Singleton::ChronoId _chrono;
		std::vector<std::shared_ptr<entities::Entity>>	_exploseTab;
		Map	&_map;
};

#endif /* !BOMBS_HPP_ */

/*
** EPITECH PROJECT, 2018
** indie
** File description:
** source
*/

#include "Map.hpp"
#include "Bombs.hpp"
#include "GonnaExplose.hpp"

std::shared_ptr<entities::Entity>	Map::placeExplosion(entities::entityPosition pos)
{
	newEntity = std::make_shared<entities::Entity>(GonnaExplose(pos, false, 1));
	_map[pos.first][pos.second].push_back(newEntity);
}

void    Map::placeBomb(entities::entityPosition pos, std::size_t shinning)
{
	std::shared_ptr<entities::Entity>		newEntity;
	std::vector<std::shared_ptr<entities::Entity>>	exploseTab;

	for (int i = 1; i <= static_cast<int>(shining); ++i) {
		if ((pos.first - i) >= 0)
			exploseTab.push_back(placeExplosion(std::make_pair(pos.first - i, pos.second)));
		else if ((pos.first + i) >= 0) {
			exploseTab.push_back(placeExplosion(std::make_pair(pos.first + i, pos.second)));			
		else if ((pos.second - i) >= 0)
			exploseTab.push_back(placeExplosion(std::make_pair(pos.first, pos.second - i)));
		else if ((pos.second + i) >= 0)
			exploseTab.push_back(placeExplosion(std::make_pair(pos.first, pos.second + i)));		
	}
 	_map[pos.first][pos.second].push_back(std::make_shared<entities::Entity>(Bombs(pos, false, 0)));
}

void	Map::deleteElem(std::shared_ptr<entities::Entity> entity)
{
//	std::size_t	index;

	std::cout << entity.get()->getPos().first << " " << entity.get()->getPos().second << std::endl;
	//_map[entity.get()->getPos().first][entity.get()->getPos().second].pop_back();
	for (auto elem : _map[3][4]) {
		if (elem.get()->getType() == entity.get()->getType())
			std::cout << elem.get()->getPos().first << " " << elem.get()->getPos().second << std::endl;
//		++index;
	}
/*  	for (auto line : _map) {
		for (auto tab : line) {
			index = 0;
			for (auto elem : tab) {
				if (elem.get()->getType() == entity.get()->getType())
					_map[entity.get()->getPos().first][entity.get()->getPos().second].erase((_map[entity.get()->getPos().first][entity.get()->getPos().second]).begin()+index);
				++index;
			}
		}
	} */
}

void	Map::displayMap()
{
	for (auto line : _map) {
		for (auto tab : line) {
			for (std::size_t i = 0; i < tab.size(); ++i) {
				if (tab[i].get()->getType() == entities::entityType::IA_TYPE)
					std::cout << "a";
				else
					std::cout << "l";
			}
			if (tab.empty())
				std::cout << " ";
		}
		std::cout << std::endl;
	}
}

void	Map::updatePos(std::shared_ptr<entities::Entity> entity, entities::entityPosition pos)
{
	std::size_t 	index = 0;

	for (auto line : _map) {
		for (auto tab : line) {
			for (auto shared : tab) {
				if (shared.get()->getId() == entity.get()->getId() && index == 0) {
					_map[pos.first][pos.second].push_back(entity);
					deleteElem(entity);
					displayMap();
					++index;
				}				
			}
		}
	}	
}
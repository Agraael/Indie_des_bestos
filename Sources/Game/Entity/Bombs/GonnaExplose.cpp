/*
** EPITECH PROJECT, 2018
** indie
** File description:
** source
*/

#include "GonnaExplose.hpp"

void    GonnaExplose::update()
{
	//if (_layout == 1) {
	//	std::cout << "non" << std::endl;		
		_map.checkExplosionCollision(_pos);
	std::cout << "gonna explose id : " << _id << std::endl;
	for (auto line : _map.get3dMap()) {
		for (auto column : line) {
			for (auto shared : column) {
				if (shared->getType() == entities::entityType::PLAYER_TYPE) {
	//				std::cout << "player gonna explose : " << shared->getPos().first << " " << shared->getPos().second << std::endl;
					std::cout << "player id" << shared->getId() << std::endl;
				}
			}
		}
	}

//		_saveTime = std::time(nullptr);
//	}
//	if (_layout == 0) {
//		if ((std::time(nullptr) - _saveTime) > 1)
//			std::cout << "oui" << std::endl;
//			_map.addDeletedEntity();
//	}
}
/*
** EPITECH PROJECT, 2018
** indie
** File description:
** source
*/

#include "Player.hpp"

void	Player::update()
{
	std::size_t	index = 0;
		std::cout << index << std::endl;

	for (auto event : _eventPlayer) {
		++index;
		std::cout << event << std::endl;
		//std::cout << event << std::endl;
	/* 	if (_lib->getEventManager()->IsKeyDown(irr::KEY_KEY_Z)) {
			std::cout << "oui" << std::endl;
			std::cout << event << std::endl;
		} */
	}
}

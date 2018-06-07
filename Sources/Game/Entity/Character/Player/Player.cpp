/*
** EPITECH PROJECT, 2018
** indie
** File description:
** source
*/

#include "Player.hpp"

void	Player::interpretEvent()
{
	std::size_t	index = 0;
		std::cout << index << std::endl;

	if (_eventPlayer.empty())
		std::cout << "problème" << std::endl;
	for (auto event : _eventPlayer) {
		++index;
		(void)event;
		//std::cout << event << std::endl;
	/* 	if (_lib->getEventManager()->IsKeyDown(irr::KEY_KEY_Z)) {
			std::cout << "oui" << std::endl;
			std::cout << event << std::endl;
		} */
	}
}

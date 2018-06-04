/*
** EPITECH PROJECT, 2018
** indie
** File description:
** source
*/

#include "Player.hpp"

void	Player::interpretEvent()
{
	if (_lib->getEventManager()->IsKeyDown(irr::KEY_KEY_Z))
		std::cout << "M D R" << std::endl;
}

/*
** EPITECH PROJECT, 2018
** indie des bestos
** File description:
** source
*/

#include "Character.hpp"

void    Character::deleteBombs()
{
        std::size_t     x;

 	for (unsigned int i = 0; i < _playerBombs.size(); i++) {
		x = 0;
		for (auto oldEntity :_playerBombs) {
			if (oldEntity ==  nullptr) {
                                std::cout << "oui" << std::endl;
				_playerBombs.erase(_playerBombs.begin() + x);
				break;
			}
			++x;
		}
	}
}
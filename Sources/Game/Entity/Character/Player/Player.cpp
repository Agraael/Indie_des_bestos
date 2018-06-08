/*
** EPITECH PROJECT, 2018
** indie
** File description:
** source
*/

#include "Player.hpp"

void	Player::update()
{
	std::size_t			index = 0;
	entities::entityPosition	newPos = _pos;

	for (auto event : _eventPlayer) {
		if (_lib->getEventManager()->IsKeyDown(event) && index < 4) {
			auto func = _foncter[index];
			newPos = func(_map->get3dMap(), _pos);
		}
		else if (_lib->getEventManager()->IsKeyDown(event))
			_map->placeBomb(_pos, _power);
		++index;
	}
	if (newPos != std::make_pair(0, 0) && newPos != _pos && _mooved == false) {
		_mooved = true;
		_map->updatePos(reinterpret_cast<Entity *>(this), newPos);
		_pos = newPos;
	}

}

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
	Singleton::TimeManager		&timer = Singleton::TimeManager::Instance();

	for (auto event : _eventPlayer) {
		if (_lib->getEventManager()->IsKeyDown(event) && index < 4) {
			auto func = _foncter[index];
			newPos = func(_map->get3dMap(), _pos, _wallpass);
		}
		else if (_lib->getEventManager()->IsKeyDown(event))
			_map->placeBomb(_pos, _power);
		++index;
	}
	if (_speed <= 5) {
		if (timer.getChronoDuration(_chrono) < (0.12f - (static_cast<float>(_speed) / 100.0f))) {
			return;
		}
	} else {
		if (timer.getChronoDuration(_chrono) < 0.08f)
			return;
	}
	if (newPos != std::make_pair(0, 0) && newPos != _pos) {
		_mooved = true;
		_map->updatePos(reinterpret_cast<Entity *>(this), newPos);
		_pos = newPos;
	}
	timer.resetChrono(_chrono);
}

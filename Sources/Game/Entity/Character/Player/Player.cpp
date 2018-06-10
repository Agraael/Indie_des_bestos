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
	
	Character::deleteBombs();
	for (auto event : _eventPlayer) {
		if (_lib->getEventManager()->IsKeyDown(event) && index < 4) {
			auto func = _foncter[index];
			newPos = func(_map->get3dMap(), _pos);
		}
		else if (_lib->getEventManager()->IsKeyDown(event) && _playerBombs.size() <= _bombs) {
			std::cout << _bombs << std::endl;
			std::cout << _playerBombs.size() << std::endl;
			_playerBombs.push_back(_map->placeBomb(_pos, _power));
			std::cout << "non" << std::endl;
		}
		++index;
	}
	if (timer.getChronoDuration(_chrono) < 0.1f) {
		return;
	}
	else if (newPos != std::make_pair(0, 0) && newPos != _pos) {
		_mooved = true;
		_map->updatePos(reinterpret_cast<Entity *>(this), newPos);
		_pos = newPos;
	}
	timer.resetChrono(_chrono);
}

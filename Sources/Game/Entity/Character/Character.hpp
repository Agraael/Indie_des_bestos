//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include <iostream>
#include <utility>
#include <functional>
#include <vector>
#include "../Entity.hpp"

#ifndef CHARACTER_HPP_
	#define CHARACTER_HPP_

/* class Character {
public:
	Character(std::vector<std::string> &positionMap, std::vector<std::string>
	&dynamicMap) : _positionMap(positionMap), _dynamicMap(dynamicMap) {};
protected:
	std::vector<std::string> &_positionMap;
	std::vector<std::string> &_dynamicMap;
	std::pair<int, int> _pos;
}; */

class Character : public entities::Entity {
public:
	Character(entities::entityPosition pos, bool iskinematic, std::size_t layout, entities::entityType type, std::string name) :
	Entity(pos, iskinematic, layout, type, name), _power(1), _bombs(1),  _speed(1), _wallpass(0) {}
	~Character() override = default;
	void	upgradeBombs() noexcept { _bombs += 1; }
        void	upgradeSpeed() noexcept { _speed += 1; }
        void	upgradePower() noexcept { _power += 1; }
	int	getWallpass() {return _wallpass; }
        void	upgradeWallpass() noexcept { if (_wallpass != 2) {_wallpass = 2;} else {_wallpass = 0;} }
protected:
	int				_power;
        std::size_t			_bombs;
        int				_speed;
        int				_wallpass;
};

#endif /* !CHARACTER_HPP */

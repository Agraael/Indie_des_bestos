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

class Character {
public:
	Character(std::vector<std::string> &positionMap, std::vector<std::string>
	&dynamicMap) : _positionMap(positionMap), _dynamicMap(dynamicMap) {};
protected:
	std::vector<std::string> &_positionMap;
	std::vector<std::string> &_dynamicMap;
	std::pair<int, int> _pos;
};

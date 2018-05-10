//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include <string>
#include "Algorithm.hpp"
#include "Ia.hpp"

void Ia::printMap(std::vector<std::string> &map)
{
	for (auto i : map)
		std::cout << i << std::endl;
}

int Ia::checkIfDead(const std::vector<std::string> &map, std::pair<int, int> &pos)
{
	if (map[pos.first][pos.second] != 'J')
		return (0);
	return (1);
}

int Ia::isInDangerousPosition(const std::vector<std::string> &dynamic_map, std::pair<int, int> &pos)
{
	if (dynamic_map[pos.first][pos.second] != '0')
		return (0);
	return (1);
}

void Ia::placeIa(std::vector<std::string> &map)
{
	map[1][1] = 'J';
	_pos = std::make_pair(1, 1);
}

Ia::Ia(std::vector<std::string> &position_map, std::vector<std::string> &dynamic_map) : Character(position_map, dynamic_map)
{
	placeIa(_positionMap);
	printMap(_positionMap);
	Algorithm *iaAlgo = new Algorithm;
	while (1) {
		if (checkIfDead(_positionMap, _pos) == 0)
			return ;
		if (isInDangerousPosition(_dynamicMap, _pos) == 0) {
			std::pair<int, int> pos_to_go =
				iaAlgo->defensiveMove(_positionMap, _dynamicMap, _pos);
			(void)(pos_to_go);
		}
	}
}

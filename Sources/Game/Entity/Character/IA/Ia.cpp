//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include "Algorithm.hpp"
#include "Ia.hpp"

/* void Ia::printMap(std::vector<std::string> &map)
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
*/
Ia::Ia(entities::entityPosition pos, bool iskinematic, std::size_t layout) :
                Character(pos, iskinematic, layout, entities::entityType::IA_TYPE)
{
	// Algorithm *algo = new Algorithm;
	// std::pair<int, int> move;
	// std::pair<int, int> pos_player = {0, 0};

	//GameMap map = _map.get3dmap();
	//move = algo->defensiveMove(map, pos_player);
}

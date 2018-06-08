//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include "Algorithm.hpp"
#include "Ia.hpp"

void Ia::update()
{
        std::pair<int, int> move = std::make_pair<int, int>(1, 1);
        GameMap map = _map->get3dMap();
	Algorithm *algo = new Algorithm;

	(void)(algo);
 	/*if (algo->check_if_dangerous_zone(map, _pos) == true) {
		move = algo->defensiveMove(map, _pos);
	}
	else {
		move = algo->offensiveMove(map, _pos, _map);
	}*/
	//if (_pos != move) {
		_map->updatePos(this, move);
	//}
	_pos = move;
}

Ia::Ia(entities::entityPosition pos, bool iskinematic, std::size_t layout, std::string name) :
                Character(pos, iskinematic, layout, entities::entityType::IA_TYPE, name)
{
}

//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include "Algorithm.hpp"
#include "Ia.hpp"

void Ia::turn()
{
        //Algorithm *algo = new Algorithm;
        std::pair<int, int> move = _pos;
        GameMap map = _map->get3dMap();

	/* if (algo->check_if_dangerous_zone(map, _pos) == true) {
		move = algo->defensiveMove(map, _pos);
	}
	else {
		move = algo->offensiveMove(map, _pos, _map);
	} */
	_map->updatePos(static_cast<std::shared_ptr<Entity>>(this), move);
	std::cout << std::endl;
	_map->displayMap();
	_pos = move;
}

Ia::Ia(entities::entityPosition pos, bool iskinematic, std::size_t layout) :
                Character(pos, iskinematic, layout, entities::entityType::IA_TYPE)
{
}

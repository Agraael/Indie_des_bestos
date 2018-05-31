/*
** EPITECH PROJECT, 2018
** indie
** File description:
** header
*/

#include "Entity.hpp"
#include <iostream>
#include <utility>
#include <functional>
#include "Walls.hpp"
#include <vector>

#ifndef MOVETO_HPP_
	#define MOVETO_HPP_

class MoveTo {
public:
	MoveTo();
	~MoveTo();
	std::pair<int, int> move_to_pos(entities::Entity *player, std::pair<int, int> pos_character,
					std::pair<int, int> pos_to_go, std::shared_ptr<Map> shared_map);
	std::pair<int, int> try_move_up(std::vector<std::vector<std::vector<std::shared_ptr<entities::Entity>>>> &map,
					std::pair<int, int> pos_character);
	std::pair<int, int> try_move_down(std::vector<std::vector<std::vector<std::shared_ptr<entities::Entity>>>> &map,
					  std::pair<int, int> pos_character);
	std::pair<int, int> try_move_right(std::vector<std::vector<std::vector<std::shared_ptr<entities::Entity>>>> &map,
					   std::pair<int, int> pos_character);
	std::pair<int, int> try_move_left(std::vector<std::vector<std::vector<std::shared_ptr<entities::Entity>>>> &map,
					  std::pair<int, int> pos_character);
private:
};

#endif /* !MOVETO_HPP_ */
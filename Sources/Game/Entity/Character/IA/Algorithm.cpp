//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include "Algorithm.hpp"

bool Algorithm::check_if_dangerous_zone(std::vector<std::vector<std::vector<std::shared_ptr<entities::Entity>>>> &map, std::pair<int, int> &pos)
{
	for (auto &entity : map[pos.first][pos.second]) {
		if (std::static_pointer_cast<GonnaExplose>(entity) != nullptr)
			return true;
		//else if (std::static_pointer_cast<Bombs>(entity) != nullptr)
		//	return true;
	}
	return false;
}

std::pair<int, int> Algorithm::init_directions(std::vector<std::vector<std::vector<std::shared_ptr<entities::Entity>>>> &map, std::pair<int, int> current_pos)
{
	std::pair<int, int> direction;
        std::pair<int, int> empty_pair = {};
        MoveTo *dir = new MoveTo;

	if ((direction = dir->try_move_up(map, current_pos)) != empty_pair)
		return (aim_at_a_further_point(map, UP, 1, direction));
        direction = dir->try_move_down(map, current_pos);
        if (direction != empty_pair)
		return (aim_at_a_further_point(map, DOWN, 1, direction));
        direction = dir->try_move_left(map, current_pos);
        if (direction != empty_pair)
		return (aim_at_a_further_point(map, LEFT, 1, direction));
        direction = dir->try_move_right(map, current_pos);
	if (direction != empty_pair)
		return (aim_at_a_further_point(map, RIGHT, 1, direction));
	return {};
}

std::pair<int, int> Algorithm::found_safe_point(int nbr_moves, int first_dir, std::pair<int, int> &direction)
{
	_dir = first_dir;
	_nbr_of_moves = nbr_moves;
	return (direction);
}

std::pair<int, int> Algorithm::aim_at_a_further_point(std::vector<std::vector<std::vector<std::shared_ptr<entities::Entity>>>> &map, int first_dir, int nbr_moves, std::pair<int, int> current_pos)
{
	std::pair<int, int> direction;
        std::pair<int, int> empty_pair = {};
	MoveTo *dir = new MoveTo;

	if (first_dir == 0)
		init_directions(map, current_pos);
	else if (nbr_moves > _nbr_of_moves)
		return {};
	direction = dir->try_move_up(map, current_pos);
	if (direction != empty_pair) {
		if (check_if_dangerous_zone(map, direction) == false)
			return (found_safe_point(nbr_moves, first_dir, direction));
		else
			aim_at_a_further_point(map, first_dir, nbr_moves + 1, direction);
	}
	direction = dir->try_move_down(map, current_pos);
        if (direction != empty_pair) {
                if (check_if_dangerous_zone(map, direction) == false)
                        return (found_safe_point(nbr_moves, first_dir, direction));
                else
                        aim_at_a_further_point(map, first_dir, nbr_moves + 1, direction);
        }
	direction = dir->try_move_left(map, current_pos);
        if (direction != empty_pair) {
                if (check_if_dangerous_zone(map, direction) == false)
                        return (found_safe_point(nbr_moves, first_dir, direction));
                else
                        aim_at_a_further_point(map, first_dir, nbr_moves + 1, direction);
        }
	direction = dir->try_move_right(map, current_pos);
        if (direction != empty_pair) {
                if (check_if_dangerous_zone(map, direction) == false)
                        return (found_safe_point(nbr_moves, first_dir, direction));
                else
                        aim_at_a_further_point(map, first_dir, nbr_moves + 1, direction);
        }
	return {};
}

std::pair<int, int> Algorithm::findNearestSafePoint(std::vector<std::vector<std::vector<std::shared_ptr<entities::Entity>>>> &map, std::pair<int, int> &posPlayer)
{
	MoveTo *dir = new MoveTo;
	std::pair<int, int> direction;
	std::pair<int, int> empty_pair = {};

	if ((direction = dir->try_move_up(map, posPlayer)) != empty_pair) {
		if (check_if_dangerous_zone(map, direction) == false)
			return (direction);
	}
	direction = dir->try_move_down(map, posPlayer);
        if (direction != empty_pair)
                if (check_if_dangerous_zone(map, direction) == false)
			return (direction);
	direction = dir->try_move_left(map, posPlayer);
        if (direction != empty_pair)
                if (check_if_dangerous_zone(map, direction) == false)
			return (direction);
	direction = dir->try_move_right(map, posPlayer);
        if (direction != empty_pair)
                if (check_if_dangerous_zone(map, direction) == false)
			return (direction);
	_posPlayer = posPlayer;
	_nbr_of_moves = 100;
	direction = posPlayer;
	return (aim_at_a_further_point(map, 0, 0, direction));
}

std::pair<int, int> Algorithm::defensiveMove(std::vector<std::vector<std::vector<std::shared_ptr<entities::Entity>>>> &map, std::pair<int, int> &posPlayer)
{
	return findNearestSafePoint(map, posPlayer);
}

//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include "Algorithm.hpp"

bool Algorithm::check_if_dangerous_zone(const GameMap &map, const std::pair<int, int> &pos)
{
	for (auto &entity : map[pos.first][pos.second]) {
		if (entity.get()->getType() ==
		    entities::entityType::GONNAEXPLOSE_TYPE ||
		    entity.get()->getType() ==
		    entities::entityType::BOMBS_TYPE)
			return true;
	}
	return false;
}

bool Algorithm::is_bomb_here(const GameMap &map, const std::pair<int, int> &pos)
{
	for (auto &entity : map[pos.first][pos.second]) {
		if (entity.get()->getType() ==
		    entities::entityType::BOMBS_TYPE)
                        return true;
	}
	return false;
}

bool Algorithm::is_character_here(const GameMap &map, const std::pair<int, int> &pos)
{
	for (auto &entity : map[pos.first][pos.second]) {
		if (entity.get()->getType() ==
                    entities::entityType::IA_TYPE ||
                    entity.get()->getType() ==
                    entities::entityType::PLAYER_TYPE)
                        return true;
	}
        return false;
}

bool Algorithm::is_wall_destructible(const GameMap &map, const std::pair<int, int> &pos)
{
	for (auto &entity : map[pos.first][pos.second]) {
		if (entity.get()->getType() ==
                    entities::entityType::DESTRUCTIBLE_TYPE)
                        return true;
        }
        return false;

}

int Algorithm::init_directions(GameMap &map, std::pair<int, int> current_pos)
{
	std::pair<unsigned int, unsigned int> direction = current_pos;

	for (direction = current_pos; direction.first + 1 < map.size(); direction.first += 1) {
		for (auto entity : map[direction.first][direction.second]) {
			if (check_if_dangerous_zone(map, direction) == false)
				break;
			if (is_bomb_here(map, direction) == true)
				return UP;
		}
	}
	for (direction = current_pos; direction.first >= 1; direction.first -= 1) {
                for (auto entity : map[direction.first][direction.second]) {
                        if (check_if_dangerous_zone(map, direction) == false)
                                break;
                        if (is_bomb_here(map, direction) == true)
                                return DOWN;
                }
        }
	for (direction = current_pos; direction.second + 1 > map[direction.first].size(); direction.second += 1) {
                for (auto entity : map[direction.first][direction.second]) {
                        if (check_if_dangerous_zone(map, direction) == false)
                                break;
                        if (is_bomb_here(map, direction) == true)
                                return RIGHT;
                }
        }
	for (direction = current_pos; direction.second >= 1; direction.second -= 1) {
	        for (auto entity : map[direction.first][direction.second]) {
                        if (check_if_dangerous_zone(map, direction) == false)
                                break;
                        if (is_bomb_here(map, direction) == true)
                                return LEFT;
                }
	}
	return {};
}

std::pair<int, int> Algorithm::defensiveRight(GameMap &map, std::pair<int, int> current_pos)
{
	std::pair<int, int> direction;
	std::pair<int, int> empty_pair = {};
	MoveTo *dir = new MoveTo;

	direction = dir->try_move_right(map, current_pos);
	if (direction != empty_pair)
		return direction;
	direction = dir->try_move_up(map, current_pos);
	if (direction != empty_pair)
		return direction;
	direction = dir->try_move_down(map, current_pos);
        if (direction != empty_pair)
		return direction;
	return current_pos;
}

std::pair<int, int> Algorithm::defensiveLeft(GameMap &map, std::pair<int, int> current_pos)
{
        std::pair<int, int> direction;
        std::pair<int, int> empty_pair = {};
        MoveTo *dir = new MoveTo;

        direction = dir->try_move_left(map, current_pos);
        if (direction != empty_pair)
		return direction;
	direction = dir->try_move_down(map, current_pos);
        if (direction != empty_pair)
		return direction;
        direction = dir->try_move_up(map, current_pos);
	if (direction != empty_pair)
                return direction;
        return current_pos;
}

std::pair<int, int> Algorithm::defensiveUp(GameMap &map, std::pair<int, int> current_pos)
{
        std::pair<int, int> direction;
        std::pair<int, int> empty_pair = {};
        MoveTo *dir = new MoveTo;

        direction = dir->try_move_up(map, current_pos);
        if (direction != empty_pair)
		return direction;
	direction = dir->try_move_left(map, current_pos);
        if (direction != empty_pair)
		return direction;
        direction = dir->try_move_right(map, current_pos);
	if (direction != empty_pair)
                return direction;
        return current_pos;
}

std::pair<int, int> Algorithm::defensiveDown(GameMap &map, std::pair<int, int> current_pos)
{
        std::pair<int, int> direction;
        std::pair<int, int> empty_pair = {};
        MoveTo *dir = new MoveTo;

        direction = dir->try_move_down(map, current_pos);
        if (direction != empty_pair)
		return direction;
	direction = dir->try_move_right(map, current_pos);
        if (direction != empty_pair)
		return direction;
        direction = dir->try_move_left(map, current_pos);
	if (direction != empty_pair)
                return direction;
        return current_pos;
}

std::pair<int, int> Algorithm::aim_at_a_further_point(GameMap &map, int /*first_dir*/, int /*nbr_moves*/, std::pair<int, int> current_pos)
{
	int dir_bomb = init_directions(map, current_pos);

	if (dir_bomb == LEFT)
		return defensiveRight(map, current_pos);
	else if (dir_bomb == RIGHT)
		return defensiveLeft(map, current_pos);
	else if (dir_bomb == DOWN)
		return defensiveUp(map, current_pos);
	else if (dir_bomb == UP)
		return defensiveDown(map, current_pos);
	return current_pos;
}

std::pair<int, int> Algorithm::findNearestSafePoint(GameMap &map, std::pair<int, int> &posPlayer)
{
	MoveTo *dir = new MoveTo;
	std::pair<int, int> direction;
	std::pair<int, int> empty_pair = {};

	if ((direction = dir->try_move_up(map, posPlayer)) != empty_pair) {
		if (check_if_dangerous_zone(map, direction) == false || is_bomb_here(map, posPlayer) == true)
			return (direction);
	}
	direction = dir->try_move_down(map, posPlayer);
        if (direction != empty_pair)
                if (check_if_dangerous_zone(map, direction) == false || is_bomb_here(map, posPlayer) == true)
			return (direction);
	direction = dir->try_move_left(map, posPlayer);
        if (direction != empty_pair)
                if (check_if_dangerous_zone(map, direction) == false || is_bomb_here(map, posPlayer) == true)
			return (direction);
	direction = dir->try_move_right(map, posPlayer);
        if (direction != empty_pair)
                if (check_if_dangerous_zone(map, direction) == false || is_bomb_here(map, posPlayer) == true)
			return (direction);
	direction = posPlayer;
	return (aim_at_a_further_point(map, 0, 0, direction));
}

std::pair<int, int> Algorithm::defensiveMove(GameMap &map, std::pair<int, int> &posPlayer)
{
	return findNearestSafePoint(map, posPlayer);
}

std::pair<int, int> Algorithm::locate_enemy(GameMap &map, std::pair<int, int> &pos_ia)
{
	int max_pos = static_cast<int>(map.size());
	std::pair<int, int> current_pos;

	for (int pos_x = 0; pos_x < max_pos; pos_x++) {
		for (int pos_y = 0; pos_y < max_pos; pos_y++) {
			current_pos.first = pos_x;
			current_pos.second = pos_y;
			if (pos_ia != current_pos && is_character_here(map, current_pos) == true)
				return (current_pos);
		}
	}
	return {1, 1};
}

bool Algorithm::try_to_put_a_bomb(GameMap &map, std::pair<int, int> &posPlayer, std::shared_ptr<Map> _map)
{
	GameMap fake_map = map;
	//auto new_map = _map;
	Map *new_map = new Map(fake_map);
	std::pair<int, int> fake_pos = posPlayer;
	_nbr_of_moves = 0;
	new_map->placeBomb(posPlayer, 3);
	findNearestSafePoint(fake_map, posPlayer);
	for (int x = 0; x < 5; x++) {
		fake_pos = defensiveMove(map, fake_pos);
		if (check_if_dangerous_zone(map, fake_pos) == false) {
			_map->placeBomb(posPlayer, 3);
			return true;
		}
	}
	return false;
}

std::pair<int, int> Algorithm::offensiveUp(GameMap &map, std::pair<int, int> &posPlayer, std::shared_ptr<Map> _map)
{
	std::pair<int, int> direction;
	std::pair<int, int> empty_pair = {};
        MoveTo *dir = new MoveTo;

	direction.first = posPlayer.first + 1;
	direction.second = posPlayer.second;
	_offensive_tries++;
	if ((dir->try_move_up(map, posPlayer)) != empty_pair) {
		if (check_if_dangerous_zone(map, direction) == false) {
			return (direction);
		}
	}
	else {
		direction.first = posPlayer.first + 1;
		direction.second = posPlayer.second;
		if (is_wall_destructible(map, direction)) {
			if (try_to_put_a_bomb(map, posPlayer, _map) == true)
				return (posPlayer);
		}
	}
	return ((_offensive_tries < 5) ? (offensiveLeft(map, posPlayer, _map)) : (posPlayer));
}

std::pair<int, int> Algorithm::offensiveDown(GameMap &map, std::pair<int, int> &posPlayer, std::shared_ptr<Map> _map)
{
	std::pair<int, int> direction;
	std::pair<int, int> empty_pair = {};
        MoveTo *dir = new MoveTo;

	direction.first = posPlayer.first - 1;
	direction.second = posPlayer.second;
	_offensive_tries++;
	if ((direction = dir->try_move_down(map, posPlayer)) != empty_pair) {
		if (check_if_dangerous_zone(map, direction) == false) {
			return (direction);
		}
	}
	else {
		direction.first = posPlayer.first - 1;
		direction.second = posPlayer.second;
		if (is_wall_destructible(map, direction)) {
			if (try_to_put_a_bomb(map, posPlayer, _map) == true)
				return (posPlayer);
		}
	}
	return ((_offensive_tries < 5) ? (offensiveRight(map, posPlayer, _map)) : (posPlayer));       
}

std::pair<int, int> Algorithm::offensiveLeft(GameMap &map, std::pair<int, int> &posPlayer, std::shared_ptr<Map> _map)
{
	std::pair<int, int> direction;
	std::pair<int, int> empty_pair = {};
        MoveTo *dir = new MoveTo;

	direction.first = posPlayer.first;
	direction.second = posPlayer.second - 1;
	_offensive_tries++;
	if ((direction = dir->try_move_right(map, posPlayer)) != empty_pair) {
		if (check_if_dangerous_zone(map, direction) == false) {
			return (direction);
		}
	}
	else {
		direction.first = posPlayer.first;
		direction.second = posPlayer.second - 1;
		if (is_wall_destructible(map, direction)) {
			if (try_to_put_a_bomb(map, posPlayer, _map) == true)
				return (posPlayer);
			else
				return posPlayer;
		}
	}
	return ((_offensive_tries < 5) ? (offensiveDown(map, posPlayer, _map)) : (posPlayer));
}

std::pair<int, int> Algorithm::offensiveRight(GameMap &map, std::pair<int, int> &posPlayer, std::shared_ptr<Map> _map)
{
	std::pair<int, int> direction;
	std::pair<int, int> empty_pair = {};
        MoveTo *dir = new MoveTo;

	direction.first = posPlayer.first;
	direction.second = posPlayer.second + 1;
	_offensive_tries++;
	if ((direction = dir->try_move_left(map, posPlayer)) != empty_pair) {
		if (check_if_dangerous_zone(map, direction) == false) {
			return (direction);
		}
	}
	else {
		direction.first = posPlayer.first;
		direction.second = posPlayer.second + 1;
		if (is_wall_destructible(map, direction)) {
			if (try_to_put_a_bomb(map, posPlayer, _map) == true)
				return (posPlayer);
		}
	}
	return ((_offensive_tries < 5) ? (offensiveUp(map, posPlayer, _map)) : (posPlayer));
}

std::pair<int, int> Algorithm::offensiveMove(GameMap &map, std::pair<int, int> &posPlayer, std::shared_ptr<Map> _map)
{
	std::pair<int, int> pos_enemy = locate_enemy(map, posPlayer);
	std::pair<int, int> direction;

	_offensive_tries = 0;
	if (pos_enemy.first < posPlayer.first) {
		direction = offensiveUp(map, posPlayer, _map);
	} else if (pos_enemy.first > posPlayer.first) {
		direction = offensiveDown(map, posPlayer, _map);
        } else if (pos_enemy.second < posPlayer.second) {
		direction = offensiveLeft(map, posPlayer, _map);
        } else {
		direction = offensiveRight(map, posPlayer, _map);
        }
	std::cout << direction.first << " " << direction.second << std::endl;
	return direction;
}

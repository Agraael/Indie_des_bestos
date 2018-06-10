//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//


#ifndef ALGORITHM_HPP_
#define ALGORITHM_HPP_

#include <iostream>
#include <utility>
#include <vector>
#include <functional>
#include "Entity.hpp"
#include "Character.hpp"
#include "Walls.hpp"
#include "TimeManager.hpp"
#include "Map.hpp"
#include "MoveTo.hpp"
#include "GonnaExplose.hpp"

#define LEFT 1
#define RIGHT 2
#define UP 3
#define DOWN 4

typedef struct s_choice {
	int first;
	int second;
} t_choice;

class Algorithm {
public:
	Algorithm(int power, Singleton::ChronoId chronoBomb) : _power(power), _chronoBomb(chronoBomb) {};
	std::pair<int, int> defensiveMove(GameMap &map, std::pair<int, int> &posPlayer);
        std::pair<int, int> offensiveMove(GameMap &map, std::pair<int, int> &posPlayer, std::shared_ptr<Map> _map);
	bool check_if_dangerous_zone(const GameMap &map, const std::pair<int, int> &pos);
private:
	bool is_bomb_here(const GameMap &map, const std::pair<int, int> &pos);
	int init_directions(GameMap &map, std::pair<int, int> current_pos);
	std::pair<int, int> aim_at_a_further_point(GameMap &map, int first_dir, int nbr_moves, std::pair<int, int> current_pos);
	bool is_character_here(const GameMap &map, const std::pair<int, int> &pos);
	std::pair<int, int> findNearestSafePoint(GameMap &map, std::pair<int, int> &posPlayer);
	std::pair<int, int> locate_enemy(GameMap &map, std::pair<int, int> &posPlayer);
	bool try_to_put_a_bomb(GameMap &map, std::pair<int, int> posPlayer, std::shared_ptr<Map> _map);
	bool is_wall_destructible(const GameMap &map, const std::pair<int, int> &pos);
	std::pair<int, int> offensiveUp(GameMap &map, std::pair<int, int> &posPlayer, std::shared_ptr<Map> _map);
	std::pair<int, int> offensiveDown(GameMap &map, std::pair<int, int> &posPlayer, std::shared_ptr<Map> _map);
	std::pair<int, int> offensiveLeft(GameMap &map, std::pair<int, int> &posPlayer, std::shared_ptr<Map> _map);
	std::pair<int, int> offensiveRight(GameMap &map, std::pair<int, int> &posPlayer, std::shared_ptr<Map> _map);
	std::pair<int, int> defensiveDown(GameMap &map, std::pair<int, int> current_pos);
	std::pair<int, int> defensiveUp(GameMap &map, std::pair<int, int> current_pos);
	std::pair<int, int> defensiveLeft(GameMap &map, std::pair<int, int> current_pos);
	std::pair<int, int> defensiveRight(GameMap &map, std::pair<int, int> current_pos);
	std::pair<int, int> _posPlayer;
	int _dir;
	int _nbr_of_moves;
	int _offensive_tries;
	int _power;
	Singleton::ChronoId _chronoBomb;
};

#endif /* !ALGORITHM_HPP_ */

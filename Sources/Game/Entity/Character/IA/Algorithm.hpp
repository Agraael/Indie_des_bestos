//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include <iostream>
#include <utility>
#include <vector>
#include <functional>
#include "Entity.hpp"
#include "Character.hpp"
#include "Walls.hpp"
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
	Algorithm() {};
	std::pair<int, int> init_directions(std::vector<std::vector<std::vector<std::shared_ptr<entities::Entity>>>> &map, std::pair<int, int> current_pos);
	std::pair<int, int> found_safe_point(int nbr_moves, int first_dir, std::pair<int, int> &direction);
	std::pair<int, int> aim_at_a_further_point(std::vector<std::vector<std::vector<std::shared_ptr<entities::Entity>>>> &map, int first_dir, int nbr_moves, std::pair<int, int> current_pos);
	bool check_if_dangerous_zone(std::vector<std::vector<std::vector<std::shared_ptr<entities::Entity>>>> &map, std::pair<int, int> &pos);
	bool is_character_here(std::vector<std::vector<std::vector<std::shared_ptr<entities::Entity>>>> &map, std::pair<int, int> &pos);
	std::pair<int, int> defensiveMove(std::vector<std::vector<std::vector<std::shared_ptr<entities::Entity>>>> &map, std::pair<int, int> &posPlayer);
	std::pair<int, int> offensiveMove(std::vector<std::vector<std::vector<std::shared_ptr<entities::Entity>>>> &map, std::pair<int, int> &posPlayer);
	std::pair<int, int> findNearestSafePoint(std::vector<std::vector<std::vector<std::shared_ptr<entities::Entity>>>> &map, std::pair<int, int> &posPlayer);
	std::pair<int, int> locate_enemy(std::vector<std::vector<std::vector<std::shared_ptr<entities::Entity>>>> &map, std::pair<int, int> &posPlayer);
	std::pair<int, int> _posPlayer;
	int _nbr_of_moves;
	int _dir;
};

//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include "Algorithm.hpp"

static const t_choice dir[] = {{1, 0},
			       {-1, 0},
			       {0, 1},
			       {0, -1}};

std::pair<int, int> Algorithm::findNearestSafePoint(std::vector<std::string> &positionMap,
                                  std::vector<std::string> &dynamicMap,
						       std::pair<int, int> &posPlayer, std::pair<int, int> &current)
{
	if (dynamicMap[current.first][current.second] == 0)
		return (current);
	for (int i = 0; i < 4; i++) {
		if (dynamicMap[current.first + dir[i].first][current.second + dir[i].second] == 0 &&
		    positionMap[current.first + dir[i].first][current.second + dir[i].second] == 0) {
			current.first += dir[i].first;
			current.second += dir[i].second;
			return (current);
		}
	}
	for (int i = 0; i < 4; i++) {
		if (positionMap[current.first + dir[i].first][current.second + dir[i].second] == 0) {
			current.first += dir[i].first;
                        current.second += dir[i].second;
			return (findNearestSafePoint(positionMap, dynamicMap, posPlayer, current));
		}
	}
	return (current);
}

std::pair<int, int> Algorithm::defensiveMove(std::vector<std::string> &positionMap,
				  std::vector<std::string> &dynamicMap,
				  std::pair<int, int> &posPlayer)
{
	std::pair<int, int> safe_pos = findNearestSafePoint(positionMap, dynamicMap, posPlayer, posPlayer);
}

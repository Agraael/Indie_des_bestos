//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include <vector>
#include <iostream>
#include <utility>
#include <functional>
#include "Character.hpp"

class Ia : public Character {
public:
	Ia(std::vector<std::string> &map, std::vector<std::string> &dynamic_map);
	int checkIfDead(const std::vector<std::string> &map, std::pair<int, int> &pos);
private:
	int isInDangerousPosition(const std::vector<std::string> &dynamic_map, std::pair<int, int> &pos);
	void printMap(std::vector<std::string> &map);
	void placeIa(std::vector<std::string> &map);
};

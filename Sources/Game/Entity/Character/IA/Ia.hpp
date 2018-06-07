//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef IA_HPP_
#define IA_HPP_

#include <vector>
#include <iostream>
#include <utility>
#include <functional>
#include <memory>
#include "Gen.hpp"
#include "Map.hpp"
#include "Character.hpp"

/* class Ia : public Character {
public:
	Ia(std::vector<std::string> &map, std::vector<std::string> &dynamic_map);
	int checkIfDead(const std::vector<std::string> &map, std::pair<int, int> &pos);
private:
	int isInDangerousPosition(const std::vector<std::string> &dynamic_map, std::pair<int, int> &pos);
	void printMap(std::vector<std::string> &map);
	void placeIa(std::vector<std::string> &map);
}; */

class Ia : public Character {
public:
	Ia(entities::entityPosition pos, bool iskinematic, std::size_t layout);
	void turn();
	~Ia() { std::cout << "IA destroyed" << std::endl;}
};

#endif /* !ia */

/*
** EPITECH PROJECT, 2018
** indie
** File description:
** header
*/

#ifndef MAP_HPP_
	#define MAP_HPP_

#include "Gen.hpp"
#include "InterpreteGeneration.hpp"

class Map {
	public:
		Map();
		~Map();
		void 	InitMap(GameMap &map);
	private:
		GameMap	&_map;
};

#endif /* !MAP_HPP_ */

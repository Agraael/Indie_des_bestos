/*
** EPITECH PROJECT, 2018
** test
** File description:
** MAp
*/

#include <iostream>
#include "Map.hpp"

Map::Map(const vec_t &max)
 : _map(nullptr), _max(max)
{

}

Map::~Map()
{
	if (_map) {
		for (int i = 0; _map[i] != nullptr; i++)
			delete[] _map[i];
		delete[] _map;
	}
}

void	Map::placeCharLine(char *&line, const mapline_t &cs)
{
	for (std::size_t x = 0; x < _max.x; x++) {
		if (x == 0)
			line[x] = cs.leftCorner;
		else if (x == _max.x - 1)
			line[x] = cs.rightCorner;
		else
			line[x] = cs.mid;
	}
	line[_max.x] = '\0';
}

void	Map::printMap()
{
	for (int i = 0; _map[i] != nullptr; i++) {
		std::cout << _map[i] << std::endl;
	}
}


char	**&Map::createMap()
{
	_map = new char*[_max.y + 1];

	for (std::size_t y = 0; y < _max.y; y++) {
		_map[y] = new char[_max.x + 1];
		if (y == 0 || y == _max.y - 1)
			placeCharLine(_map[y], {WALL, WALL, WALL});
		else
			placeCharLine(_map[y], {WALL, PATH, WALL});
	}
	_map[_max.y] = nullptr;
	return (_map);
}

void	Map::clearMap()
{

}

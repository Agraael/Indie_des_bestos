/*
** EPITECH PROJECT, 2018
** test
** File description:
** procedal
*/

#include <iostream>
#include <time.h>
#include "Map.hpp"
#include "Procedural.hpp"

Procedural::Procedural()
{
	_engine.seed(time(NULL));
}

Procedural::~Procedural()
{
}

void	Procedural::placeUnDestWall1On2(char **&map)
{
	for (int y = 1; map[y] != nullptr; y++) {
		for (int x = 1; map[y][x] != WALL; x++) {
			if (y % 2 == 0 && x % 2 == 0)
				map[y][x] = WALL;
		}
	}
}

void	Procedural::placeDestWall(char **&map, std::size_t remp)
{
	for (int y = 1; map[y] != nullptr; y++) {
		for (int x = 1; map[y][x] != '\0'; x++) {
			if (map[y][x] == PATH && remp >= randomize())
				map[y][x] = 'X';
		}
	}
}

void	Procedural::placeBonus(char **&map, char bonus, std::size_t remp)
{
	for (int y = 1; map[y] != nullptr; y++) {
		for (int x = 1; map[y][x] != '\0'; x++) {
			if (map[y][x] == 'X' && remp >= randomize())
				map[y][x] = bonus;
		}
	}
}

void	Procedural::placeSpawnPointCorner(char **&map, char spawn, vec_t max)
{
	map[1][1] = spawn;
	map[1][2] = PATH;
	map[2][1] = PATH;

	map[1][max.x - 2] = spawn;
	map[1][max.x - 3] = PATH;
	map[2][max.x - 2] = PATH;

	map[max.y - 2][1] = spawn;
	map[max.y - 2][2] = PATH;
	map[max.y - 3][1] = PATH;

	map[max.y - 2][max.x - 2] = spawn;
	map[max.y - 2][max.x - 3] = PATH;
	map[max.y - 3][max.x - 2] = PATH;

}


int	Procedural::randomize()
{
	std::uniform_int_distribution<>	distrib;

	return distrib(_engine) % 101;
}

void	Procedural::placeBlock(char **&map, char block, vec_t max)
{
	vec_t	Prec = {1, 1};

	for (int y = 1; y < max.y - 1; y++) {
		for (int x = 1; x < max.x - 1; x++) {
			if (placeWall(map, {{static_cast<std::size_t>(x), static_cast<std::size_t>(y)}, Prec}, block) == true)
				map[y][x] = block;
			else
				map[y][x] = PATH;
		}
	}
}

bool	Procedural::placeWall(char **map, data_vec_t data, char block)
{
	int	wallNum = checkChar(map, data, block);

	if (map[data.pos.y][data.pos.x] == PATH && wallNum >= 5)
		return true;
	else if (wallNum >= 4)
		return true;
	return false;
}

int	Procedural::checkChar(char **map, data_vec_t data, char block)
{
	int	total = 0;
	vec_t	start = {data.pos.x - data.prec.x, data.pos.y - data.prec.y};
	vec_t	end = {data.pos.x + data.prec.x, data.pos.y + data.prec.y};

	for (int y = start.y; y < end.y + 1; y++) {
		for (int x = start.x; x < end.x + 1; x++) {
			if (map[y][x] == block)
				total++;
		}
	}
	return total;
}

/*
** EPITECH PROJECT, 2018
** test
** File description:
** procedal
*/

#include <iostream>
#include <time.h>
#include "Procedural.hpp"

Procedural::Procedural()
{
	_engine.seed(time(NULL));
}

Procedural::~Procedural()
{
}

//Place 1 undestructible wall every 2 char in the map
void	Procedural::placeUnDestWall1On2(char **&map)
{
	for (int y = 1; map[y] != nullptr; y++) {
		for (int x = 1; map[y][x] != INDESTRUCTIBLE; x++) {
			if (y % 2 == 0 && x % 2 == 0)
				map[y][x] = INDESTRUCTIBLE;
		}
	}
}

//Place destructible wall with random in the map
void	Procedural::placeDestWall(char **&map, std::size_t remp)
{
	for (int y = 1; map[y] != nullptr; y++) {
		for (int x = 1; map[y][x] != '\0'; x++) {
			if (map[y][x] == PASS && static_cast<int>(remp) >= randomize())
				map[y][x] = DESTRUCTIBLE;
		}
	}
}

//Place Bonuses in the destructible wall in the map
	void	Procedural::placeBonus(char **&map, char bonus, std::size_t remp)
	{
		for (int y = 1; map[y] != nullptr; y++) {
			for (int x = 1; map[y][x] != '\0'; x++) {
				if (map[y][x] == DESTRUCTIBLE && static_cast<int>(remp) >= randomize())
					map[y][x] = bonus;
			}
		}
	}

//Place 4 spawn points in the map
	void	Procedural::placeSpawnPointCorner(char **&map, char spawn, Vector_t max)
	{
		map[1][1] = spawn;
		map[1][2] = PASS;
		map[2][1] = PASS;

		map[1][max.x - 2] = spawn;
		map[1][max.x - 3] = PASS;
		map[2][max.x - 2] = PASS;

		map[max.y - 2][1] = spawn;
		map[max.y - 2][2] = PASS;
		map[max.y - 3][1] = PASS;

		map[max.y - 2][max.x - 2] = spawn;
		map[max.y - 2][max.x - 3] = PASS;
		map[max.y - 3][max.x - 2] = PASS;

	}

//Random
	int	Procedural::randomize()
	{
		std::uniform_int_distribution<>	distrib;

		return distrib(_engine) % 101;
	}

//Smooth the block in the map
	void	Procedural::placeBlock(char **&map, char block, Vector_t max)
	{
		Vector_t	Prec = {1, 1};

		for (std::size_t y = 1; y < max.y - 1; y++) {
			for (std::size_t x = 1; x < max.x - 1; x++) {
				if (placeWall(map, {{x, y}, Prec}, block) == true)
					map[y][x] = block;
				else
					map[y][x] = PASS;
			}
		}
	}

//Choose to place a wall or not in a certain place
	bool	Procedural::placeWall(char **map, data_vec_t data, char block)
	{
		int	wallNum = checkChar(map, data, block);

		if (map[data.pos.y][data.pos.x] == PASS && wallNum >= 5)
			return true;
		else if (wallNum >= 4)
			return true;
		return false;
	}

//Count same block arround a place
	int	Procedural::checkChar(char **map, data_vec_t data, char block)
	{
		int	total = 0;
		Vector_t	start = {data.pos.x - data.prec.x, data.pos.y - data.prec.y};
		Vector_t	end = {data.pos.x + data.prec.x, data.pos.y + data.prec.y};

		for (std::size_t y = start.y; y < end.y + 1; y++) {
			for (std::size_t x = start.x; x < end.x + 1; x++) {
				if (map[y][x] == block)
					total++;
			}
		}
		return total;
	}

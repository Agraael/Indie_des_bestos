/*
** EPITECH PROJECT, 2018
** Indie
** File description:
** Map Generator
*/

#include <exception>
#include <iostream>
#include "Procedural.hpp"
#include "MapGenerator.hpp"

MapGenerator::MapGenerator()
{
}

MapGenerator::~MapGenerator()
{
	if (_map) {
		for (int i = 0; _map[i] != nullptr; i++)
			delete[] _map[i];
		delete[] _map;
	}
}

void	MapGenerator::runGeneration(const GenerationSize &sizeType, const GenerationMod &modType)
{
	if (modType == GenerationMod::Standard)
		genStandardMap(_GenSizeTab.at(sizeType));
	else if (modType == GenerationMod::FullDest)
		genFullDestMap(_GenSizeTab.at(sizeType));
}

void	MapGenerator::setPlayers(const int &nb_player, const int &nb_ia)
{
	int	p = 0;
	int	ai = 0;

	if (!_map)
		throw std::exception();
	for (int y = 0; _map[y]; y++) {
		for (int x = 0; _map[y][x] != '\0'; x++) {
			if (_map[y][x] == SPAWNPOINT) {
				if (p < nb_player) {
					_map[y][x] = 'l';
					p++;
				} else if (ai < nb_ia) {
					_map[y][x] = 'C';
					ai++;
				} else
					_map[y][x] = PASS;
			}
		}
	}
}

void	MapGenerator::genStandardMap(const Vector_t &size)
{
	Procedural	proc;

	createMap(size);
	// place UD Wall //
	proc.placeUnDestWall1On2(_map);
	// place D Wall //
	proc.placeDestWall(_map, 95);
	// place Spawn Point //
	proc.placeSpawnPointCorner(_map, SPAWNPOINT, size);
	// bonus //
	proc.placeBonus(_map, BOMB_UP, 30);
	proc.placeBonus(_map, SPEED_UP, 20);
	proc.placeBonus(_map, FIRE_UP, 30);
	proc.placeBonus(_map, WALL_PASS, 20);
	// bonus //
}

void	MapGenerator::genFullDestMap(const Vector_t &size)
{
	Procedural	proc;

	createMap(size);
	proc.placeDestWall(_map, 50);
	for (int i = 0; i < 2; i++)
		proc.placeBlock(_map, DESTRUCTIBLE, size);
	proc.placeSpawnPointCorner(_map, SPAWNPOINT, size);
	proc.placeBonus(_map, BOMB_UP, 30);
	proc.placeBonus(_map, SPEED_UP, 20);
	proc.placeBonus(_map, FIRE_UP, 30);
	proc.placeBonus(_map, WALL_PASS, 20);
}

void	MapGenerator::createMap(const Vector_t &size)
{
	_map = new char*[size.y + 1];

	for (std::size_t y = 0; y < size.y; y++) {
		_map[y] = new char[size.x + 1]();
		if (y == 0 || y == size.y - 1)
			createMapLine(_map[y], {INDESTRUCTIBLE, INDESTRUCTIBLE, INDESTRUCTIBLE}, size.x);
		else
			createMapLine(_map[y], {INDESTRUCTIBLE, PASS, INDESTRUCTIBLE}, size.x);
	}
	_map[size.y] = nullptr;
}

void	MapGenerator::createMapLine(char *&line, const mapline_t &cs, std::size_t maxx)
{
	for (std::size_t x = 0; x < maxx; x++) {
		if (x == 0)
			line[x] = cs.leftCorner;
		else if (x == maxx - 1)
			line[x] = cs.rightCorner;
		else
			line[x] = cs.mid;
	}
	line[maxx] = '\0';
}
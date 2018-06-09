/*
** EPITECH PROJECT, 2018
** indie
** File description:
** source
*/

#include "InterpreteGeneration.hpp"
#include <algorithm>

void	InterpreteGeneration::InitIndestructible(SharedEntity &tempTab, std::size_t x, std::size_t y)
{
	tempTab.push_back(std::make_shared<IndestructibleWalls>(std::make_pair(x,y), true, 0));
}

void	InterpreteGeneration::InitDestructible(SharedEntity &tempTab, std::size_t x, std::size_t y)
{
	tempTab.push_back(std::make_shared<DestructibleWalls>(std::make_pair(x,y), true, 0, nullptr, BonusSpace::BonusesTypes::NO_BONUS));
}

void	InterpreteGeneration::InitBombUp(SharedEntity &tempTab, std::size_t x, std::size_t y)
{
	std::shared_ptr<entities::Entity>		bonus;

	bonus = std::make_shared<BombUp>(std::make_pair(x,y), true, 1);
	tempTab.push_back(std::make_shared<DestructibleWalls>(std::make_pair(x,y), false, 0, bonus, BonusSpace::BonusesTypes::BOMBUP));
	tempTab.push_back(bonus);
}

void	InterpreteGeneration::InitSpeedUp(SharedEntity &tempTab, std::size_t x, std::size_t y)
{
	std::shared_ptr<entities::Entity>		bonus;

	bonus = std::make_shared<SpeedUp>(std::make_pair(x,y), true, 1);
	tempTab.push_back(std::make_shared<DestructibleWalls>(std::make_pair(x,y), false, 0, bonus, BonusSpace::BonusesTypes::SPEEDUP));
	tempTab.push_back(bonus);
}

void	InterpreteGeneration::InitFireUp(SharedEntity &tempTab, std::size_t x, std::size_t y)
{
	std::shared_ptr<entities::Entity>		bonus;

	bonus = std::make_shared<FireUp>(std::make_pair(x,y), true, 1);
	tempTab.push_back(std::make_shared<DestructibleWalls>(std::make_pair(x,y), false, 0, bonus, BonusSpace::BonusesTypes::FIREUP));
	tempTab.push_back(bonus);
}

void	InterpreteGeneration::InitWallPass(SharedEntity &tempTab, std::size_t x, std::size_t y)
{
	std::shared_ptr<entities::Entity>		bonus;

	bonus = std::make_shared<WallPass>(std::make_pair(x,y), true, 1);
	tempTab.push_back(std::make_shared<DestructibleWalls>(std::make_pair(x,y), false, 0, bonus, BonusSpace::BonusesTypes::WALLPASS));
	tempTab.push_back(bonus);
}

void	InterpreteGeneration::InitIa(SharedEntity &tempTab, std::size_t x, std::size_t y)
{
	static	std::size_t	index = 1;

	tempTab.push_back(std::make_shared<Ia>(std::make_pair(x,y), false, 0, "IA" + std::to_string(index)));
	++index;
}

void	InterpreteGeneration::InitPlayer(SharedEntity &tempTab, std::size_t x, std::size_t y)
{
	static	std::size_t	index = 1;

	tempTab.push_back(std::make_shared<Player>(std::make_pair(x,y), false, 0, _eventPlayer[index], "PLAYER" + std::to_string(index)));
	++index;
}

void	InterpreteGeneration::InitSoloBombUp(SharedEntity &tempTab, std::size_t x, std::size_t y)
{
	tempTab.push_back(std::make_shared<BombUp>(std::make_pair(x,y), true, 1));
}

void	InterpreteGeneration::InitSoloSpeedUp(SharedEntity &tempTab, std::size_t x, std::size_t y)
{
	tempTab.push_back(std::make_shared<SpeedUp>(std::make_pair(x,y), false, 0));
}

void	InterpreteGeneration::InitSoloFireUp(SharedEntity &tempTab, std::size_t x, std::size_t y)
{
	tempTab.push_back(std::make_shared<FireUp>(std::make_pair(x,y), false, 0));
}

void	InterpreteGeneration::InitSoloWallPass(SharedEntity &tempTab, std::size_t x, std::size_t y)
{
	tempTab.push_back(std::make_shared<WallPass>(std::make_pair(x,y), false, 0));
}

std::size_t	InterpreteGeneration::findHeight(char **map)
{
	std::size_t	height = 0;

	for (; map[height]; ++height);
	return (height);
}

std::size_t	InterpreteGeneration::findWidth(char **map)
{
	std::size_t	width = 0;

	for (std::size_t i = 0; map[i]; ++i) {
		for (; map[i][width]; ++width);
		return (width);
	}
	return (0);
}

void	InterpreteGeneration::createMap(GameMap &threedmap, char **map)
{
	Fill(threedmap, findWidth(map), findHeight(map), map);
}

void	InterpreteGeneration::Fill(GameMap &map, const std::size_t &width, const std::size_t &height, char **charMap)
{
	for (std::size_t i = 0; i < height; ++i) {
		for (std::size_t n = 0; n < width; ++n) {
			std::cout << charMap[i][n];
			auto func = _initFuncsPtr[static_cast<InterpreteGeneration::entityType>(charMap[i][n])];
			if (charMap[i][n] != ' ') {
				func(_tempTab, i, n);
				_tempLine.push_back(_tempTab);
				_tempTab.clear();
			}
			else
				_tempLine.push_back({});
		}
		std::cout << std::endl;
		map.push_back(_tempLine);
		if (!(_tempLine.empty()))
			_tempLine.clear();
	}
}
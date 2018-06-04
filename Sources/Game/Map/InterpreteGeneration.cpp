/*
** EPITECH PROJECT, 2018
** indie
** File description:
** source
*/

#include "InterpreteGeneration.hpp"
#include <algorithm>

SharedEntity	InterpreteGeneration::InitIndestructible(std::size_t x, std::size_t y)
{
	SharedEntity	tempLine;

	tempLine.push_back(std::make_shared<entities::Entity>(IndestructibleWalls(std::make_pair(x,y), false, 0)));
	return tempLine;
}

SharedEntity	InterpreteGeneration::InitDestructible(std::size_t x, std::size_t y)
{
	SharedEntity	tempLine;

	tempLine.push_back(std::make_shared<entities::Entity>(DestructibleWalls(
	std::make_pair(x,y), false, 0, nullptr, BonusSpace::BonusesTypes::NO_BONUS)));
	return tempLine;
}

SharedEntity	InterpreteGeneration::InitBombUp(std::size_t x, std::size_t y)
{
	SharedEntity	tempLine;
	std::shared_ptr<BonusSpace::Bonus>		bonus;

	bonus = std::make_shared<BonusSpace::Bonus>(BombUp(std::make_pair(x,y), true, 1));
	tempLine.push_back(std::make_shared<entities::Entity>(DestructibleWalls(
		std::make_pair(x,y), false, 0, bonus, BonusSpace::BonusesTypes::BOMBUP)));
	tempLine.push_back(bonus);
	return tempLine;
}

SharedEntity	InterpreteGeneration::InitSpeedUp(std::size_t x, std::size_t y)
{
	SharedEntity	tempLine;
	std::shared_ptr<BonusSpace::Bonus>		bonus;

	bonus = std::make_shared<BonusSpace::Bonus>(SpeedUp(std::make_pair(x,y), true, 1));
	tempLine.push_back(std::make_shared<entities::Entity>(DestructibleWalls(
		std::make_pair(x,y), false, 0, bonus, BonusSpace::BonusesTypes::SPEEDUP)));
	tempLine.push_back(bonus);
	return tempLine;
}

SharedEntity	InterpreteGeneration::InitFireUp(std::size_t x, std::size_t y)
{
	SharedEntity	tempLine;
	std::shared_ptr<BonusSpace::Bonus>		bonus;

	bonus = std::make_shared<BonusSpace::Bonus>(FireUp(std::make_pair(x,y), true, 1));
	tempLine.push_back(std::make_shared<entities::Entity>(DestructibleWalls(
		std::make_pair(x,y), false, 0, bonus, BonusSpace::BonusesTypes::FIREUP)));
	tempLine.push_back(bonus);
	return tempLine;
}

SharedEntity	InterpreteGeneration::InitWallPass(std::size_t x, std::size_t y)
{
	SharedEntity	tempLine;
	std::shared_ptr<BonusSpace::Bonus>		bonus;

	bonus = std::make_shared<BonusSpace::Bonus>(WallPass(std::make_pair(x,y), true, 1));
	tempLine.push_back(std::make_shared<entities::Entity>(DestructibleWalls(
		std::make_pair(x,y), false, 0, bonus, BonusSpace::BonusesTypes::WALLPASS)));
	tempLine.push_back(bonus);
	return tempLine;
}

SharedEntity	InterpreteGeneration::InitCharacter(std::size_t x, std::size_t y)
{
	SharedEntity	tempLine;

	tempLine.push_back(std::make_shared<entities::Entity>(Player(std::make_pair(x,y), false, 0)));
	return tempLine;
}

SharedEntity	InterpreteGeneration::InitSoloBombUp(std::size_t x, std::size_t y)
{
	SharedEntity	tempLine;

	tempLine.push_back(std::make_shared<entities::Entity>(BombUp(std::make_pair(x,y), true, 1)));
	return tempLine;
}

SharedEntity	InterpreteGeneration::InitSoloSpeedUp(std::size_t x, std::size_t y)
{
	SharedEntity	tempLine;

	tempLine.push_back(std::make_shared<entities::Entity>(SpeedUp(std::make_pair(x,y), false, 0)));
	return tempLine;
}

SharedEntity	InterpreteGeneration::InitSoloFireUp(std::size_t x, std::size_t y)
{
	SharedEntity	tempLine;

	tempLine.push_back(std::make_shared<entities::Entity>(FireUp(std::make_pair(x,y), false, 0)));
	return tempLine;
}

SharedEntity	InterpreteGeneration::InitSoloWallPass(std::size_t x, std::size_t y)
{
	SharedEntity	tempLine;

	tempLine.push_back(std::make_shared<entities::Entity>(WallPass(std::make_pair(x,y), false, 0)));
	return tempLine;
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

GameMap	InterpreteGeneration::createMap(char **map)
{
	return (Fill(findWidth(map), findHeight(map), map));
}

GameMap	InterpreteGeneration::Fill(const std::size_t &width, const std::size_t &height, char **charMap)
{
	std::vector<std::vector<std::shared_ptr<entities::Entity>>>	tempLine;
	GameMap							map;

	for (std::size_t i = 0; i < height; ++i) {
		for (std::size_t n = 0; n < width; ++n) {
			auto func = _initFuncsPtr[static_cast<InterpreteGeneration::entityType>(charMap[i][n])];
			if (charMap[i][n] != ' ')
				tempLine.push_back(func(i, n));
			else
				tempLine.push_back({});
		}
		map.push_back(tempLine);
		if (!(tempLine.empty()))
			tempLine.clear();
	}
	return map;
}
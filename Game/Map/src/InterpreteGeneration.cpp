/*
** EPITECH PROJECT, 2018
** indie
** File description:
** source
*/

#include "InterpreteGeneration.hpp"
#include <algorithm>

std::vector<std::shared_ptr<entities::Entity>>	InterpreteGeneration::InitIndestructible(std::size_t x, std::size_t y)
{
	std::vector<std::shared_ptr<entities::Entity>>	tempLine;

	tempLine.push_back(std::make_shared<entities::Entity>(IndestructibleWalls(
		std::make_pair(x,y), false, 0, nullptr, BonusSpace::BonusesTypes::NO_BONUS)));
	return tempLine;
}

std::vector<std::shared_ptr<entities::Entity>>	InterpreteGeneration::InitDestructible(std::size_t x, std::size_t y)
{
	std::vector<std::shared_ptr<entities::Entity>>	tempLine;

	tempLine.push_back(std::make_shared<entities::Entity>(DestructibleWalls(std::make_pair(x,y), false, 0)));
	return tempLine;
}

std::vector<std::shared_ptr<entities::Entity>>	InterpreteGeneration::InitBombUp(std::size_t x, std::size_t y)
{
	std::vector<std::shared_ptr<entities::Entity>>	tempLine;
	std::shared_ptr<BonusSpace::Bonus>		bonus;

	bonus = std::make_shared<BonusSpace::Bonus>(BombUp(std::make_pair(x,y), true, 1));
	tempLine.push_back(std::make_shared<entities::Entity>(IndestructibleWalls(
		std::make_pair(x,y), false, 0, bonus, BonusSpace::BonusesTypes::BOMBUP)));
	tempLine.push_back(std::move(bonus));
	return tempLine;
}

std::vector<std::shared_ptr<entities::Entity>>	InterpreteGeneration::InitSpeedUp(std::size_t x, std::size_t y)
{
	std::vector<std::shared_ptr<entities::Entity>>	tempLine;
	std::shared_ptr<BonusSpace::Bonus>		bonus;

	bonus = std::make_shared<BonusSpace::Bonus>(SpeedUp(std::make_pair(x,y), true, 1));
	tempLine.push_back(std::make_shared<entities::Entity>(IndestructibleWalls(
		std::make_pair(x,y), false, 0, bonus, BonusSpace::BonusesTypes::SPEEDUP)));
	tempLine.push_back(std::move(bonus));
	return tempLine;
}

std::vector<std::shared_ptr<entities::Entity>>	InterpreteGeneration::InitFireUp(std::size_t x, std::size_t y)
{
	std::vector<std::shared_ptr<entities::Entity>>	tempLine;
	std::shared_ptr<BonusSpace::Bonus>		bonus;

	bonus = std::make_shared<BonusSpace::Bonus>(FireUp(std::make_pair(x,y), true, 1));
	tempLine.push_back(std::make_shared<entities::Entity>(IndestructibleWalls(
		std::make_pair(x,y), false, 0, bonus, BonusSpace::BonusesTypes::FIREUP)));
	tempLine.push_back(std::move(bonus));
	return tempLine;
}

std::vector<std::shared_ptr<entities::Entity>>	InterpreteGeneration::InitWallPass(std::size_t x, std::size_t y)
{
	std::vector<std::shared_ptr<entities::Entity>>	tempLine;
	std::shared_ptr<BonusSpace::Bonus>		bonus;

	bonus = std::make_shared<BonusSpace::Bonus>(WallPass(std::make_pair(x,y), true, 1));
	tempLine.push_back(std::make_shared<entities::Entity>(IndestructibleWalls(
		std::make_pair(x,y), false, 0, bonus, BonusSpace::BonusesTypes::WALLPASS)));
	tempLine.push_back(std::move(bonus));
	return tempLine;
}

std::vector<std::shared_ptr<entities::Entity>>	InterpreteGeneration::InitCharacter(std::size_t x, std::size_t y)
{
	std::vector<std::shared_ptr<entities::Entity>>	tempLine;

	tempLine.push_back(std::make_shared<entities::Entity>(Player(std::make_pair(x,y), false, 0)));
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
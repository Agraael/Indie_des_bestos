/*
** EPITECH PROJECT, 2018
** indie
** File description:
** header
*/

#ifndef INTERPRETEGENERATION_HPP_
	#define INTERPRETEGENERATION_HPP_

#include <functional>
#include <vector>
#include <iostream>
#include <memory>
#include <map>
#include "Gen.hpp"
#include "../../Entity/Walls/src/DestructibleWalls.hpp"
#include "../../Entity/Walls/src/IndestructibleWalls.hpp"
#include "../../Entity/Bonuses/src/FireUp.hpp"
#include "../../Entity/Bonuses/src/SpeedUp.hpp"
#include "../../Entity/Bonuses/src/WallPass.hpp"
#include "../../Entity/Bonuses/src/BombUp.hpp"
#include "../../Entity/Character/Player/src/Player.hpp"
#include "../../Entity/Character/IA/src/Ia.hpp"
#include "Map.hpp"

class Entity;

class InterpreteGeneration {
	public:
		InterpreteGeneration() {}
		GameMap	createMap(char **);
	private:		
		enum entityType {
			NOTHING = ' ',
			INDESTRUCTIBLE_TYPE = 'I',
			DESTRUCTIBLE_TYPE = 'D',
			BOMB_TYPE = 'B',
			SPEED_TYPE = 'S',
			FIRE_UP_TYPE = 'F',
			WALL_PASS_TYPE = 'P',
			CHARACTER_TYPE = 'C',
		};
		GameMap		Fill(const std::size_t &, const std::size_t &, char **);
		std::size_t	findHeight(char **);
		std::size_t	findWidth(char **);
		SharedEntity	InitIndestructible(std::size_t, std::size_t);
		SharedEntity	InitDestructible(std::size_t, std::size_t);
		SharedEntity	InitBombUp(std::size_t, std::size_t);
		SharedEntity	InitSpeedUp(std::size_t, std::size_t);
		SharedEntity	InitFireUp(std::size_t, std::size_t);
		SharedEntity	InitWallPass(std::size_t, std::size_t);
		SharedEntity	InitCharacter(std::size_t, std::size_t);
		

		using	EntitiesInitialization = std::function<SharedEntity(std::size_t, std::size_t)>;
		using	ptrMapFunc = std::map<entityType, EntitiesInitialization>;
		ptrMapFunc _initFuncsPtr {
			{InterpreteGeneration::entityType::INDESTRUCTIBLE_TYPE, [this](std::size_t x, std::size_t y) { return this->InitIndestructible(x, y); }},
			{InterpreteGeneration::entityType::DESTRUCTIBLE_TYPE, 	[this](std::size_t x, std::size_t y) { return this->InitDestructible(x, y); }},
			{InterpreteGeneration::entityType::BOMB_TYPE, 		[this](std::size_t x, std::size_t y) { return this->InitBombUp(x, y); }},
			{InterpreteGeneration::entityType::SPEED_TYPE, 		[this](std::size_t x, std::size_t y) { return this->InitSpeedUp(x, y); }},
			{InterpreteGeneration::entityType::FIRE_UP_TYPE, 	[this](std::size_t x, std::size_t y) { return this->InitFireUp(x, y); }},
			{InterpreteGeneration::entityType::WALL_PASS_TYPE, 	[this](std::size_t x, std::size_t y) { return this->InitWallPass(x, y); }},
			{InterpreteGeneration::entityType::CHARACTER_TYPE, 	[this](std::size_t x, std::size_t y) { return this->InitCharacter(x, y); }}
		};
};

#endif /* !INTERPRETEGENERATION_HPP_ */
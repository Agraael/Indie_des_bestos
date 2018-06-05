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
#include <unordered_map>
#include "Gen.hpp"
#include "DestructibleWalls.hpp"
#include "IndestructibleWalls.hpp"
#include "FireUp.hpp"
#include "SpeedUp.hpp"
#include "WallPass.hpp"
#include "BombUp.hpp"
#include "Player.hpp"
#include "Ia.hpp"
#include "Map.hpp"
#include "IrrlichtLib.hpp"
#include "LibEventManager.hpp"

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
		SOLO_BOMB_TYPE = 'b',
		SPEED_TYPE = 'S',
		FIRE_UP_TYPE = 'F',
		SOLO_SPEED_TYPE = 's',
		SOLO_FIRE_UP_TYPE = 'f',
		WALL_PASS_TYPE = 'P',
		SOLO_WALL_PASS_TYPE = 'p',
		PLAYER_TYPE = 'C',
		IA_TYPE = 'C',
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
	SharedEntity	InitPlayer(std::size_t, std::size_t);
	SharedEntity	InitIa(std::size_t, std::size_t);
	SharedEntity	InitSoloSpeedUp(std::size_t, std::size_t);
	SharedEntity	InitSoloFireUp(std::size_t, std::size_t);
	SharedEntity	InitSoloWallPass(std::size_t, std::size_t);
	SharedEntity	InitSoloBombUp(std::size_t, std::size_t);

	std::unordered_map<std::size_t, std::vector<graphic::controllerUser>>	_eventPlayer = {
		{1, {graphic::controllerUser::ARROW_DOWN, graphic::controllerUser::ARROW_UP, graphic::controllerUser::ARROW_LEFT, graphic::controllerUser::ARROW_RIGHT, graphic::controllerUser::ENTER}},
		{2, {graphic::controllerUser::KEY_Z, graphic::controllerUser::KEY_Q, graphic::controllerUser::KEY_S, graphic::controllerUser::KEY_D, graphic::controllerUser::SPACEBAR}},
		{3, {graphic::controllerUser::KEY_Z, graphic::controllerUser::KEY_Q, graphic::controllerUser::KEY_S, graphic::controllerUser::KEY_D, graphic::controllerUser::SPACEBAR}},
		{4, {graphic::controllerUser::KEY_Z, graphic::controllerUser::KEY_Q, graphic::controllerUser::KEY_S, graphic::controllerUser::KEY_D, graphic::controllerUser::SPACEBAR}}
	};
	using	EntitiesInitialization = std::function<SharedEntity(std::size_t, std::size_t)>;
	using	ptrMapFunc = std::unordered_map<entityType, EntitiesInitialization>;
	ptrMapFunc _initFuncsPtr {
		{InterpreteGeneration::entityType::INDESTRUCTIBLE_TYPE, [this](std::size_t x, std::size_t y) { return this->InitIndestructible(x, y); }},
		{InterpreteGeneration::entityType::DESTRUCTIBLE_TYPE, 	[this](std::size_t x, std::size_t y) { return this->InitDestructible(x, y); }},
		{InterpreteGeneration::entityType::BOMB_TYPE, 		[this](std::size_t x, std::size_t y) { return this->InitBombUp(x, y); }},
		{InterpreteGeneration::entityType::SPEED_TYPE, 		[this](std::size_t x, std::size_t y) { return this->InitSpeedUp(x, y); }},
		{InterpreteGeneration::entityType::FIRE_UP_TYPE, 	[this](std::size_t x, std::size_t y) { return this->InitFireUp(x, y); }},
		{InterpreteGeneration::entityType::WALL_PASS_TYPE, 	[this](std::size_t x, std::size_t y) { return this->InitWallPass(x, y); }},
		{InterpreteGeneration::entityType::PLAYER_TYPE, 	[this](std::size_t x, std::size_t y) { return this->InitPlayer(x, y); }},
		{InterpreteGeneration::entityType::IA_TYPE,	 	[this](std::size_t x, std::size_t y) { return this->InitIa(x, y); }},
		{InterpreteGeneration::entityType::SOLO_BOMB_TYPE, 	[this](std::size_t x, std::size_t y) { return this->InitSoloBombUp(x, y); }},
		{InterpreteGeneration::entityType::SOLO_SPEED_TYPE,	[this](std::size_t x, std::size_t y) { return this->InitSoloSpeedUp(x, y); }},
		{InterpreteGeneration::entityType::SOLO_FIRE_UP_TYPE, 	[this](std::size_t x, std::size_t y) { return this->InitSoloFireUp(x, y); }},
		{InterpreteGeneration::entityType::SOLO_WALL_PASS_TYPE, [this](std::size_t x, std::size_t y) { return this->InitSoloWallPass(x, y); }}
	};
};

#endif /* !INTERPRETEGENERATION_HPP_ */

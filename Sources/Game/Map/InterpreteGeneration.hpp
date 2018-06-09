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
	void	createMap(GameMap &, char **);
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
		PLAYER_TYPE = 'l',
		IA_TYPE = 'C',
	};
	std::size_t	findHeight(char **);
	std::size_t	findWidth(char **);
	void		Fill(GameMap &, const std::size_t &, const std::size_t &, char **);
	void		InitIndestructible(SharedEntity &, std::size_t, std::size_t);
	void		InitDestructible(SharedEntity &, std::size_t, std::size_t);
	void		InitBombUp(SharedEntity &, std::size_t, std::size_t);
	void		InitSpeedUp(SharedEntity &, std::size_t, std::size_t);
	void		InitFireUp(SharedEntity &, std::size_t, std::size_t);
	void		InitWallPass(SharedEntity &, std::size_t, std::size_t);
	void		InitPlayer(SharedEntity &, std::size_t, std::size_t);
	void		InitIa(SharedEntity &, std::size_t, std::size_t);
	void		InitSoloSpeedUp(SharedEntity &, std::size_t, std::size_t);
	void		InitSoloFireUp(SharedEntity &, std::size_t, std::size_t);
	void		InitSoloWallPass(SharedEntity &, std::size_t, std::size_t);
	void		InitSoloBombUp(SharedEntity &, std::size_t, std::size_t);

	EntitiesVec	_tempLine;
	SharedEntity	_tempTab;	
	std::unordered_map<std::size_t, std::vector<irr::EKEY_CODE>>	_eventPlayer = {
		{1, {irr::KEY_KEY_Z, irr::KEY_KEY_Q, irr::KEY_KEY_S, irr::KEY_KEY_D, irr::KEY_SPACE}},
		{2, {irr::KEY_UP, irr::KEY_LEFT, irr::KEY_DOWN, irr::KEY_RIGHT, irr::KEY_RETURN}},
	};
	using	EntitiesInitialization = std::function<void(SharedEntity &, std::size_t, std::size_t)>;
	using	ptrMapFunc = std::unordered_map<entityType, EntitiesInitialization>;
	ptrMapFunc _initFuncsPtr {
		{InterpreteGeneration::entityType::INDESTRUCTIBLE_TYPE, [this](SharedEntity &templine, std::size_t x, std::size_t y) { return this->InitIndestructible(templine, x, y); }},
		{InterpreteGeneration::entityType::DESTRUCTIBLE_TYPE, 	[this](SharedEntity &templine, std::size_t x, std::size_t y) { return this->InitDestructible(templine, x, y); }},
		{InterpreteGeneration::entityType::BOMB_TYPE, 		[this](SharedEntity &templine, std::size_t x, std::size_t y) { return this->InitBombUp(templine, x, y); }},
		{InterpreteGeneration::entityType::SPEED_TYPE, 		[this](SharedEntity &templine, std::size_t x, std::size_t y) { return this->InitSpeedUp(templine, x, y); }},
		{InterpreteGeneration::entityType::FIRE_UP_TYPE, 	[this](SharedEntity &templine, std::size_t x, std::size_t y) { return this->InitFireUp(templine, x, y); }},
		{InterpreteGeneration::entityType::WALL_PASS_TYPE, 	[this](SharedEntity &templine, std::size_t x, std::size_t y) { return this->InitWallPass(templine, x, y); }},
		{InterpreteGeneration::entityType::PLAYER_TYPE, 	[this](SharedEntity &templine, std::size_t x, std::size_t y) { return this->InitPlayer(templine, x, y); }},
		{InterpreteGeneration::entityType::IA_TYPE,	 	[this](SharedEntity &templine, std::size_t x, std::size_t y) { return this->InitIa(templine, x, y); }},
		{InterpreteGeneration::entityType::SOLO_BOMB_TYPE, 	[this](SharedEntity &templine, std::size_t x, std::size_t y) { return this->InitSoloBombUp(templine, x, y); }},
		{InterpreteGeneration::entityType::SOLO_SPEED_TYPE,	[this](SharedEntity &templine, std::size_t x, std::size_t y) { return this->InitSoloSpeedUp(templine, x, y); }},
		{InterpreteGeneration::entityType::SOLO_FIRE_UP_TYPE, 	[this](SharedEntity &templine, std::size_t x, std::size_t y) { return this->InitSoloFireUp(templine, x, y); }},
		{InterpreteGeneration::entityType::SOLO_WALL_PASS_TYPE, [this](SharedEntity &templine, std::size_t x, std::size_t y) { return this->InitSoloWallPass(templine, x, y); }}
	};
};

#endif /* !INTERPRETEGENERATION_HPP_ */

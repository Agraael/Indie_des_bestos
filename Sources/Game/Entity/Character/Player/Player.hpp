/*
** EPITECH PROJECT, 2018
** indie
** File description:
** header
*/

#ifndef PLAYER_HPP_
	#define PLAYER_HPP_

#include "Character.hpp"
#include "IrrlichtLib.hpp"
#include "MoveTo.hpp"
#include "Gen.hpp"
#include "Map.hpp"

class Player : public Character {
public:
	Player(entities::entityPosition pos, bool iskinematic, std::size_t layout, std::vector<irr::EKEY_CODE> eventPlayer, std::string name) :
	Character(pos, iskinematic, layout, entities::entityType::PLAYER_TYPE, name), _eventPlayer(eventPlayer) { _move = std::make_unique<MoveTo>(); }
	void	setLibEventManager(graphic::IrrlichtLib *lib) { _lib = lib; }
	void	update();
	~Player() final {};

private:
	graphic::IrrlichtLib									*_lib;
	std::vector<irr::EKEY_CODE>								_eventPlayer;
	std::unique_ptr<MoveTo>									_move;
	std::vector<std::function<std::pair<int, int> (GameMap &, entities::entityPosition)>>	_foncter = {
		[this](GameMap &map, entities::entityPosition pos) { return _move->try_move_up(map, pos); },
		[this](GameMap &map, entities::entityPosition pos) { return _move->try_move_left(map, pos); },
		[this](GameMap &map, entities::entityPosition pos) { return _move->try_move_down(map, pos); },
		[this](GameMap &map, entities::entityPosition pos) { return _move->try_move_right(map, pos); }
	};
};

#endif /* !PLAYER_HPP_ */

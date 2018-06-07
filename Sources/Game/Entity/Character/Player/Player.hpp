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

class Player : public Character {
public:
	Player(entities::entityPosition pos, bool iskinematic, std::size_t layout, std::vector<graphic::controllerUser> eventPlayer, std::string name) :
	Character(pos, iskinematic, layout, entities::entityType::PLAYER_TYPE, name), _eventPlayer(eventPlayer) {}
	void					setLibEventManager(graphic::IrrlichtLib *lib) { _lib = lib; }
	void					interpretEvent();
	~Player() {};
private:
	graphic::IrrlichtLib			*_lib;
	std::vector<graphic::controllerUser>	_eventPlayer;
};

#endif /* !PLAYER_HPP_ */

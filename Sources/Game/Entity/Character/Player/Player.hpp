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
	Player(entities::entityPosition pos, bool iskinematic, std::size_t layout) :
	Character(pos, iskinematic, layout, entities::entityType::PLAYER_TYPE) {}
	void	setLibEventManager(graphic::IrrlichtLib *lib) { _lib = lib; }
	void	interpretEvent();
	~Player() {};
private:
	std::unordered_map<int, std::vector<controllerUser>>
	graphic::IrrlichtLib	*_lib;
};

#endif /* !PLAYER_HPP_ */

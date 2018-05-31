/*
** EPITECH PROJECT, 2018
** indie
** File description:
** header
*/

#ifndef PLAYER_HPP_
	#define PLAYER_HPP_

#include "Character.hpp"

class Player : public Character {
public:
	Player(entities::entityPosition pos, bool iskinematic, std::size_t layout) :
		Character(pos, iskinematic, layout, "p") {}
	~Player() {};
private:
	
};

#endif /* !PLAYER_HPP_ */

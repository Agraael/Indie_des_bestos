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
<<<<<<< HEAD:Game/Entity/Character/Player/src/Player.hpp
	Character(pos, iskinematic, layout, entities::entityType::PLAYER) {}
=======
		Character(pos, iskinematic, layout, "p") {}
>>>>>>> 5e27efff015b9c8f505c3e916a707c0ba3b45a42:Sources/Game/Entity/Character/Player/Player.hpp
	~Player() {};
private:
	
};

#endif /* !PLAYER_HPP_ */

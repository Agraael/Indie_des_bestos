/*
** EPITECH PROJECT, 2018
** indie
** File description:
** header
*/

#ifndef ENTITY_HPP_
	#define ENTITY_HPP_

#include <iostream>
#include <utility>
#include <functional>

class Entity {
	public:
		Entity();
		~Entity();
		std::pair<int, int>	getPos() { return _pos; }
		bool			getIsKinematic() { return _iskinematic; }
		bool			getIsRegidBody() { return _isregidBody; }
		bool			getDeath() { return _isDead; }
		void			die(bool die) { _isDead = true; }
	protected:
		std::pair<int, int>     _pos;
		bool			_iskinematic;
		bool			_isregidBody;
		bool			_isDead;
		int			_layout;
		// textures
};

#endif /* !ENTITY_HPP_ */

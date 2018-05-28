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
#include <memory>
//#include "../Map/src/Map.hpp"

namespace entities {

	using entityPosition = std::pair<float, float>;

	class Entity {
		public:
			Entity(entityPosition pos, bool iskinematic, std::size_t layout) : _pos(pos), _iskinematic(iskinematic), _layout(layout) {}
			std::pair<int, int>					getPos() const noexcept { return _pos; }
			bool							getIsKinematic() const noexcept { return _iskinematic; }
			bool							getDeath() const noexcept { return _isDead; }
			void							die(bool die) { _isDead = true; }
			void							displayType() {std::cout << _type << std::endl;};
		protected:
//			std::unique_ptr<Map>	_map;
			std::string		_type;
			entityPosition		_pos;
			bool			_iskinematic;
			bool			_isDead;
			std::size_t		_layout;
			//bool			_isregidBody;
			// textures
			//bool			getIsRegidBody() { return _isregidBody; }
	};
}
#endif /* !ENTITY_HPP_ */

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

class Map;

namespace entities {
	using graphicEntityPosition = std::pair<float, float>;
	using entityPosition = std::pair<int, int>;
	class Entity {
	public:
		Entity(entityPosition pos, bool iskinematic, std::size_t layout, std::string type) : /* _id(0), */ _type(type), _pos(pos), _iskinematic(iskinematic), _layout(layout)
		{ 
		}
		entityPosition		getPos() const noexcept { return _pos; }
		bool			isDead() const noexcept { return _isDead; }
		bool			IsKinematic() const noexcept { return _iskinematic; }
		graphicEntityPosition	getGraphcPos() const noexcept { return _graphicPos; }
		std::string		getTextrue() const noexcept { return _texture; };
		//std::size_t		getId() const noexcept { return entities::Entity::_id; };
		void			displayType() const noexcept {std::cout << _type;};
		void			die(bool state) { _isDead = state; }
		void			setMap(std::shared_ptr<Map> &map) {_map = map; };
		void			setTexture(std::string texture) { _texture = texture; }
	protected:
	//	static std::size_t	_nb;
	//	const std::size_t	_id;
		std::string		_texture;
		std::shared_ptr<Map>	_map;
		std::string		_type;
		entityPosition		_pos;
		graphicEntityPosition	_graphicPos;
		bool			_iskinematic;
		bool			_isDead;
		std::size_t		_layout;
		//bool			_isregidBody;
		//bool			getIsRegidBody() { return _isregidBody; }
	};
//	std::size_t entities::Entity::_nb = 0;
}
#endif /* !ENTITY_HPP_ */
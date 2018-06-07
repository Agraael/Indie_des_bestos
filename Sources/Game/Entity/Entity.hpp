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

	enum entityType {
		INDESTRUCTIBLE_TYPE,
		DESTRUCTIBLE_TYPE,
		BOMB_UP_TYPE,
		SPEED_UP_TYPE,
		FIRE_UP_TYPE,
		WALL_PASS_TYPE,
		PLAYER_TYPE,
		IA_TYPE,
		BOMBS_TYPE,
		GONNAEXPLOSE_TYPE
	};

	class Entity {
	public:
		Entity(entityPosition pos, bool iskinematic, std::size_t layout, entities::entityType type, std::string name) : _pos(pos), _iskinematic(iskinematic), _layout(layout), _typeEnum(type), _name(name) { _graphicPos = std::make_pair(static_cast<float>(pos.first), static_cast<float>(pos.second)); }
		entityPosition		getPos() const noexcept { return _pos; }
		bool			isDead() const noexcept { return _isDead; }
		bool			IsKinematic() const noexcept { return _iskinematic; }
		graphicEntityPosition	getGraphcPos() const noexcept { return _graphicPos; }
		std::string		getTextrue() const noexcept { return _texture; }
		entities::entityType	getType() const noexcept { return _typeEnum; }
		std::size_t		getLayout() const noexcept { return _layout; }
		std::size_t		getId() const noexcept { return _id; }
		void			setId(std::size_t id) { _id = id; }
		std::size_t		getId() { return (_id); }
		void			die(bool state) { _isDead = state; }
		void			setMap(std::shared_ptr<Map> &map) {_map = map; };
		void			setTexture(std::string texture) { _texture = texture; }
		std::string		getName() { return _name; }
	protected:
		std::size_t		_id;
		graphicEntityPosition	_graphicPos;
		entityPosition		_pos;
		bool			_iskinematic;
		std::size_t		_layout;
		entities::entityType	_typeEnum;
		std::string		_texture;
		std::string		_name;
		std::shared_ptr<Map>	_map;
		bool			_isDead;
		//bool			_isregidBody;
		//bool			getIsRegidBody() { return _isregidBody; }
	};
//	std::size_t entities::Entity::_nb = 0;
}
#endif /* !ENTITY_HPP_ */
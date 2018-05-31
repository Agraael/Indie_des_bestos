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
			Entity(entityPosition pos, bool iskinematic, std::size_t layout, std::string type)
				: _pos(pos), _iskinematic(iskinematic), _layout(layout), _type(type) {}
		entityPosition		getPos() const noexcept { return _pos; }
		bool			isDead() const noexcept { return _isDead; }
		graphicEntityPosition	getGraphcPos() const noexcept { return _graphicPos; }
		bool			IsKinematic() const noexcept { return _iskinematic; }
		void			die(bool die) { (void)(die);_isDead = true; }
		void			displayType() const noexcept {std::cout << _type;};
		void			setMap(std::shared_ptr<Map> map) {_map = map; };
		std::string		getTextrue() const noexcept { return _texture; };
		void			setTexture(std::string texture) { _texture = texture; }
		std::size_t		getId() const noexcept { return entities::Entity::_id; };
	protected:
		static std::size_t	_id;
		entityPosition		_pos;
		bool			_iskinematic;
		std::string		_texture;
		std::shared_ptr<Map>	_map;
		std::size_t		_layout;
		std::string		_type;
		graphicEntityPosition	_graphicPos;
		bool			_isDead;
		//bool			_isregidBody;
		//bool			getIsRegidBody() { return _isregidBody; }
	};
}
#endif /* !ENTITY_HPP_ */

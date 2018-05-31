/*
** EPITECH PROJECT, 2018
** indie
** File description:
** header
*/

#ifndef HANDLEGAME_HPP_
	#define HANDLEGAME_HPP_

#include "../../Game/Map/src/Map.hpp"
#include "../../Game/Map/src/Gen.hpp"

class HandleGame {
	public:
		void    InitGame(/* char ** */);
		GameMap getGameMap() const noexcept { return (_threeDMap->get3dMap()); }
		void    updateMap() {}
	private:
		std::shared_ptr<Map>		_threeDMap;
};

#endif /* !HANDLEGAME_HPP_ */
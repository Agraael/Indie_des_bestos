/*
** EPITECH PROJECT, 2018
** indie
** File description:
** header
*/

#ifndef HANDLEGAME_HPP_
	#define HANDLEGAME_HPP_

#include <vector>
#include "IrrlichtLib.hpp"
#include "Map.hpp"
#include "Gen.hpp"

class HandleGame {
public:
	HandleGame(graphic::IrrlichtLib *lib) : _lib(lib) {}
	void    InitGame(/* char ** */);
	GameMap getGameMap() const noexcept { return (_threeDMap->get3dMap()); }
	void    updateMap() {}
private:
	std::shared_ptr<Map>		_threeDMap;
	graphic::IrrlichtLib		*_lib;
};

#endif /* !HANDLEGAME_HPP_ */

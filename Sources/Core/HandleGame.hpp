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

#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#include "irrlicht.h"
#endif

class HandleGame
{
	public:
		HandleGame(graphic::IrrlichtLib *lib) : _lib(lib) {}
		void	InitGame(const GenerationSize &, const GenerationMod &);
		void	updateMap() {}
		void	updtaeGameForanatole();
		GameMap getGameMap() const noexcept { return (_threeDMap->get3dMap()); }
	private:
		void	initMapGround(const GenerationSize &);
		std::shared_ptr<Map>			_threeDMap;
		graphic::IrrlichtLib			*_lib;
		std::vector<irr::scene::ISceneNode *>	_disp;
		const std::map<const GenerationSize, const Vector_t>	_hGameSizeTab = {
			{GenerationSize::Small, {13, 7}},
			{GenerationSize::Medium, {19, 13}},
			{GenerationSize::Big, {25, 19}}
		};

};

#endif /* !HANDLEGAME_HPP_ */

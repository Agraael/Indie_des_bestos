/*
** EPITECH PROJECT, 2018
** indie
** File description:
** header
*/

#ifndef HANDLEGAME_HPP_
	#define HANDLEGAME_HPP_

#include <unordered_map>
#include <vector>
#include "IrrlichtLib.hpp"
#include "Map.hpp"
#include "Gen.hpp"
#include "Entity.hpp"

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
		void	quitGame();
		GameMap getGameMap() const noexcept { return (_threeDMap->get3dMap()); }
	private:
		void	initMapGround(const GenerationSize &);
		void	addCubeToMap(const entities::Entity &);
		std::shared_ptr<Map>			_threeDMap;
		graphic::IrrlichtLib			*_lib;
		std::vector<irr::scene::ISceneNode *>	_disp;
		const std::map<const GenerationSize, const Vector_t>	_hGameSizeTab = {
			{GenerationSize::Small, {13, 7}},
			{GenerationSize::Medium, {19, 13}},
			{GenerationSize::Big, {25, 19}}
		};
		const std::unordered_map<entities::entityType, const std::string &>	_textureMap = {
			{entities::entityType::INDESTRUCTIBLE_TYPE, "./Assets/media/brick_wall.jpg"},
			{entities::entityType::DESTRUCTIBLE_TYPE, "./Assets/media/brick_wall.jpg"},
			{entities::entityType::BOMB_UP_TYPE, "./Assets/media/brick_wall.jpg"},
			{entities::entityType::BOMBS_TYPE, "./Assets/media/brick_wall.jpg"},
			{entities::entityType::FIRE_UP_TYPE, "./Assets/media/brick_wall.jpg"},
			{entities::entityType::GONNAEXPLOSE_TYPE, "./Assets/media/brick_wall.jpg"},
			{entities::entityType::IA_TYPE, "./Assets/media/brick_wall.jpg"},
			{entities::entityType::PLAYER_TYPE, "./Assets/media/brick_wall.jpg"},
			{entities::entityType::SPEED_UP_TYPE, "./Assets/media/brick_wall.jpg"},
			{entities::entityType::WALL_PASS_TYPE, "./Assets/media/brick_wall.jpg"}
		};
};

#endif /* !HANDLEGAME_HPP_ */

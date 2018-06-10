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

struct	gameType_t {
	std::string	game_name;
	GenerationSize	g_size;
	GenerationMod	g_mod;
	int		nb_player;
	int		nb_ia;
};

template<typename T>
struct Vector3d {
	T	x;
	T	y;
	T	z;
};

class HandleGame
{
	public:
		HandleGame(graphic::IrrlichtLib *lib) : _lib(lib) {}
		void	InitGame(const gameType_t &);
		void	updateMap(bool &);
		void	quitGame();
		void	dumpPlayerName();
		void	saveGame();
		GameMap getGameMap() const noexcept { return (_threeDMap->get3dMap()); }
		bool	CheckEndGame();
	private:
		void	changeDisp();
		void	updateDeletedEntity();
		void	updateAddEntity();
		void	initMapGround(const GenerationSize &, std::size_t &);
		void	addCubeToMap(const entities::Entity &, std::size_t &);
		void	updateEntity(const entities::Entity *);
		bool	gameEnd() noexcept;

		std::string				_gameName;
		std::shared_ptr<Map>			_threeDMap;
		graphic::IrrlichtLib			*_lib;
		std::vector<irr::scene::ISceneNode *>	_disp;
		std::string				_winnerName;
		char					**_map;
		bool					_timeDispWinner;
		const std::unordered_map<GenerationSize, const Vector3d<int>>	_hGameSizeTab = {
			{GenerationSize::Small, {15, 9, 10}},
			{GenerationSize::Medium, {25, 19, 16}},
			{GenerationSize::Big, {37, 31, 25}}
		};
		const std::unordered_map<entities::entityType, const std::string>	_textureMap = {
			{entities::entityType::INDESTRUCTIBLE_TYPE, "./Assets/media/BrickWall.jpg"},
			{entities::entityType::DESTRUCTIBLE_TYPE, "./Assets/media/wood_box.png"},
			{entities::entityType::BOMB_UP_TYPE, "./Assets/media/wood_box.png"},
			{entities::entityType::BOMBS_TYPE, "./Assets/media/brick_wall.jpg"},
			{entities::entityType::FIRE_UP_TYPE, "./Assets/media/lava.jpg"},
			{entities::entityType::GONNAEXPLOSE_TYPE, "./Assets/media/lava.jpg"},
			{entities::entityType::IA_TYPE, "./Assets/media/bmbrmn.png"},
			{entities::entityType::PLAYER_TYPE, "./Assets/media/bmbrmn.png"},
			{entities::entityType::SPEED_UP_TYPE, "./Assets/media/BrickWall.jpg"},
			{entities::entityType::WALL_PASS_TYPE, "./Assets/media/bmbrmn.png"}
		};
};

#endif /* !HANDLEGAME_HPP_ */

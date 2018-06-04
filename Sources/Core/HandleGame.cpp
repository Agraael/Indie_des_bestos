/*
** EPITECH PROJECT, 2018
** indie
** File description:
** source
*/

#include "HandleGame.hpp"
#include "InterpreteGeneration.hpp"
#include "MapGenerator.hpp"
#include "Gen.hpp"

void    HandleGame::InitGame(const GenerationSize &size, const GenerationMod &mod)
{
	InterpreteGeneration	interpret;
	MapGenerator		generator;

	generator.runGeneration(size, mod);
	_threeDMap = std::make_shared<Map>(Map(interpret.createMap(generator.getMap())));
	initMapGround(size);
	for (auto line : _threeDMap->get3dMap())
		for (auto tab : line)
			for (auto shared : tab)
				shared.get()->setMap(_threeDMap);
}

void	HandleGame::initMapGround(const GenerationSize &size)
{
	Vector_t	max = _hGameSizeTab.at(size);

	for (std::size_t y = 0; y < max.y + 1; y++) {
		for (std::size_t x = 0; x < max.x + 1; x++)
			_disp.push_back(_lib->createCube({static_cast<double>(x), static_cast<double>(y), 0}, "./Assets/media/brick_wall.jpg"));
	}
	_lib->setCamera({(static_cast<double>(max.x) / 2), - (static_cast<double>(max.y) / 2) + 4, -20}, {static_cast<double>(max.x) / 2, static_cast<double>(max.y) / 2, 0});
}

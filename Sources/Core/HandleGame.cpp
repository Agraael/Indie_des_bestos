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

void    HandleGame::InitGame()
{
	InterpreteGeneration    *interpret = new InterpreteGeneration;
	MapGenerator            *generator = new MapGenerator;

	generator->runGeneration(GenerationSize::Big, GenerationMod::FullDest);
	_threeDMap = std::make_shared<Map>(Map(interpret->createMap(generator->getMap())));
	for (auto line : _threeDMap->get3dMap())
		for (auto tab : line)
			for (auto shared : tab)
				shared.get()->setMap(_threeDMap);
}

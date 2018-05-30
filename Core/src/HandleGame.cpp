/*
** EPITECH PROJECT, 2018
** indie
** File description:
** source
*/

#include "HandleGame.hpp"
#include "../../Game/Map/src/InterpreteGeneration.hpp"
#include "../../Game/Map/src/MapGenerator.hpp"
#include "../../Game/Map/src/Gen.hpp"

void    HandleGame::InitGame()
{
	InterpreteGeneration    *interpret = new InterpreteGeneration;
	MapGenerator            *generator = new MapGenerator;
	char			**charMap;

	generator->runGeneration(GenerationSize::Big, GenerationMod::FullDest);
	charMap = generator->getMap();
	_threeDMap = std::make_shared<Map>(Map(interpret->createMap(generator->getMap())));
}
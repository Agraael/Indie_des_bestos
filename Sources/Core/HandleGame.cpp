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
	char			**charMap;

	(void)(charMap);
	generator->runGeneration(GenerationSize::Big, GenerationMod::FullDest);
	charMap = generator->getMap();
	_threeDMap = std::make_shared<Map>(Map(interpret->createMap(generator->getMap())));
}

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
	char			**map;

	generator->runGeneration(GenerationSize::Big, GenerationMod::FullDest);
	_threeDMap = std::make_shared<Map>(Map(interpret->createMap(generator->getMap())));
	map = generator->getMap();
	//for (int y = 0; map[y] != NULL; y++) {
	//	for (int x = 0; map[y][x] != '\0'; x++) {
	//		vec3df	vec;
	//		vec.x = static_cast<double>(x);
	//		vec.y = static_cast<double>(y);
	//		vec.z = 0;
	//		_lib->createCube(vec, "./Assets/media/pixel_skyline.png");
	//	}
	//}
	vec3df	vec;
	vec.x = 10;
	vec.y = -10;
	vec.z = -10;
	vec3df	kek;
	kek.x = 10;
	kek.y = 10;
	kek.z = 0;
	_lib->setCamera(vec, kek);
	for (auto line : _threeDMap->get3dMap())
		for (auto tab : line)
			for (auto shared : tab)
				shared.get()->setMap(_threeDMap);
}

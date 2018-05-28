#include "InterpreteGeneration.hpp"
#include "MapGenerator.hpp"
#include "Gen.hpp"
#include "../../Entity/Bombs/src/Bombs.hpp"
#include "Map.hpp"
#include "../../Entity/Walls/src/IndestructibleWalls.hpp"

int main()
{
	InterpreteGeneration    *interpret = new InterpreteGeneration;
	MapGenerator            *generator = new MapGenerator;
	GameMap			map;
	char			**charMap;
	int x = 0;
	int y = 0;

	generator->runGeneration(GenerationSize::Big, GenerationMod::FullDest);
	charMap = generator->getMap();
	for (int i = 0; charMap[i] != NULL; ++i)
	{
		std::cout << charMap[i] << std::endl;
	}
	Map *ThreeDMap = new Map(interpret->createMap(generator->getMap()));
	map = ThreeDMap->get3dMap();
	for (auto line : map) {
		y = 0;
		for (auto tab : line) {
			if (!(tab.empty()))
				std::cout << "M";
			++y;
		}
		std::cout << std::endl;
		++x;
	}
	ThreeDMap->placeBomb(std::make_pair(0, 1));
	map = ThreeDMap->get3dMap();
	std::cout << charMap[0][1] << std::endl;
	for (auto entity : map[0][1])
	{
		std::cout << "elem" << std::endl;
		if (static_cast<Bombs *>(entity.get()) == nullptr)
			std::cout << "oui" << std::endl;
		if (static_cast<IndestructibleWalls *>(entity.get()) == nullptr)
			std::cout << "oui" << std::endl;
	}
}
#include "InterpreteGeneration.hpp"
#include "MapGenerator.hpp"
#include "Gen.hpp"
#include "../../Entity/Bombs/src/Bombs.hpp"
#include "../../Entity/Bombs/src/GonnaExplose.hpp"
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
	std::shared_ptr<Map>		ThreeDMap = std::make_shared<Map>(Map(interpret->createMap(generator->getMap())));
	ThreeDMap->placeBomb(std::make_pair(1, 1), 3);
	map = ThreeDMap->get3dMap();
	for (auto line : map) {
		for (auto tab : line) {
			for (auto shared : tab) {
				shared.get()->setMap(ThreeDMap);
			}
			if (tab.empty())
				std::cout << " ";
			std::cout << " ";
		}
		std::cout << std::endl;
	}
}
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
	for (int i = 0; charMap[i] != NULL; ++i)
	{
		std::cout << charMap[i] << std::endl;
	}
	std::shared_ptr<Map>		ThreeDMap = std::make_shared<Map>(Map(interpret->createMap(generator->getMap())));
	map = ThreeDMap->get3dMap();
	for (auto line : map) {
		for (auto tab : line) {
			for (auto shared : tab) {
				shared->setMap(ThreeDMap);
			}			
		}
	}
	ThreeDMap->placeBomb(std::make_pair(0, 1), 3);
	map = ThreeDMap->get3dMap();
	std::cout << charMap[0][1] << std::endl;
	for (auto line : map) {
		for (auto tab : line) {
			for (auto shared : tab) {
 				if (static_cast<IndestructibleWalls *>(shared.get()) == nullptr)
					std::cout << "G";
				else
					std::cout << " ";
			}
		}
		std::cout << std::endl;
	}
}
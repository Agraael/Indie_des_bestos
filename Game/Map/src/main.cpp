#include "InterpreteGeneration.hpp"
#include "MapGenerator.hpp"
#include "Gen.hpp"

int main()
{
	InterpreteGeneration    *interpret = new InterpreteGeneration;
	MapGenerator            *generator = new MapGenerator;
	GameMap			map;
	char			**charMap;
	int x = 0;
	int y = 0;

	generator->runGeneration(GenerationSize::Big, GenerationMod::Standard);
	charMap = generator->getMap();
	map = interpret->createMap(generator->getMap());
	for (auto line : map) {
		y = 0;
		for (auto tab : line) {
			std::cout << charMap[x][y] << std::endl;
			for (auto elem : tab) {
				std::cout << elem.get()->getPos().first << ", " << elem.get()->getPos().second << std::endl;
			}
			++y;
		}
		++x;
	}
}
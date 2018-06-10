/*
** EPITECH PROJECT, 2018
** indie
** File description:
** savegame
*/

#include "SaveGame.hpp"

SaveGame::SaveGame()
{
}

SaveGame::~SaveGame()
{
}

void	SaveGame::save(const std::string &name, const std::shared_ptr<Map> &threeDMap, char **&map)
{
	std::ofstream	myFile(_path + name);
	GameMap		dMap = threeDMap->get3dMap();

	for (int y = 0; map[y]; y++) {
		for (int x = 0; map[y][x] != '\0'; x++) {
			if (!dumpChar(x, y, dMap, myFile))
				myFile.write(&(map[y][x]), 1);

		}
		myFile << '\n';
	}
	myFile.close();
}

bool	SaveGame::dumpChar(int x, int y, const GameMap &dMap, std::ofstream &myFile)
{
	for (auto shared : dMap[y][x]) {
		if (shared->getLayout() == 0) {
			//char i = static_cast<char>(shared->getType());
			myFile.write("A", 1);
			return true;
		}
	}
	return false;
}

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

void	SaveGame::save(const std::string &name, const char **&map)
{
	std::ofstream	myFile(_path + name);

	for (int y = 0; map[y]; y++) {
		for (int x = 0; map[y][x] != '\0'; x++)
			myFile << map[y][x];
		myFile << '\n';
	}
	myFile.close();
}
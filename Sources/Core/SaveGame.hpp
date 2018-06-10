/*
** EPITECH PROJECT, 2018
** indie
** File description:
** SaveGame
*/

#ifndef SAVEGAME_HPP_
	#define SAVEGAME_HPP_

#include <memory>
#include <fstream>
#include <unordered_map>
#include "Entity.hpp"
#include "Map.hpp"

class SaveGame
{
	public:
		SaveGame();
		~SaveGame();
		void	save(const std::string &, const std::shared_ptr<Map> &, char **&);
	private:
		bool	dumpChar(int, int, const GameMap &, std::ofstream &);
		const std::string	_path = "./gameMap/";
};

#endif /* !SAVEGAME_HPP_ */

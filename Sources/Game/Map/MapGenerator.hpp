/*
** EPITECH PROJECT, 2018
** Indie
** File description:
** Map Generator
*/

#ifndef MAPGENERATOR_HPP_
	#define MAPGENERATOR_HPP_

#include <cstdlib>
#include <functional>
#include <map>
#include "Gen.hpp"

class MapGenerator
{
	public:
		MapGenerator();
		~MapGenerator();
		void	runGeneration(const GenerationSize &, const GenerationMod &);
		void	setPlayers(const int &, const int &);
		char	**&getMap() { return _map; }
	private:
		char	**_map;

		void	genStandardMap(const Vector_t &);
		void	genFullDestMap(const Vector_t &);
		void	createMap(const Vector_t &);
		void	createMapLine(char *&, const mapline_t &, std::size_t);

		const std::map<const GenerationSize, const Vector_t>	_GenSizeTab = {
			{GenerationSize::Small, {13, 7}},
			{GenerationSize::Medium, {19, 13}},
			{GenerationSize::Big, {25, 19}}
		};
};

#endif /* !MAPGENERAOR_HPP_ */

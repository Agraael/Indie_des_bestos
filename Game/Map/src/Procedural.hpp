/*
** EPITECH PROJECT, 2018
** test
** File description:
** Procedural
*/

#ifndef PROCEDURAL_HPP_
	#define PROCEDURAL_HPP_

#include <random>
#include "Gen.hpp"

struct data_vec_t {
	Vector_t pos;
	Vector_t prec;
};

class Procedural {
	public:
		Procedural();
		~Procedural();
		void	placeUnDestWall1On2(char **&);
		void	placeDestWall(char **&, std::size_t);
		void	placeBonus(char **&, char, std::size_t);
		void	placeSpawnPointCorner(char **&, char, Vector_t);
		void	placeBlock(char **&, char, Vector_t);
	private:
		int	randomize();
		bool	placeWall(char **map, data_vec_t, char);
		int	checkChar(char **map, data_vec_t, char);
		std::default_random_engine	_engine;
};

#endif /* !PROCEDURAL_HPP_ */

/*
** EPITECH PROJECT, 2018
** Indie
** File description:
** Gen
*/

#ifndef GEN_HPP_
	#define GEN_HPP_

#include <cstdlib>

# define BOMB_UP	'B'
# define SPEED_UP	'S'
# define DESTRUCTIBLE	'D'
# define INDESTRUCTIBLE	'I'
# define FIRE_UP	'F'
# define WALL_PASS	'P'
# define PASS		' '
# define SPAWNPOINT	'C'

struct	Vector_t {
	std::size_t	x;
	std::size_t	y;
};

struct mapline_t {
	char	leftCorner;
	char	mid;
	char	rightCorner;
};

enum GenerationSize {
	Small,
	Medium,
	Big
};

enum GenerationMod {
	Standard,
	FullDest
};

#endif /* !GEN_HPP_ */

/*
** EPITECH PROJECT, 2018
** Indie
** File description:
** Gen
*/

#ifndef GEN_HPP_
	#define GEN_HPP_

#include "Entity.hpp"
#include <cstdlib>
#include <vector>

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

using	SharedEntity = std::vector<std::shared_ptr<entities::Entity>>;
using	EntitiesVec = std::vector<SharedEntity>;
using	GameMap = std::vector<EntitiesVec>;
using	RefGameMap = GameMap &;

#endif /* !GEN_HPP_ */

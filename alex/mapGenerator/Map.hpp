/*
** EPITECH PROJECT, 2018
** test
** File description:
** Map
*/

#ifndef MAP_HPP_
	#define MAP_HPP_

#include <cstdlib>

struct vec_t {
	std::size_t	x;
	std::size_t	y;
};

struct mapline_t {
	char	leftCorner;
	char	mid;
	char	rightCorner;
};

# define	WALL	'#'
# define	PATH	' '

class Map {
	public:
		Map(const vec_t &);
		~Map();
		char	**&createMap();
		void	printMap();
		char	**getMap() { return _map; }
	private:
		void	placeCharLine(char *&, const mapline_t &);
		void	clearMap();
		char	**_map;
		vec_t	_max;
};

#endif /* !MAP_HPP_ */

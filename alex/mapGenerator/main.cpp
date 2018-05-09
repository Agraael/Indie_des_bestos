/*
** EPITECH PROJECT, 2018
** test
** File description:
** main
*/

#include "Map.hpp"
#include "Procedural.hpp"

int	main()
{
	vec_t	max = {19, 13};
	Map	a(max);
	Procedural	p;

	a.createMap();
	char **map = a.getMap();
	//p.placeUnDestWall1On2(map);
	p.placeDestWall(map, 40);
	p.placeBlock(map, 'X', max);
	p.placeSpawnPointCorner(map, 'O', max);
	char **bonusmap = a.getMap();
	a.printMap();
	return (0);
}
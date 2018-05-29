/*
** EPITECH PROJECT, 2018
** indie
** File description:
** main
*/

#include "Core.hpp"

int	main(int ac, char **av)
{
	Core	core;

	(void)ac;
	(void)av;
	if (core.run() == 84)
		return (84);
	return (0);
}
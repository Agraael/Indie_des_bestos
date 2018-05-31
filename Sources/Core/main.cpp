/*
** EPITECH PROJECT, 2018
** indie
** File description:
** main
*/

#include <iostream>
#include <exception>
#include "Core.hpp"

int	main(int ac, char **av)
{
	Core	core;

	(void)ac;
	(void)av;
	try
	{
	if (core.run() == 84)
		return (84);
	} catch(std::exception ex) {
		std::cout << ex.what() << std::endl;
	}
	return (0);
}
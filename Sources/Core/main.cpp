/*
** EPITECH PROJECT, 2018
** indie
** File description:
** main
*/

//#include <iostream>
//#include <exception>
//#include "Core.hpp"
//
//int	main(int ac, char **av)
//{
//	Core	core;
//
//	(void)ac;
//	(void)av;
//	try
//	{
//	if (core.run() == 84)
//		return (84);
//	} catch(std::exception ex) {
//		std::cout << ex.what() << std::endl;
//	}
//	return (0);
//}


#include <memory>
#include "../LocalMenu/localMenu.hpp"
#include <irrKlang.h>
#include <string>
#include <cstdio>
#include <iostream>
#include "irrKlang.h"

using namespace std;

int main()
{

	irrklang::ISoundEngine* engine = irrklang::createIrrKlangDevice();

	if (!engine) return 1; // could not start engine

	engine->setSoundVolume(1.0f);
	engine->play2D("./media/bombermanMenu.mp3"); // play some mp3 file

	cout<<"hello\n";

	std::cin.get(); // wait until user presses a key

	engine->drop(); // delete engine
	return 0;
}
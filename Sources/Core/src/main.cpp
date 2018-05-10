/*
** EPITECH PROJECT, 2018
** indie
** File description:
** source
*/

#include <irrlicht/irrlicht.h>
#include "IrrlichtLib.hpp"
#include <iostream>

int main()
{
	std::cout << "Hello Indie !!" << std::endl;

	int main()
	{
		graphic::IrrlichtLib Lib;
		Lib.setMesh();
		while(Lib._device->run())
		{
		        Lib._guiEnv->addStaticText(L"WRITE SOMETHING", irr::core::rect<irr::s32>(10,10,260,22), true);
		        Lib.displayAll();
		}
	}
	return 0;
}

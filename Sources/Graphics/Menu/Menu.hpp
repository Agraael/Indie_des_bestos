//
// Created by Ludovica Pagliarani on 08/05/2018.
//

#ifndef MENU_HPP
#define MENU_HPP

#include "IrrlichtLib.hpp"
#include "LibEventManager.hpp"

namespace graphic
{

	class Menu
	{
	public:
		Menu(graphic::IrrlichtLib *lib);
		~Menu() = default;
		void printLogo();
		void drawChoiceButtons();
		void startDirigible();
		irr::gui::IGUIImage *drawDirigible();
		void printBackground();
		void printUserName();
		void display();
		void updateDisplay();
		void drawChoice();
	private:
		graphic::IrrlichtLib *_lib;
		irr::gui::IGUIImage *_dirigible;
		size_t _count;
	};
}

#endif //MENU_HPP

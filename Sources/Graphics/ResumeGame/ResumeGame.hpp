//
// Created by Ludovica Pagliarani on 08/05/2018.
//

#ifndef RESUMEGAME_HPP
#define RESUMEGAME_HPP

#include "IrrlichtLib.hpp"
#include "LibEventManager.hpp"

namespace graphic
{

	class ResumeGame
	{
	public:
		ResumeGame(graphic::IrrlichtLib *lib);
		~ResumeGame() = default;
		void printLogo();
		void drawChoiceButtons();
		void startDirigible();
		irr::gui::IGUIImage *drawDirigible();
		void printBackground();
		void display();
		void printListBox();
		void updateDisplay();
		void drawChoice();
	private:
		graphic::IrrlichtLib *_lib;
		irr::gui::IGUIImage *_dirigible;
		vec2d _size;
		size_t _count;
	};
}

#endif //RESUMEGAME_HPP

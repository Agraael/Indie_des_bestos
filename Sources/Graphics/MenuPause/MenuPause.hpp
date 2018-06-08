/*
** EPITECH PROJECT, 2018
** Indie
** File description:
** MenuPause
*/

#ifndef MENUPAUSE_HPP_
	#define MENUPAUSE_HPP_

#include "IrrlichtLib.hpp"
#include "HandleGame.hpp"

namespace graphic
{
	class MenuPause {
		public:
			MenuPause(graphic::IrrlichtLib *&lib) : _lib(lib) {}
			~MenuPause();
			void	display();
			void	updateDisplay(HandleGame &);
		private:
			graphic::IrrlichtLib	*_lib;
			void	printContinue();
			void	printQuit();
			void	printSave();
			void	printTitle();
	};
}

#endif /* !MENUPAUSE_HPP_ */

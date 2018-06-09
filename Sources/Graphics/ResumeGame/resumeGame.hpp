//
// Created by Ludovica Pagliarani on 08/05/2018.
//

#ifndef RESUMEGAME_HPP
#define RESUMEGAME_HPP

#include <unordered_map>
#include <algorithm>
#include <functional>
#include "IrrlichtLib.hpp"
#include "EventManager.hpp"

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
        void drawFileName();
		void printListBox();
		void manageFiles(size_t nbr);
		void updateDisplay();
		void drawChoice();
		void saveFilesToVector();
	private:
		graphic::IrrlichtLib *_lib;
		irr::gui::IGUIImage *_dirigible;
		vec2d _size;
		int _count;
		size_t _itFiles;
        irr::gui::IGUIImage *_fileImg;
        std::string _fileName;
		std::vector<std::string> _files;
		std::unordered_map<char, std::string> _alphaMap = {
				{'A', "./Assets/media/A_letter.png"},
				{'B', "./Assets/media/B_letter.png"},
				{'C', "./Assets/media/C_letter.png"},
				{'D', "./Assets/media/D_letter.png"},
				{'E', "./Assets/media/E_letter.png"},
				{'F', "./Assets/media/F_letter.png"},
				{'G', "./Assets/media/G_letter.png"},
				{'H', "./Assets/media/H_letter.png"},
				{'I', "./Assets/media/I_letter.png"},
				{'J', "./Assets/media/J_letter.png"},
				{'K', "./Assets/media/K_letter.png"},
				{'L', "./Assets/media/L_letter.png"},
				{'M', "./Assets/media/M_letter.png"},
				{'N', "./Assets/media/N_letter.png"},
				{'O', "./Assets/media/O_letter.png"},
				{'P', "./Assets/media/P_letter.png"},
				{'Q', "./Assets/media/Q_letter.png"},
				{'R', "./Assets/media/R_letter.png"},
				{'S', "./Assets/media/S_letter.png"},
				{'T', "./Assets/media/T_letter.png"},
				{'U', "./Assets/media/U_letter.png"},
				{'V', "./Assets/media/V_letter.png"},
				{'W', "./Assets/media/W_letter.png"},
				{'X', "./Assets/media/X_letter.png"},
				{'Y', "./Assets/media/Y_letter.png"},
				{'Z', "./Assets/media/Z_letter.png"},
		};
        std::unordered_map<IndieEvents::IndieKeys, std::function<void()>>	_manageEvent = {
                {IndieEvents::NEXT_FILE, [this](){ manageFiles(1);  }},
                {IndieEvents::PREV_FILE, [this](){ manageFiles(-1); }},
                //{graphic::controllerUser::IA_DOWN, [this](){ (_aisNb == 0) ? _aisNb = 0 : _aisNb--; }},
                //{graphic::controllerUser::IA_UP, [this](){ (_aisNb == 3) ? _aisNb = 3 : _aisNb++; }},
        };
	};
}

#endif //RESUMEGAME_HPP

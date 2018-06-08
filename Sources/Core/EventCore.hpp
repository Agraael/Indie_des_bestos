/*
** EPITECH PROJECT, 2018
** indie
** File description:
** event core
*/

#ifndef EVENTCORE_HPP_
	#define EVENTCORE_HPP_

#include "EventManager.hpp"
#include "IrrlichtLib.hpp"
#include <unordered_map>

enum	CoreState {
	IN_MENU,
	IN_SOLO,
	IN_LOCAL,
	IN_LOCAL_GAME,
	IN_SETTINGS,
	EXIT,
	GAME_PAUSE
};

class EventCore
{
	public:
		EventCore(graphic::IrrlichtLib *lib) : _lib(lib) {}
		~EventCore();
		CoreState	updateCore(CoreState) const noexcept;
	private:
		graphic::IrrlichtLib		*_lib;
		static const std::unordered_map<graphic::controllerUser, CoreState>	_statesTab;
};

#endif /* !EVENTCORE_HPP_ */

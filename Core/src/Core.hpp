/*
** EPITECH PROJECT, 2018
** indie
** File description:
** header
*/

#ifndef CORE_HPP_
	#define CORE_HPP_

#include "EventManager.hpp"

class Core
{
	public:
		Core();
		~Core();
		int	run();
	private:
		IndieEvents::EventManager	*_events;
};

#endif /* !CORE_HPP_ */

/*
** EPITECH PROJECT, 2018
** indie
** File description:
** source
*/

#include "Core.hpp"

Core::Core()
: _events(new IndieEvents::EventManager()), _state(CoreState::IN_MENU)
{
}

Core::~Core()
{
}

int	Core::run()
{

}
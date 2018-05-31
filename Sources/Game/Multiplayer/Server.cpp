/*
** EPITECH PROJECT, 2018
** indie
** File description:
** source
*/

#include "Server.hpp"

Server::Server()
{
    _count = -30;
}

Server::~Server()
{
    graphic::infos_t buttonPlay;
    buttonPlay._x = 200;
    buttonPlay._y = 250;
    buttonPlay._w = 400;
    buttonPlay._h = 280;
    buttonPlay._path = "./media/button_menu.png";
    buttonPlay._desc = "Play the game";
    buttonPlay._name = "Play";
    buttonPlay._type = graphic::GUI_ID_QUIT_BUTTON;
    _lib->printButton(buttonPlay);

    graphic::infos_t buttonChoise;
    buttonChoise._x = 200;
    buttonChoise._y = 310;
    buttonChoise._w = 400;
    buttonChoise._h = 340;
    buttonChoise._path = "./media/button_menu.png";
    buttonChoise._desc = "Change settings game";
    buttonChoise._name = "Settings";
    buttonChoise._type = graphic::GUI_ID_QUIT_BUTTON;
    _lib->printButton(buttonChoise);

    graphic::infos_t buttonExit;
    buttonExit._x = 200;
    buttonExit._y = 360;
    buttonExit._w = 400;
    buttonExit._h = 390;
    buttonExit._path = "./media/button_menu.png";
    buttonExit._desc = "Exit the game";
    buttonExit._name = "Quit";
    buttonExit._type = graphic::GUI_ID_QUIT_BUTTON;
    _lib->printButton(buttonExit);
}

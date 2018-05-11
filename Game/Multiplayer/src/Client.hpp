/*
** EPITECH PROJECT, 2021
** Indie_des_bestos
** File description:
** Created by lotnot,
*/

#ifndef CLIENT_HPP_
#define CLIENT_HPP_


#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <iostream>
#include <netdb.h>
#include <vector>
#include <sstream>

class Client {
	public :
		Client() = default;
		~Client() =default;
		int joinGame();
		int ConnectToServer();
	private :
		std::string _ipServer;
		int _fd;
		int _port;



};

#endif
/*
** EPITECH PROJECT, 2021
** Indie_des_bestos
** File description:
** Created by lotnot,
*/

#ifndef SERVER_HPP_
#define SERVER_HPP_

#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <iostream>
#include <netdb.h>
#include <vector>

class Server
{
	public :
		Server() = default;
		~Server() = default;
		int createCommunication();
		int hostGame();
		int getMax();
		int connectedToGame();
		int joinGame();
		int handleClient(int, std::vector<std::pair<int, std::string>> );
		std::string getIp();
	private :
		int _serverFd;
		fd_set _readfds;
		bool playing;
		std::vector<std::pair<int, std::string>> fdPlayer;
		std::string _serverIp;
		int _portServer;
};

#endif
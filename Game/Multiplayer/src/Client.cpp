/*
** EPITECH PROJECT, 2021
** Indie_des_bestos
** File description:
** Created by lotnot, 
*/

#include "Client.hpp"

int Client::ConnectToServer()
{
	struct protoent *pe;
	struct sockaddr_in sin;
	std::string buff;
	int i;

	pe = getprotobyname("TCP");
	_fd = socket(AF_INET, SOCK_STREAM, pe->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(_port);
	sin.sin_addr.s_addr = inet_addr(_ipServer.c_str());
	if (connect(_fd, (struct sockaddr *)&sin, sizeof(sin)) == -1)
		return (-1);
	while (1)
	{
		
		//playgame
		//write(1, "yolo\n", 5);
		sleep(1);
	}
}

int Client::joinGame()
{
	std::string port;

	std::cout << "ip server : " << std::endl;
	std::getline(std::cin, _ipServer);
	std::cout << "port connection : " << std::endl;
	std::getline(std::cin, port);
	std::istringstream (port) >> _port;
	ConnectToServer();
}

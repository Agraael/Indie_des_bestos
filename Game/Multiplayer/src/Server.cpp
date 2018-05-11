/*
** EPITECH PROJECT, 2021
** Indie_des_bestos
** File description:
** Created by lotnot, 
*/

#include "Server.hpp"
#include <algorithm>
#include <cstdio>
#include <iostream>

#include <memory>
#include <stdexcept>
#include <string>
#include <array>

std::string Server::getIp()
{
	std::array<char, 128> buffer;
	std::string result;
	std::string cmd = "hostname -I";
	std::shared_ptr<FILE> ip(popen(cmd.c_str(), "r"), pclose);

	while (!feof(ip.get())) {
		if (fgets(buffer.data(), 128, ip.get()) != nullptr)
			result += buffer.data();
	}
	result = result.substr(0, result.size()-1);
	return result;
}


int Server::createCommunication()
{
	struct protoent *pe;
	struct sockaddr_in sin;
	struct sockaddr_in cin;
	socklen_t len;

	pe = getprotobyname("TCP");
	_serverFd = socket(AF_INET, SOCK_STREAM, pe->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = 0;
	sin.sin_addr.s_addr = INADDR_ANY;
	bind(_serverFd, (const struct sockaddr *)&sin, sizeof(sin));
	listen(_serverFd, 4);
	len = sizeof(cin);
	getsockname(_serverFd, (struct sockaddr *)&sin, &len);
	_portServer = ntohs(sin.sin_port);
	std::cout << _portServer << std::endl;
	_serverIp = getIp();
	std::cout <<  _serverIp << std::endl;
	std::cout << "waiting_connection" << std::endl;
	fdPlayer.push_back(std::make_pair(accept(_serverFd, (struct sockaddr *)&cin, &len), "joueur2"));
	std::cout << fdPlayer[0].second << std::endl;
	fdPlayer.push_back(std::make_pair(accept(_serverFd, (struct sockaddr *)&cin, &len), "joueur3"));
	std::cout << fdPlayer[1].second << std::endl;
	fdPlayer.push_back(std::make_pair(accept(_serverFd, (struct sockaddr *)&cin, &len), "joueur4"));
	std::cout << fdPlayer[2].second << std::endl;
	std::cout << "all player connected" << std::endl;
}

int Server::getMax()
{
	int max = 0;
	FD_ZERO(&_readfds);
	FD_SET(fdPlayer[0].first, &_readfds);
	FD_SET(fdPlayer[1].first, &_readfds);
	FD_SET(fdPlayer[2].first, &_readfds);
	for (auto &i : fdPlayer) {
		if (i.first > max)
			max = i.first;
	}
	return max;
}

int Server::handleClient(int fdClient1, std::vector<std::pair<int, std::string>> fdPlayer)
{
	char buff[4096];
	int len;
	int len2;

	len = read(fdClient1, buff, 40096);
	std::cout << buff << std::endl;
	if (len == -1) {
		std::cerr << "fail read\n" << std::endl;
		return (-1);
	}
	for (auto &i : fdPlayer) {
		write(i.first, buff, len);
	}
}

int Server::hostGame()
{
	int fdMax;
	int playing = 0;

	createCommunication();
	while (!playing) {
		fdMax = getMax();
		if (select(fdMax + 1, &_readfds, NULL, NULL, NULL) == -1)
			playing  = 1;
		else {
			for (auto &i : fdPlayer) {
				if (FD_ISSET(i.first, &_readfds))
					handleClient(i.first, fdPlayer);
			}
		}
	}
}
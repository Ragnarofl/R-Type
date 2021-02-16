/*
** EPITECH PROJECT, 2020
** Network
** File description:
** Network
*/

#ifndef __NETWORK__
#define __NETWORK__

#include <SFML/Network.hpp>
#include <iostream>
#include <cstdlib>
#include <string>
#include "string.h"
#include "Coordinator.hpp"

class Network {
    private:
        sf::UdpSocket _socket;
        unsigned short _port;
        char _data[1024];
    public:
        Network(unsigned short port);
        ~Network();
        int send(std::string data, sf::IpAddress ip, unsigned short port);
        std::string read();
};

#endif /**/
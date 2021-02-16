/*
** EPITECH PROJECT, 2020
** Network
** File description:
** Network
*/

#include "Network.hpp"

Network::Network(unsigned short port) : _port(port)
{
    if (_socket.bind(_port) != sf::Socket::Done) {

    }
    _socket.setBlocking(false);
}

Network::~Network() {}

int Network::send(std::string data, sf::IpAddress ip, unsigned short port)
{
    if (_socket.send(data.data(), data.size(), ip, port) != sf::Socket::Done) {
        std::cout << "Failed to send payload." << std::endl;
        return 0;
    }
    return 1;
}

std::string Network::read()
{
    std::size_t received;
    sf::IpAddress sender;
    unsigned short port;
    memset(_data, 0, 1024);

    if (_socket.receive(_data, 1024, received, sender, port) != sf::Socket::Done) {

    } // else
        // std::cout << "Received : " << _data << std::endl;
    return std::string(_data);
}
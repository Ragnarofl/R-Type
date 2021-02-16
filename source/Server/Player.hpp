/*
** EPITECH PROJECT, 2020
** Player
** File description:
** Player
*/

#ifndef __PLAYER__
#define __PLAYER__

#include "SafeQueue.hpp"
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <ctime>
#include <map>

using boost::asio::ip::address;
using boost::asio::ip::udp;

class Player {
    private:
        udp::socket _socket;
        SafeQueue _queue;
        std::vector<std::string> _data;
        udp::endpoint _addr;
        int _position = 0;
        int _room_nb = 0;
    public:
        Player(udp::socket socket, udp::endpoint addr);
        ~Player();
        void add_data(std::string str);
        std::string pop_first_data();
        void do_write(std::string data);
        void set_position(int pos);
        void set_room_nb(int room_nb);
        udp::endpoint get_endpoint() const;
        int get_position() const;
        int get_room_nb() const;
};

#endif /**/
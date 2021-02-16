/*
** EPITECH PROJECT, 2020
** Server
** File description:
** Server
*/

#ifndef __SERVER__
#define __SERVER__

#include "Interface.hpp"
#include "Room.hpp"
#include "Player.hpp"

class Server {
    private:
        boost::asio::io_context _io_context;
        int _port;
        udp::socket _socket;
        udp::endpoint _sender_endpoint;
        enum { max_length = 1024 };
        char _data[max_length];
        Interface _interface;
    public:
        Server(int port);
        ~Server();
        void do_receive();
        void do_send(std::string data);
        void run();
};

#endif /**/
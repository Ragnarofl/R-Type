/*
** EPITECH PROJECT, 2020
** Server
** File description:
** Server
*/

#include "Server.hpp"

Server::Server(int port)
 : _io_context(), _socket(_io_context, udp::endpoint(udp::v4(), port))
{
    _port = port;
    do_receive();
}

Server::~Server() {}

void Server::do_receive()
{
    _socket.async_receive_from(
        boost::asio::buffer(_data, max_length), _sender_endpoint,
        [this](boost::system::error_code ec, std::size_t bytes_recvd) {
            if (!ec && bytes_recvd > 0) {
                // std::cout << "Received : " << std::string(_data) << std::endl;
                // std::cout << "From : " << _sender_endpoint << std::endl;
                if (!_interface.player_exist(_sender_endpoint)) {
                    udp::socket sock(_io_context, udp::v4());
                    _interface.add_player(std::move(sock), _sender_endpoint);
                }
                std::string data = _interface.get_data(_data, _sender_endpoint);
                do_send(data);
                memset(_data, 0, max_length);
            } else {
                do_receive();
            }
        });
}

void Server::do_send(std::string data)
{
    _socket.async_send_to(
        boost::asio::buffer(data, data.size()), _sender_endpoint,
        [this](boost::system::error_code /*ec*/, std::size_t /*bytes_sent*/) {
            do_receive();
        });
}

void Server::run()
{
    _io_context.run();
}

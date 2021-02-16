/*
** EPITECH PROJECT, 2020
** Player
** File description:
** Player
*/

#include "Player.hpp"

Player::Player(udp::socket socket, udp::endpoint addr) : _socket(std::move(socket))
{
    _addr = addr;
}

Player::~Player() {}

void Player::add_data(std::string str)
{
//    _data.push_back(str);
    _queue.push(str);
    // std::cout << "Data added." << std::endl;
}

std::string Player::pop_first_data()
{
    std::string tmp = _queue.pop();
    return tmp;
}

void Player::do_write(std::string data)
{
    // std::cout << "Sent: " << data << std::endl;
    _socket.async_send_to(
        boost::asio::buffer(data, data.size()), _addr,
        [this](boost::system::error_code ec, std::size_t /*bytes_sent*/) {
            if (ec) {
                std::cout << "Problem with write" << std::endl;
            }
        });
}

void Player::set_position(int pos)
{
    _position = pos;
}

void Player::set_room_nb(int room_nb)
{
    _room_nb = room_nb;
}

udp::endpoint Player::get_endpoint() const
{
    return _addr;
}

int Player::get_position() const
{
    return _position;
}

int Player::get_room_nb() const
{
    return _room_nb;
}
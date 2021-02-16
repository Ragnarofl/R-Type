/*
** EPITECH PROJECT, 2020
** Interface
** File description:
** Interface
*/

#ifndef __INTERFACE__
#define __INTERFACE__

#include <iostream>
#include <map>
#include <string>
#include "Room.hpp"

class Interface {
    private:
        typedef std::string(Interface::*ptr)(std::string, udp::endpoint);
        std::map<std::string, ptr> _map;
        std::map<udp::endpoint, std::shared_ptr<Player>> _player_list;
        std::vector<std::shared_ptr<Room>> _room_list;
    public:
        Interface();
        ~Interface();
        std::string get_data(std::string str, udp::endpoint endp);
        int player_exist(udp::endpoint endp) const;
        void add_player(udp::socket socket, udp::endpoint sender_endpoint);
        std::string new_room(std::string str, udp::endpoint endp);
        std::string room_info(std::string str, udp::endpoint endp);
        std::string join_room(std::string str, udp::endpoint endp);
        std::string player_room_position(std::string str, udp::endpoint endp);
        std::string leave_room(std::string str, udp::endpoint endp);
        std::string player_pos(std::string str, udp::endpoint endp);
        std::string player_shoot(std::string str, udp::endpoint endp);
        std::string player_dead(std::string str, udp::endpoint endp);
        std::string player_hit(std::string str, udp::endpoint endp);
        std::string enemy_dead(std::string str, udp::endpoint endp);
        std::string enemy_hit(std::string str, udp::endpoint endp);
};

#endif /**/
/*
** EPITECH PROJECT, 2020
** Interface
** File description:
** Interface
*/

#include "Interface.hpp"

Interface::Interface()
{
    _map["100"] = &Interface::new_room;
    _map["101"] = &Interface::room_info;
    _map["102"] = &Interface::join_room;
    _map["103"] = &Interface::player_room_position;
    _map["104"] = &Interface::leave_room;
    _map["105"] = &Interface::player_pos;
    _map["106"] = &Interface::player_shoot;
    _map["107"] = &Interface::player_dead;
    _map["108"] = &Interface::player_hit;
    _map["109"] = &Interface::enemy_dead;
    _map["110"] = &Interface::enemy_hit;
}

Interface::~Interface() {}

std::string Interface::get_data(std::string str, udp::endpoint endp)
{
    std::string res("");
    std::string code("");
    if (str.empty() || str.size() <= 4) {
        res = "800";
        return res;
    }
    code = str.substr(0, 3);
    res = (this->*(_map[code]))(str.substr(4), endp);
    return res;
}

int Interface::player_exist(udp::endpoint endp) const
{
    if (_player_list.find(endp) != _player_list.end())
        return 1;
    return 0;
}

void Interface::add_player(udp::socket socket, udp::endpoint sender_endpoint)
{
    _player_list[sender_endpoint] = std::make_shared<Player>(std::move (socket), sender_endpoint);
}

std::string Interface::new_room(std::string /*str*/, udp::endpoint endp)
{
    _room_list.push_back(std::make_shared<Room>(_player_list[endp]));
    _room_list.back().get()->start();
    std::cout << "New room created for player " << endp << std::endl;
    return std::string("200/Room created");
}

std::string Interface::room_info(std::string /*str*/, udp::endpoint /*endp*/)
{
    std::string res("200/");
    for (unsigned int i = 0; i < _room_list.size(); i++) {
        std::string tmp = std::to_string(i + 1);
        tmp += ":";
        tmp += std::to_string(_room_list[i]->get_player_count());
        tmp += "/";
        res += tmp;
    }
    return res;
}

std::string Interface::join_room(std::string str, udp::endpoint endp)
{
    unsigned int room_nb = atoi(str.c_str());

    std::cout << room_nb << std::endl;
    if (room_nb <= _room_list.size()) {
        _player_list[endp]->set_room_nb(room_nb);
        _room_list[room_nb - 1].get()->add_new_player(_player_list[endp]);
        _player_list[endp]->add_data(std::string("202/" + std::to_string(_player_list[endp]->get_position())));
        std::cout << endp << " joined room number " << room_nb << std::endl;
        return std::string("211/" + std::to_string(_player_list[endp]->get_position()));
    }
    return std::string("201/Failed to join room");
}

std::string Interface::player_room_position(std::string /*str*/, udp::endpoint endp)
{
    std::string tmp("203/");
    int res = _player_list[endp]->get_position();
    tmp += std::to_string(res);
    return tmp;
}

std::string Interface::leave_room(std::string /*str*/, udp::endpoint endp)
{
    std::cout << "Removing player." << std::endl;
    _room_list[_player_list[endp]->get_room_nb() - 1]->remove_player(endp);
    std::cout << "Removed player." << std::endl;
    return std::string();
}

std::string Interface::player_pos(std::string str, udp::endpoint endp)
{
    _player_list[endp]->add_data(std::string("205/" + str));
    return std::string();
}

std::string Interface::player_shoot(std::string str, udp::endpoint endp)
{
    _player_list[endp]->add_data(std::string("206/" + str));
    return std::string();
}

std::string Interface::player_dead(std::string str, udp::endpoint endp)
{
    _player_list[endp]->add_data(std::string("207/" + str));
    return std::string();
}

std::string Interface::player_hit(std::string str, udp::endpoint endp)
{
    _player_list[endp]->add_data(std::string("208/" + str));
    return std::string();
}

std::string Interface::enemy_dead(std::string str, udp::endpoint endp)
{
    _player_list[endp]->add_data(std::string("209/" + str));
    return std::string();
}

std::string Interface::enemy_hit(std::string str, udp::endpoint endp)
{
    _player_list[endp]->add_data(std::string("210/" + str));
    return std::string();
}

/*
** EPITECH PROJECT, 2020
** B-CPP-501-MPL-5-1-rtype-balthazard.grego
** File description:
** test main
*/

#include "Core.hpp"

int main(int ac, char **av)
{
    try {
        if (ac != 2) {
            std::cerr << "Usage: async_udp_echo_server <port>\n";
            return 1;
        }
        Core server(std::atoi(av[1]));
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

  return 0;
}
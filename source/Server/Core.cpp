/*
** EPITECH PROJECT, 2020
** Core
** File description:
** Core
*/

#include "Core.hpp"

Core::Core(int port)
{
    Server s(port);
    s.run();
}

Core::~Core() {}
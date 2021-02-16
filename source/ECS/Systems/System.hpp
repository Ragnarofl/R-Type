/*
** EPITECH PROJECT, 2020
** B-CPP-501-MPL-5-1-rtype-balthazard.grego
** File description:
** System
*/

#ifndef SYSTEM_HPP_
#define SYSTEM_HPP_

#include <set>
#include "EntityManager.hpp"

class System {
    public:
        std::set<Entity> mEntities;
};

#endif /* !SYSTEM_HPP_ */

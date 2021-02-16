/*
** EPITECH PROJECT, 2020
** B-CPP-501-MPL-5-1-rtype-balthazard.grego
** File description:
** ClientEnemyNetworkSystem
*/

#ifndef CLIENTENEMYNETWORKSYSTEM_HPP_
#define CLIENTENEMYNETWORKSYSTEM_HPP_

#include "Coordinator.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Transform.hpp"
#include "PF_BasicEnemyShape.hpp"

class ClientEnemyNetworkSystem : public System {
    public:
        void Update(Coordinator &gCoordinator, std::string info);
    private:
        bool spawned = false;
};

#endif /* !CLIENTENEMYNETWORKSYSTEM_HPP_ */

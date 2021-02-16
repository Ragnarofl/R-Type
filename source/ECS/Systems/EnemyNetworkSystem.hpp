/*
** EPITECH PROJECT, 2020
** B-CPP-501-MPL-5-1-rtype-balthazard.grego
** File description:
** EnemyNetworkSystem
*/

#ifndef ENEMYNETWORKSYSTEM_HPP_
#define ENEMYNETWORKSYSTEM_HPP_

#include "System.hpp"
#include "Coordinator.hpp"
#include "Enemy.hpp"
#include "Transform.hpp"
#include "Player.hpp"



class EnemyNetworkSystem : public System
{
    public:
        void Update(Coordinator &gCoordinator, std::vector<std::shared_ptr<Player>> player_list);
};

#endif /* !ENEMYNETWORKSYSTEM_HPP_ */

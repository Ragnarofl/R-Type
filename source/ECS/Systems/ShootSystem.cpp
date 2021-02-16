/*
** EPITECH PROJECT, 2020
** B-CPP-501-MPL-5-1-rtype-balthazard.grego
** File description:
** ShootSystem
*/

#include "ShootSystem.hpp"
#include "PF_Missile_Shape.hpp"

void ShootSystem::Update(Coordinator& gCoordinator, Network& networkInstance)
{
    PF_Missile_Shape missile;

    for (auto &entity : mEntities) 
    {
        // std::cout << "in inputSystem" << std::endl;
        auto &player = gCoordinator.GetComponent<PlayerComponent>(entity);
        auto& transform = gCoordinator.GetComponent<Transform>(entity);

        //Network Sending data
        if (player.hasShoot) {
            missile.Create(gCoordinator, player.playerNumber, transform.Position);
            player.hasShoot = false;
            networkInstance.send("106/" + std::to_string(player.playerNumber) + ":" + std::to_string((int)transform.Position.x) + ":" + std::to_string((int)transform.Position.y), sf::IpAddress(IP_ADDRESS), 10010);
        }
    }
}

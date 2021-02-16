/*
** EPITECH PROJECT, 2020
** B-CPP-501-MPL-5-1-rtype-balthazard.grego
** File description:
** EnemyNetworkSystem
*/

#include "EnemyNetworkSystem.hpp"
#include "Player.hpp"

void EnemyNetworkSystem::Update(Coordinator& gCoordinator, std::vector<std::shared_ptr<Player>> player_list)
{
    for (auto &Entity : mEntities) {

        auto &enemy = gCoordinator.GetComponent<Enemy>(Entity);
        auto &transform = gCoordinator.GetComponent<Transform>(Entity);

        int posx = transform.Position.x;
        int posy = transform.Position.y;

        for (unsigned int i = 0; i < player_list.size(); i++)
            player_list[i]->do_write("212/" + std::to_string(1) + ":" + std::to_string(posx) + ":" + std::to_string(posy));
    }
}
/*
** EPITECH PROJECT, 2020
** B-CPP-501-MPL-5-1-rtype-balthazard.grego
** File description:
** ClientEnemyNetworkSystem
*/

#include "ClientEnemyNetworkSystem.hpp"

void ClientEnemyNetworkSystem::Update(Coordinator& gCoordinator, std::string res)
{
    std::istringstream iss(res);
    std::string result;
    sf::Vector2f enemyPos;
    int enemyNumber = -1;
    PF_BasicEnemyShape e;

    if( std::getline( iss, result , '/') ) {
        if (result == "213")
        {
            std::string token;
            int i = 0;
            while (std::getline(iss, token, ':'))
            {
                if (i == 0)
                    enemyNumber = atoi(token.data());
                else if (i == 1)
                    enemyPos.x = atoi(token.data());
                else if (i == 2)
                    enemyPos.y = atoi(token.data());
                i += 1;
            }
            std::cout << "creating enemy prefab" << std::endl;
            e.Create(gCoordinator, enemyPos);
        }
    }

    for (auto& Entity : mEntities) 
    {
        std::istringstream iss(res);
        std::string result;
        sf::Vector2f enemyPos;
        int enemyNumber = -1;
        PF_BasicEnemyShape e;
        auto& transform = gCoordinator.GetComponent<Transform>(Entity);
        auto& enemy = gCoordinator.GetComponent<Enemy>(Entity);

        if( std::getline( iss, result , '/') ) {
            if (result == "212")
            {
                std::string token;
                int i = 0;
                while (std::getline(iss, token, ':'))
                {
                    if (i == 0)
                        enemyNumber = atoi(token.data());
                    else if (i == 1)
                        enemyPos.x = atoi(token.data());
                    else if (i == 2)
                        enemyPos.y = atoi(token.data());
                    i += 1;
                }
            }
        }
    }
}
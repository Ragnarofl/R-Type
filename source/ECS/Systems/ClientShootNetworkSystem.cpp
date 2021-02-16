/*
** EPITECH PROJECT, 2020
** B-CPP-501-MPL-5-1-rtype-balthazard.grego
** File description:
** ClientShootNetworkSystem
*/

#include "ClientShootNetworkSystem.hpp"
#include "PF_Missile_Shape.hpp"

void ClientShootNetworkSystem::Update(Coordinator& gCoordinator, float dt, Network& networkInstance, std::string res)
{
    for (auto &entity : mEntities) 
    {
        // std::cout << "in inputSystem" << std::endl;
        auto &player = gCoordinator.GetComponent<PlayerComponent>(entity);
        auto &input = gCoordinator.GetComponent<Input>(entity);
        auto& transform = gCoordinator.GetComponent<Transform>(entity);

        std::istringstream iss( res );
        std::string result;
        int netPlayerNbr = -1;
        sf::Vector2f netPlayerPos = sf::Vector2f(0, 0);

        if( std::getline( iss, result , '/') ) {
            if( result == "206" )
            {
                std::string token;
                int i = 0;
                while( std::getline( iss, token, ':' ) )
                {
                    if (i == 0)
                        netPlayerNbr = atoi(token.data());
                    else if (i == 1)
                        netPlayerPos.x = atoi(token.data());
                    else if (i == 2)
                        netPlayerPos.y = atoi(token.data());
                    i += 1;
                }
                PF_Missile_Shape missile;
                missile.Create(gCoordinator, netPlayerNbr, netPlayerPos);
            }
            bool isKeyPressed = false;

            for (auto &CurrentKey : input.KeyList)
            {
                if (sf::Keyboard::isKeyPressed(CurrentKey) &&
                    (CurrentKey == sf::Keyboard::K))
                {
                    // transform.Velocity.x = player.moveSpeed;
                    player.hasShoot = true;
                    isKeyPressed = true;

                }
            }
        }
    }
}
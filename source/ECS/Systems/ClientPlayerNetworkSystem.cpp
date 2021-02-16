/*
** EPITECH PROJECT, 2020
** B-CPP-501-MPL-5-1-rtype-balthazard.grego
** File description:
** ClientPlayerNetworkSystem
*/

#include "ClientPlayerNetworkSystem.hpp"

void ClientPlayerNetworkSystem::Update(Coordinator& gCoordinator, std::string res)
{
    std::istringstream iss( res );
    std::string result;
    int netPlayerNbr = -1;
    sf::Vector2f netPlayerPos = sf::Vector2f(0, 0);
    PF_Enemies_Basic EnemiePF;
    
    if( std::getline( iss, result , '/') ) {
        if( result == "211" )
        {
            std::string token;
            if (std::getline( iss, token, '/' ))
            {
                netPlayerNbr = atoi(token.data());
                std::cout << "netPlayerNbr: " << netPlayerNbr << std::endl;
                    EnemiePF.Create(gCoordinator, netPlayerNbr,
                        std::vector<sf::Keyboard::Key>{
                            sf::Keyboard::Right, sf::Keyboard::Left, sf::Keyboard::Up, sf::Keyboard::Down, sf::Keyboard::K
                        }
                    );
            }
        }
        if( result == "202" )
        {
            std::string token;
            if (std::getline( iss, token, '/' ))
            {
                netPlayerNbr = atoi(token.data());
                std::cout << "netPlayerNbr: " << netPlayerNbr << std::endl;
                    EnemiePF.Create(gCoordinator, netPlayerNbr,
                        std::vector<sf::Keyboard::Key>{
                        }
                    );
            }
        }
        else spawned = false;
        for (auto& Entity : mEntities) {
            auto& transform = gCoordinator.GetComponent<Transform>(Entity);
            auto &player = gCoordinator.GetComponent<PlayerComponent>(Entity);
            std::istringstream iss( res );
            std::string result;
            int netPlayerNbr = -1;
            sf::Vector2f netPlayerPos = sf::Vector2f(0, 0);

            if( std::getline( iss, result , '/') ) {
                if( result == "205" )
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
                    if (player.playerNumber == netPlayerNbr)
                        transform.Position = netPlayerPos;
                }
            }
        }
    }
}
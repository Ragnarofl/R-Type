/*
** EPITECH PROJECT, 2020
** B-CPP-501-MPL-5-1-rtype-balthazard.grego
** File description:
** InputSystem
*/

#include "InputSystem.hpp"
#include "../Components/PlayerComponent.hpp"
#include "../Components/Transform.hpp"
#include "../Components/Input.hpp"
#include "../Components/Shapes.hpp"
#include "Coordinator.hpp"

void InputSystem::Update(Coordinator &gCoordinator, float dt, Network& networkInstance)
{
    for (auto &entity : mEntities) 
    {
        // std::cout << "in inputSystem" << std::endl;
        auto &player = gCoordinator.GetComponent<PlayerComponent>(entity);
        auto &transform = gCoordinator.GetComponent<Transform>(entity);
        auto &input = gCoordinator.GetComponent<Input>(entity);
        bool isKeyPressed = false;

        for (auto &CurrentKey : input.KeyList)
        {
            if (sf::Keyboard::isKeyPressed(CurrentKey) &&
                (CurrentKey == sf::Keyboard::D || CurrentKey == sf::Keyboard::Right || CurrentKey == sf::Keyboard::H))
            {
                // std::cout << "in right" << std::endl;
                // transform.Velocity.x = player.moveSpeed;
                transform.Position.x += player.moveSpeed * dt;
                isKeyPressed = true;
                // std::cout << "pos = " << transform.Position.x << std::endl;

            }

            else if (sf::Keyboard::isKeyPressed(CurrentKey) &&
                (CurrentKey == sf::Keyboard::A || CurrentKey == sf::Keyboard::Left || CurrentKey == sf::Keyboard::G))
            {
                // std::cout << "in left" << std::endl;
                // transform.Velocity.x = -player.moveSpeed;
                transform.Position.x -= player.moveSpeed * dt;
                isKeyPressed = true;
            }

            else if (sf::Keyboard::isKeyPressed(CurrentKey) &&
                (CurrentKey == sf::Keyboard::W || CurrentKey == sf::Keyboard::Up || CurrentKey == sf::Keyboard::Y))
            {
                // std::cout << "in up" << std::endl;
                // transform.Velocity.y = -player.moveSpeed;
                transform.Position.y -= player.moveSpeed * dt;
                isKeyPressed = true;
            }

            else if (sf::Keyboard::isKeyPressed(CurrentKey) &&
                (CurrentKey == sf::Keyboard::S || CurrentKey == sf::Keyboard::Down))
            {
                // std::cout << "in down" << std::endl;
                // transform.Velocity.y = player.moveSpeed;
                transform.Position.y += player.moveSpeed * dt;
                isKeyPressed = true;
            }
            else if (sf::Keyboard::isKeyPressed(CurrentKey) &&
                (CurrentKey == sf::Keyboard::K))
            {
                std::cout << "HAS SHOOT" << std::endl;
                // transform.Velocity.y = player.moveSpeed;
                player.hasShoot = true;
            }
        }
        //Network Sending data
        if (isKeyPressed) {
            networkInstance.send("105/" + std::to_string(player.playerNumber) + ":" + std::to_string((int)transform.Position.x) + ":" + std::to_string((int)transform.Position.y), sf::IpAddress("127.0.0.1"), 10010);
        }
    }
}
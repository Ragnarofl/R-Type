/*
** EPITECH PROJECT, 2020
** B-CPP-501-MPL-5-1-rtype-balthazard.grego
** File description:
** CollisionSystem
*/

#include "CollisionSystem.hpp"

void CollisionSystem::Update(Coordinator &gCoordinator)
{
    for (auto &entity : mEntities) 
    {
        auto &transform = gCoordinator.GetComponent<Transform>(entity);
        auto &collision = gCoordinator.GetComponent<CollisionComponent>(entity);
        auto &shape = gCoordinator.GetComponent<SFMLCircleShape>(entity);
        sf::Color initColor = shape.Body.getFillColor();
            for (auto &entityOther : mEntities) 
            {
                // if (entityOther != entity) {
                    auto &transformOther = gCoordinator.GetComponent<Transform>(entityOther);
                    auto &collisionOther = gCoordinator.GetComponent<CollisionComponent>(entityOther);
                    auto &shapeOther = gCoordinator.GetComponent<SFMLCircleShape>(entityOther);

                    if ((transform.Position.x < transformOther.Position.x + collisionOther.Size.x && transform.Position.x > transformOther.Position.x) &&
                        (transform.Position.y < transformOther.Position.y + collisionOther.Size.y && transform.Position.y > transformOther.Position.y)) {
                        // std::cout << "COLLIDE !" << std::endl;
                        shape.Body.setFillColor(sf::Color::White);
                        shapeOther.Body.setFillColor(sf::Color::White);
                        // std::cout << "Other: "<< transformOther.Position.x << std::endl << "Selected: " <<transform.Position.x << std::endl << std::endl;
                    }
                // }
            }
    }
}
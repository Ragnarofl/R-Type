/*
** EPITECH PROJECT, 2020
** B-CPP-501-MPL-5-1-rtype-balthazard.grego
** File description:
** PF_EnemyShape
*/

#ifndef PF_ENEMYSHAPE_HPP_
#define PF_ENEMYSHAPE_HPP_

#include "Coordinator.hpp"
#include "Transform.hpp"
#include "Enemy.hpp"
#include "Shapes.hpp"
#include "PhysicsComponent.hpp"
#include "CollisionComponent.hpp"

struct PF_BasicEnemyShape {
    sf::Vector2i Create(Coordinator &gCoordinator, sf::Vector2f pos);
};

inline sf::Vector2i PF_BasicEnemyShape::Create(Coordinator &gCoordinator, sf::Vector2f pos)
{
    // std::cout << "in create PF_BasicEnemyShape" << std::endl;
    std::vector<Entity> entities = std::vector<Entity>(1);
    Entity entity = gCoordinator.CreateEntity();

    float bodyRadius = 30.f;
    float LegsRadius = (8 * bodyRadius) / 10;
    float HeadRadius = (2 * bodyRadius) / 10;

    sf::CircleShape headCircle;
    sf::CircleShape bodyTriangle(80, TRIANGLE_SHAPE + 3);
    sf::CircleShape LegsCircle(80, TRIANGLE_SHAPE + 3);

    bodyTriangle.setRadius(bodyRadius);
    bodyTriangle.setFillColor(sf::Color::Red);
    bodyTriangle.setOutlineColor(sf::Color::Black);
    bodyTriangle.setOutlineThickness(1.f);
    headCircle.setRadius(HeadRadius);
    headCircle.setFillColor(sf::Color::Black);
    LegsCircle.setRadius(LegsRadius);
    LegsCircle.setFillColor(sf::Color::Red);

    gCoordinator.AddComponent(
        entity,
        Transform {
            .Position = pos,
            .Rotation = 90.f        
        }
    );
    gCoordinator.AddComponent(
        entity,
        SFMLCircleShape {
            .Body = bodyTriangle,
            .Head = headCircle,
            .Legs = LegsCircle,
            .HeadOffset = sf::Vector2f(-(bodyTriangle.getRadius() - headCircle.getRadius()) + bodyTriangle.getGlobalBounds().width / 3, bodyTriangle.getRadius() - headCircle.getRadius()),
            .BodyOffset = sf::Vector2f(0.f, 0.f),
            .LegOffset = sf::Vector2f(-(bodyTriangle.getRadius() - LegsCircle.getRadius()), bodyTriangle.getRadius() - LegsCircle.getRadius())
        }
    );
    gCoordinator.AddComponent(
        entity,
        Enemy {
            .health = 100,
            .totalHealth = 100,
            .type = 1,
            .alive = true
            // .enemyNumber = enemyNumber
        }
    );
    gCoordinator.AddComponent(
        entity,
        Physics {
            .Velocity = sf::Vector2f(- (rand() % 1000 + 100), 0.f),
        }
    );
    gCoordinator.AddComponent(
        entity,
        CollisionComponent {
            .Size = sf::Vector2f(bodyTriangle.getGlobalBounds().width, bodyTriangle.getGlobalBounds().height + 55),
            .Filter = CollisionFillter::ENEMY
        }
    );
    return (sf::Vector2i(pos.x, pos.y));
    // for (unsigned int i = 0; i < player_list.size(); i++)
    //     player_list[i]->do_write("213/" + std::to_string(1));
}

#endif /* !PF_ENEMYSHAPE_HPP_ */

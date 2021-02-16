/*
** EPITECH PROJECT, 2020
** B-CPP-501-MPL-5-1-rtype-balthazard.grego
** File description:
** PF_Missile_Shape
*/

#ifndef PF_MISSILE_SHAPE_HPP_
#define PF_MISSILE_SHAPE_HPP_

#include "Coordinator.hpp"
#include "Transform.hpp"
#include "ShootComponent.hpp"
#include "PhysicsComponent.hpp"
#include "CollisionComponent.hpp"
#include "Shapes.hpp"

struct PF_Missile_Shape {
    void Create(Coordinator& gCoordinator, int playerNumber, sf::Vector2f playerPos);
};

inline void PF_Missile_Shape::Create(Coordinator& gCoordinator, int playerNumber, sf::Vector2f playerPos)
{
    std::vector<Entity> entities = std::vector<Entity>(1);

    float bodyRadius = 35.f;
    float LegsRadius = (8 * bodyRadius) / 10; // Leg Shape is 80% of main body
    float HeadRadius = (2 * bodyRadius) / 10; // Head Shape is 20% of main body

    sf::Color color [] = {sf::Color::Blue, sf::Color::Red, sf::Color::Yellow, sf::Color::Green};

    Entity entity = gCoordinator.CreateEntity();
    sf::CircleShape bodyTriangle;
    sf::CircleShape headCircle;
    sf::CircleShape LegsCircle;
        
    bodyTriangle.setRadius(bodyRadius);
    bodyTriangle.setFillColor(sf::Color::Black);
    bodyTriangle.setOutlineColor(color[playerNumber]);
    bodyTriangle.setOutlineThickness(2.f);
    headCircle.setRadius(HeadRadius);
    headCircle.setFillColor(sf::Color::Black);
    LegsCircle.setRadius(LegsRadius);
    LegsCircle.setFillColor(color[playerNumber]);

    gCoordinator.AddComponent(
        entity,
        Transform{
            .Position = playerPos,
            .Rotation = 90.f
        });
    gCoordinator.AddComponent(
        entity,
        SFMLCircleShape{
            .Body = bodyTriangle,
            .Head = headCircle,
            .Legs = LegsCircle,
            .HeadOffset = sf::Vector2f(-(bodyTriangle.getRadius() - headCircle.getRadius()) + bodyTriangle.getGlobalBounds().width / 3, bodyTriangle.getRadius() - headCircle.getRadius()),
            .BodyOffset = sf::Vector2f(0.f, 0.f),
            .LegOffset = sf::Vector2f(-(bodyTriangle.getRadius() - LegsCircle.getRadius()), bodyTriangle.getRadius() - LegsCircle.getRadius()),
        });
        gCoordinator.AddComponent(
			entity,
			ShootComponent {
			});
        gCoordinator.AddComponent(
            entity,
            Input { 
                .KeyList = std::vector<sf::Keyboard::Key>{
		                    sf::Keyboard::K
	                    }
            }); 
        gCoordinator.AddComponent(
            entity,
            Physics {
                .Velocity = sf::Vector2f(2000.f, 0.f),
            });
        gCoordinator.AddComponent(
            entity,
            CollisionComponent {
                .Size = sf::Vector2f(bodyTriangle.getGlobalBounds().width, bodyTriangle.getGlobalBounds().height + 55),
                .Filter = CollisionFillter::BULLET,
            });
}

#endif /* !PF_MISSILE_SHAPE_HPP_ */

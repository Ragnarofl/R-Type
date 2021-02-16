/*
** EPITECH PROJECT, 2020
** B-CPP-501-MPL-5-1-rtype-balthazard.grego
** File description:
** PF_Enemies_Basic
*/

#ifndef PF_ENEMIES_BASIC_HPP_
#define PF_ENEMIES_BASIC_HPP_

#include "Coordinator.hpp"
#include "Sprite.hpp"
#include "Transform.hpp"
#include "PlayerComponent.hpp"
#include "Input.hpp"
#include "PhysicsComponent.hpp"
#include "CollisionComponent.hpp"
#include "Shapes.hpp"
#include "Animation.hpp"

struct PF_Enemies_Basic {
    void Create(Coordinator& gCoordinator, int playerNumber, std::vector<sf::Keyboard::Key> KeyList);
};

inline void PF_Enemies_Basic::Create(Coordinator& gCoordinator, int playerNumber, std::vector<sf::Keyboard::Key> KeyList)
{
    std::vector<Entity> entities = std::vector<Entity>(1);

    float bodyRadius = 75.f;
    float LegsRadius = (8 * bodyRadius) / 10; // Leg Shape is 80% of main body
    float HeadRadius = (2 * bodyRadius) / 10; // Head Shape is 20% of main body
    // std::string playerPort = std::to_string(playerNumber)
    sf::Vector2f headOffset = sf::Vector2f(-20, 0);
    sf::Color color [] = {sf::Color::Blue, sf::Color::Red, sf::Color::Yellow, sf::Color::Green};
    sf::Texture *texture = new sf::Texture;
    sf::Sprite *sprite = new sf::Sprite;
    sf::IntRect rect(0,0,33,36);

    texture->loadFromFile("../../Assets/r-typesheet5.png");
    sprite->setTexture(*texture);
    sprite->setTextureRect(rect);

    Entity entity = gCoordinator.CreateEntity();
    sf::CircleShape bodyTriangle(80, TRIANGLE_SHAPE + playerNumber);
    sf::CircleShape headCircle;
    sf::CircleShape LegsCircle(80, TRIANGLE_SHAPE + playerNumber);
        
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
            .Position = sf::Vector2f(0.f, 0 + (250.f * playerNumber)),
            .Rotation = 90.f
        });
    gCoordinator.AddComponent(
        entity,
        SFMLCircleShape{
            .Body = bodyTriangle,
            .Head = headCircle,
            .Legs = LegsCircle,
            .HeadOffset = sf::Vector2f(-(bodyTriangle.getRadius() - headCircle.getRadius()) + bodyTriangle.getGlobalBounds().width / 3, bodyTriangle.getRadius() - headCircle.getRadius() - headOffset.y),
            .BodyOffset = sf::Vector2f(0.f, 0.f),
            .LegOffset = sf::Vector2f(-(bodyTriangle.getRadius() - LegsCircle.getRadius()), bodyTriangle.getRadius() - LegsCircle.getRadius()),
        });
        gCoordinator.AddComponent(
			entity,
			PlayerComponent {
                .health = 100,
                .totalHealth = 100,
                .moveSpeed = 600.0f,
                .shootSpeed = 10.0f,
                .alive = true,
                .playerNumber = playerNumber
			});
        gCoordinator.AddComponent(
            entity,
            Input { 
                .KeyList = KeyList
            });
        gCoordinator.AddComponent(
            entity,
            Physics {
                .Velocity = sf::Vector2f(500.f, 0.f),
            });
        gCoordinator.AddComponent(
            entity,
            CollisionComponent {
                .Size = sf::Vector2f(bodyTriangle.getGlobalBounds().width, bodyTriangle.getGlobalBounds().height + 55),
                .Filter = CollisionFillter::PLAYER,
            });
        gCoordinator.AddComponent(
            entity,
            Sprite {
                .texture = texture,
                .sprite = sprite,
            });
        gCoordinator.AddComponent(
            entity,
            Animation {
                .rect = rect,
                .sizeAllFrames = 533,
                .sizeOneFrame = 33,
                .holdTime = 0.5
            }
        );
}

#endif /* !PF_ENEMIES_BASIC_HPP_ */
/*
** EPITECH PROJECT, 2020
** B-CPP-501-MPL-5-1-rtype-balthazard.grego
** File description:
** PF_FirstBoss
*/

#ifndef PF_FIRSTBOSS_HPP_
#define PF_FIRSTBOSS_HPP_

#include "Coordinator.hpp"
#include "Transform.hpp"
#include "Enemy.hpp"
#include "Sprite.hpp"
#include "Animation.hpp"

struct PF_FirstBoss {
    void Create(Coordinator& gCoorinator);
};

inline void PF_FirstBoss::Create(Coordinator &gCoordinator)
{
    std::vector<Entity> entities = std::vector<Entity>(1);
    Entity entity = gCoordinator.CreateEntity();

    sf::Texture *texture = new sf::Texture;
    sf::Sprite *sprite = new sf::Sprite;
    sf::IntRect rect(0, 0, 141, 256);
    // sf::IntRect rect(0, 0, 33, 36);

    texture->loadFromFile("/home/yann/Documents/Epitech/tek3/rtype/B-CPP-501-MPL-5-1-rtype-balthazard.grego/Assets/firstboss.png");
    // texture->loadFromFile("/home/yann/Documents/Epitech/tek3/rtype/B-CPP-501-MPL-5-1-rtype-balthazard.grego/source/assets/r-typesheet5.png");

    sprite->setTexture(*texture);
    sprite->setTextureRect(rect);

    gCoordinator.AddComponent(
        entity,
        Transform {
            .Position = sf::Vector2f(300, 300),
            .Rotation = 0.f
        }
    );
    gCoordinator.AddComponent(
        entity,
        Sprite {
            .texture = texture,
            .sprite = sprite,
        }
    );
    gCoordinator.AddComponent(
        entity,
        Enemy {
            .health = 100,
            .totalHealth = 100,
            .alive = true
        }
    );
    gCoordinator.AddComponent(
        entity,
        Animation {
            .rect = rect,
            .sizeAllFrames = 995 - 141, //533-33,
            .sizeOneFrame = 141, //33
            .holdTime = 0.5
        }
    );
}

#endif /* !PF_FIRSTBOSS_HPP_ */
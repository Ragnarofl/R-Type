/*
** EPITECH PROJECT, 2020
** B-CPP-501-MPL-5-1-rtype-balthazard.grego
** File description:
** SpriteRenderSystem
*/

#include "SpriteRenderSystem.hpp"

void SpriteRenderSystem::Update(Coordinator& gCoordinator)
{
    for (auto& Entity : mEntities) {
        auto& sprite = gCoordinator.GetComponent<Sprite>(Entity);
        auto& transform = gCoordinator.GetComponent<Transform>(Entity);
        
        sprite.sprite->setPosition(transform.Position);
        sprite.sprite->setRotation(transform.Rotation);
    }
}

void SpriteRenderSystem::Draw(Coordinator& gCoordinator, sf::RenderWindow& Window)
{
    for (auto& Entity : mEntities) {
        auto& sprite = gCoordinator.GetComponent<Sprite>(Entity);

        Window.draw(*(sprite.sprite));
    }
}

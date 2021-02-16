/*
** EPITECH PROJECT, 2020
** B-CPP-501-MPL-5-1-rtype-balthazard.grego
** File description:
** RenderSystem
*/

#include "ShapeRenderSystem.hpp"
#include "PF_Enemies_Basic.hpp"

void ShapeRenderSystem::Update(Coordinator& gCoordinator, std::string res)
{
    for (auto& Entity : mEntities) {
        auto& shape = gCoordinator.GetComponent<SFMLCircleShape>(Entity);
        auto& transform = gCoordinator.GetComponent<Transform>(Entity);
        // auto &player = gCoordinator.GetComponent<PlayerComponent>(Entity);

        shape.Head.setPosition(transform.Position + shape.HeadOffset);
        shape.Head.setRotation(transform.Rotation);
        shape.Body.setPosition(transform.Position + shape.BodyOffset);
        shape.Body.setRotation(transform.Rotation);
        shape.Legs.setPosition(transform.Position + shape.LegOffset);
        shape.Legs.setRotation(transform.Rotation);
    }
}

void ShapeRenderSystem::Draw(Coordinator& gCoordinator, sf::RenderWindow& Window)
{
    for (auto& Entity : mEntities) {
        auto& shape = gCoordinator.GetComponent<SFMLCircleShape>(Entity);

        Window.draw(shape.Body);
        Window.draw(shape.Legs);
        Window.draw(shape.Head);
    }
}
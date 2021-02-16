/*
** EPITECH PROJECT, 2020
** B-CPP-501-MPL-5-1-rtype-balthazard.grego
** File description:
** SpriteRenderSystem
*/

#ifndef SPRITERENDERSYSTEM_HPP_
#define SPRITERENDERSYSTEM_HPP_

#include "Coordinator.hpp"
#include "Transform.hpp"
#include "Sprite.hpp"
#include "PlayerComponent.hpp"

class SpriteRenderSystem : public System {
    public:
        void Update(Coordinator& gCoordinator);
        void Draw(Coordinator& gCoordinator, sf::RenderWindow& Window);
    protected:
    private:
};

#endif /* !SPRITERENDERSYSTEM_HPP_ */

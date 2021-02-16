/*
** EPITECH PROJECT, 2020
** B-CPP-501-MPL-5-1-rtype-balthazard.grego
** File description:
** RenderSystem
*/

#ifndef SHAPERENDERSYSTEM_HPP_
#define SHAPERENDERSYSTEM_HPP_

#include "Coordinator.hpp"
#include "Shapes.hpp"
#include "Transform.hpp"
#include "PlayerComponent.hpp"
// #include "PF_Enemies_Basic.hpp"

class ShapeRenderSystem : public System {
    public:
        void Update(Coordinator& gCoordinator, std::string res);
        void Draw(Coordinator& gCoordinator, sf::RenderWindow& Window);
    protected:
    private:
        bool spawned = false;
};

#endif /* !SHAPERENDERSYSTEM_HPP_ */

/*
** EPITECH PROJECT, 2020
** B-CPP-501-MPL-5-1-rtype-balthazard.grego
** File description:
** PhysicSystem
*/

#ifndef PHYSICSSYSTEM_HPP_
#define PHYSICSSYSTEM_HPP_

#include "Coordinator.hpp"
#include "Transform.hpp"
#include "PhysicsComponent.hpp"
#include "CollisionComponent.hpp"

class PhysicsSystem : public System {
    public:
        void Update(Coordinator& gCoordinator, float DeltaTime);

    protected:
    private:
};

#endif /* !PHYSICSSYSTEM_HPP_ */

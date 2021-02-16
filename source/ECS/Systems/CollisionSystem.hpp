/*
** EPITECH PROJECT, 2020
** B-CPP-501-MPL-5-1-rtype-balthazard.grego
** File description:
** CollisionSystem
*/

#ifndef COLLISIONSYSTEM_HPP_
#define COLLISIONSYSTEM_HPP_

#include "Coordinator.hpp"
#include "CollisionComponent.hpp"
#include "Transform.hpp"
#include "Shapes.hpp"

class CollisionSystem : public System {
    public:
        void Update(Coordinator &gCoordinator);

    protected:
    private:
};

#endif /* !COLLISIONSYSTEM_HPP_ */

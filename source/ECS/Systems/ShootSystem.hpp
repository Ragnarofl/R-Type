/*
** EPITECH PROJECT, 2020
** B-CPP-501-MPL-5-1-rtype-balthazard.grego
** File description:
** ShootSystem
*/

#ifndef SHOOTSYSTEM_HPP_
#define SHOOTSYSTEM_HPP_

#include "Coordinator.hpp"
#include "Shapes.hpp"
#include "Transform.hpp"
#include "PlayerComponent.hpp"
#include "Input.hpp"
#include "ShootComponent.hpp"

class ShootSystem : public System {
    public:
        void Update(Coordinator& gCoordinator, Network& networkInstance);

    protected:
    private:
};

#endif /* !SHOOTSYSTEM_HPP_ */

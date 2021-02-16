/*
** EPITECH PROJECT, 2020
** B-CPP-501-MPL-5-1-rtype-balthazard.grego
** File description:
** InputSystem
*/

#ifndef INPUTSYSTEM_HPP_
#define INPUTSYSTEM_HPP_

#include "System.hpp"
#include "Coordinator.hpp"

class InputSystem : public System
{
    public:
        void Update(Coordinator &gCoordinator, float dt, Network& networkInstance);
};

#endif /* !INPUTSYSTEM_HPP_ */

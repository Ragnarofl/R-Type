/*
** EPITECH PROJECT, 2020
** B-CPP-501-MPL-5-1-rtype-balthazard.grego
** File description:
** AnimationSystem
*/

#ifndef ANIMATIONSYSTEM_HPP_
#define ANIMATIONSYSTEM_HPP_

#include "System.hpp"
#include "Coordinator.hpp"

class AnimationSystem : public System
{
    public:
        void Update(Coordinator &gCoordinateur, float dt);
};

#endif /* !ANIMATIONSYSTEM_HPP_ */

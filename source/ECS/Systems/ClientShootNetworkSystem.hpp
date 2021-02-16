/*
** EPITECH PROJECT, 2020
** B-CPP-501-MPL-5-1-rtype-balthazard.grego
** File description:
** ClientShootNetworkSystem
*/

#ifndef CLIENTSHOOTNETWORKSYSTEM_HPP_
#define CLIENTSHOOTNETWORKSYSTEM_HPP_

#include "Coordinator.hpp"
#include "Shapes.hpp"
#include "Transform.hpp"
#include "PlayerComponent.hpp"
#include "Input.hpp"

class ClientShootNetworkSystem : public System {
    public:
        void Update(Coordinator& gCoordinator, float dt, Network& networkInstance, std::string res);

    protected:
    private:
};

#endif /* !CLIENTSHOOTNETWORKSYSTEM_HPP_ */

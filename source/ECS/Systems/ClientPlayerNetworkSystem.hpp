/*
** EPITECH PROJECT, 2020
** B-CPP-501-MPL-5-1-rtype-balthazard.grego
** File description:
** ClientPlayerNetworkSystem
*/

#ifndef CLIENTPLAYERNETWORKSYSTEM_HPP_
#define CLIENTPLAYERNETWORKSYSTEM_HPP_

#include "Coordinator.hpp"
#include "Transform.hpp"
#include "Sprite.hpp"
#include "Player.hpp"
#include "PF_Enemies_Basic.hpp"

class ClientPlayerNetworkSystem : public System {
    public:
        void Update(Coordinator& gCoordinator, std::string res);

    protected:
    private:
        bool spawned = false;
};

#endif /* !CLIENTPLAYERNETWORKSYSTEM_HPP_ */

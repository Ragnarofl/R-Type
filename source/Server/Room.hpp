/*
** EPITECH PROJECT, 2020
** Room
** File description:
** Room
*/

#ifndef __ROOM__
#define __ROOM__

#include "CollisionSystem.hpp"
#include "PhysicsSystem.hpp"
#include "EnemyNetworkSystem.hpp"
#include "PF_BasicEnemyShape.hpp"
#include "PlayerComponent.hpp"
#include "Player.hpp"
#include <thread>

class Room : public std::enable_shared_from_this<Room> {
    private:
        std::vector<std::shared_ptr<Player>> _player_list;
        std::mutex _m;
        std::unique_lock<std::mutex> _glock;
        Coordinator _gCoordinator;
        sf::Clock _clock;
        sf::Time _deltaTime;
        float _elapsed;
        float _frameRate;
        std::vector<PF_BasicEnemyShape> _enemyList;

    public:
        Room(std::shared_ptr<Player> owner);
        ~Room();
        void run();
        void start();
        void add_new_player(std::shared_ptr<Player> player);
        void remove_player(udp::endpoint address);
        int get_player_position(udp::endpoint address) const;
        void do_write();
        int get_player_count() const;
};

#endif /**/
/*
** EPITECH PROJECT, 2020
** Room
** File description:
** Room
*/

#include "Room.hpp"

Room::Room(std::shared_ptr<Player> owner) : _glock(_m, std::defer_lock)
{
    _player_list.push_back(owner);
    owner->set_position(_player_list.size() - 1);
}

Room::~Room() {}

void Room::run()
{
    _gCoordinator.Init();
    _gCoordinator.RegisterComponent<Transform>();
    _gCoordinator.RegisterComponent<PlayerComponent>();
    _gCoordinator.RegisterComponent<Enemy>();
    _gCoordinator.RegisterComponent<Physics>();
	_gCoordinator.RegisterComponent<CollisionComponent>();
	_gCoordinator.RegisterComponent<SFMLCircleShape>();


    auto physicsSystem = _gCoordinator.RegisterSystem<PhysicsSystem>();
    {
        Signature signature;
        signature.set(_gCoordinator.GetComponentType<Transform>());
        signature.set(_gCoordinator.GetComponentType<Physics>());
        signature.set(_gCoordinator.GetComponentType<CollisionComponent>());
        _gCoordinator.SetSystemSignature<PhysicsSystem>(signature);  
    }
    auto collisionSystem = _gCoordinator.RegisterSystem<CollisionSystem>();
    {
        Signature signature;
        signature.set(_gCoordinator.GetComponentType<Transform>());
        signature.set(_gCoordinator.GetComponentType<CollisionComponent>());
        signature.set(_gCoordinator.GetComponentType<SFMLCircleShape>());
        _gCoordinator.SetSystemSignature<PhysicsSystem>(signature);
    }

    auto enemyNetworkSystem = _gCoordinator.RegisterSystem<EnemyNetworkSystem>();
    {
        Signature signature;
        signature.set(_gCoordinator.GetComponentType<Enemy>());
        signature.set(_gCoordinator.GetComponentType<Transform>());
        _gCoordinator.SetSystemSignature<EnemyNetworkSystem>(signature);
    }

    PF_BasicEnemyShape enemy;

    // enemy.Create(_gCoordinator);
    //     for (unsigned int i = 0; i < _player_list.size(); i++)
    //         _player_list[i]->do_write("213/" + std::to_string(1));

    while (1) {
        _deltaTime = _clock.restart();
        _elapsed += _deltaTime.asSeconds();
        _frameRate += _deltaTime.asSeconds();
        if (_frameRate >= (1 / 30)) {
            collisionSystem->Update(_gCoordinator);
            physicsSystem->Update(_gCoordinator, _deltaTime.asSeconds());
            // enemyNetworkSystem->Update(_gCoordinator, _player_list);
            _frameRate -= (1 / 30);
        }

        if (_elapsed >= 2) {
            sf::Vector2f pos = sf::Vector2f(1920, (rand() % 1000 + 50));
            sf::Vector2i ret;
            ret = enemy.Create(_gCoordinator, pos);
            for (unsigned int i = 0; i < _player_list.size(); i++)
                _player_list[i]->do_write("213/" + std::to_string(1) + ":" + std::to_string(ret.x) + ":" + std::to_string(ret.y));
            _elapsed -= 2;
        }
        if (_glock.owns_lock())
            continue;
        for (unsigned int i = 0; i < _player_list.size(); i++) {
            if (!_player_list[i])
                continue;
            std::string tmp = _player_list[i]->pop_first_data();
            if (!tmp.empty()) {
                // std::cout << "Room Size: " << _player_list.size() << std::endl;
                // std::cout << "Popped : " << tmp << std::endl;
                for (unsigned int j = 0; j < _player_list.size(); j++) {
                    // std::cout << "Second for loop: " << j << std::endl;
                    if (j != i) {
                        _player_list[j]->do_write(tmp);
                        // std::cout << "Message sent." << std::endl;
                    }
                }
            }
        }
    }
}

void Room::start()
{
    std::thread thread(&Room::run, this);
    thread.detach();
}

void Room::add_new_player(std::shared_ptr<Player> player)
{
    std::lock_guard<decltype(_glock)> g(_glock);
    for (unsigned int i = 0; i < _player_list.size(); i++)
        if (_player_list[i] == 0) {
            _player_list[i] = player;
            player->set_position(_player_list.size() - 1);
            std::cout << "Player added." << std::endl;
            for (unsigned int j = 0; j < _player_list.size(); j++)
                if (j != i)
                   player->do_write("202/" + std::to_string(j));
            return;
        }
    _player_list.push_back(player);
    player->set_position(_player_list.size() - 1);
    for (unsigned int j = 0; j < _player_list.size(); j++)
        if (j != player->get_position())
                player->do_write("202/" + std::to_string(j));
    std::cout << "Player added." << std::endl;
}

void Room::remove_player(udp::endpoint address)
{
    std::lock_guard<decltype(_glock)> g(_glock);
    std::string send("203/");
    int player_nb = 0;
    for (unsigned int i = 0; i < _player_list.size(); i++)
        if (_player_list[i]->get_endpoint() == address) {
            _player_list[i] = 0;
            player_nb = i + 1;
        }
    send += std::to_string(player_nb);
    for (unsigned int i = 0; i < _player_list.size(); i++)
        if (_player_list[i])
            _player_list[i]->do_write(send);
    std::cout << "Player removed." << std::endl;
}

int Room::get_player_position(udp::endpoint address) const
{
    for (unsigned int i = 0; i < _player_list.size(); i++)
        if (_player_list[i]->get_endpoint() == address) {
            return i;
        }
    return 0;
}

void Room::do_write()
{
    auto self(shared_from_this());
}

int Room::get_player_count() const
{
    return _player_list.size();
}
/*
** EPITECH PROJECT, 2020
** B-CPP-501-MPL-5-1-rtype-balthazard.grego
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

struct PlayerComponent
{
    int health;
    int totalHealth;
    float moveSpeed;
    float shootSpeed;
    bool alive;
    int playerNumber;
    bool hasShoot = false;
};

#endif /* !PLAYER_HPP_ */
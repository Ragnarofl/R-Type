/*
** EPITECH PROJECT, 2020
** B-CPP-501-MPL-5-1-rtype-balthazard.grego
** File description:
** CollisionComponent
*/

#ifndef COLLISIONCOMPONENT_HPP_
#define COLLISIONCOMPONENT_HPP_

#include <SFML/System.hpp>

enum CollisionFillter {
	STATIC = 0x0001,
	ENEMY = 0x0002,
	PLAYER = 0x0004,
	BULLET = 0x0006
};

struct CollisionComponent
{
	sf::Vector2f Size{};
    CollisionFillter Filter{};
};

#endif /* !COLLISIONCOMPONENT_HPP_ */

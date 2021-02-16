/*
** EPITECH PROJECT, 2020
** B-CPP-501-MPL-5-1-rtype-balthazard.grego
** File description:
** Shapes
*/

#ifndef SHAPES_HPP_
#define SHAPES_HPP_

#include <SFML/Graphics.hpp>

#define TRIANGLE_SHAPE 3
#define SQUARE_SHAPE 4
#define LINE_SHAPE 3

struct SFMLCircleShape
{
	sf::CircleShape Body{};
	sf::CircleShape Head{};
	sf::CircleShape Legs{};
	sf::Vector2f HeadOffset = sf::Vector2f(0.f, 0.f);
    sf::Vector2f BodyOffset = sf::Vector2f(0.f, 0.f);
    sf::Vector2f LegOffset = sf::Vector2f(0.f, 0.f);
};

#endif /* !SHAPES_HPP_ */

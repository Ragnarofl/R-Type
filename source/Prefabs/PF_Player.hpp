/*
** EPITECH PROJECT, 2020
** B-CPP-501-MPL-5-1-rtype-balthazard.grego
** File description:
** PF_Player
*/

#ifndef PF_PLAYER_HPP_
#define PF_PLAYER_HPP_

#include "Coordinator.hpp"
#include "PlayerComponent.hpp"
#include "Input.hpp"
#include "Sprite.hpp"
#include "Transform.hpp"
#include "Animation.hpp"

struct PF_Player {
    void Create(Coordinator &gCoordinator);
};

inline void PF_Player::Create(Coordinator &gCoordinator)
{
    std::vector<Entity> entities(1);
    
    //sprite creation
    sf::Texture *texture = new sf::Texture;
    sf::Sprite *sprite = new sf::Sprite;
    sf::IntRect rect(0, 0, 33, 36);
    // texture->loadFromFile("/home/yann/Documents/Epitech/tek3/rtype/B-CPP-501-MPL-5-1-rtype-balthazard.grego/source/assets/Biomech Dragon Cannon.png");
    texture->loadFromFile("/home/balthazard/Desktop/EPI3/CPP/RType/B-CPP-501-MPL-5-1-rtype-balthazard.grego/source/assets/r-typesheet5.png");
    sprite->setTexture(*texture);

    for (auto &entity : entities)
    {
        entity = gCoordinator.CreateEntity();
		gCoordinator.AddComponent(
			entity,
			Transform{
				.Position = sf::Vector2f((0, 0), (500.f)),
                .Rotation = 0.f
			});
        gCoordinator.AddComponent(
            entity, 
            PlayerComponent {
                .health = 100,
                .totalHealth = 100,
                .moveSpeed = 100.0f,
                .shootSpeed = 10.0f,
                .alive = true,
                .playerNumber = 1
            });
        gCoordinator.AddComponent(
            entity,
            Sprite {
                .texture = texture,
                .sprite = sprite
            });
        gCoordinator.AddComponent(
            entity,
            Input { .KeyList = std::vector<sf::Keyboard::Key>{
		        sf::Keyboard::Right, sf::Keyboard::Left, sf::Keyboard::Up, sf::Keyboard::Right
	            }
            });
        gCoordinator.AddComponent(
            entity,
            Animation {
                .rect = rect,
                .sizeAllFrames = 533,
                .sizeOneFrame = 33
            });
    }
}

#endif /* !PF_PLAYER_HPP_ */

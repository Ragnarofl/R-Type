/*
** EPITECH PROJECT, 2020
** B-CPP-501-MPL-5-1-rtype-balthazard.grego
** File description:
** AnimationSystem
*/

#include "AnimationSystem.hpp"
#include "../Components/Animation.hpp"
#include "../Components/Sprite.hpp"

void AnimationSystem::Update(Coordinator &gCoordinator, float dt)
{
    static float elapsed;
    elapsed += dt;

    for (auto &entity : mEntities)
    {
        auto &animation = gCoordinator.GetComponent<Animation>(entity);
        auto &sprite = gCoordinator.GetComponent<Sprite>(entity);

        if (elapsed >= animation.holdTime)
        {
            if (animation.rect.left >= animation.sizeAllFrames)
            {
                animation.rect.left = 0;
            }
            else {
                animation.rect.left += animation.sizeOneFrame;
            }
            elapsed = 0;
            sprite.sprite->setTextureRect(animation.rect);
        }
    }
}
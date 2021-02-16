/*
** EPITECH PROJECT, 2020
** B-CPP-501-MPL-5-1-rtype-balthazard.grego
** File description:
** Coordinator
*/

#include "Coordinator.hpp"

void Coordinator::Init()
{
    // Create pointers to each manager
    mComponentManager = std::make_unique<ComponentManager>();
    mEntityManager = std::make_unique<EntityManager>();
    mSystemManager = std::make_unique<SystemManager>(); 
}

Entity Coordinator::CreateEntity()
{
    return mEntityManager->CreateEntity(); 
}

void Coordinator::DestroyEntity(Entity entity)
{
    mEntityManager->DestroyEntity(entity);

    mComponentManager->EntityDestroyed(entity);

    mSystemManager->EntityDestroyed(entity); 
}
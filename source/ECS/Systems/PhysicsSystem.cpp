/*
** EPITECH PROJECT, 2020
** B-CPP-501-MPL-5-1-rtype-balthazard.grego
** File description:
** PhysicsSystem
*/

#include "PhysicsSystem.hpp"

void PhysicsSystem::Update(Coordinator& gCoordinator, float DeltaTime)
{
    for (auto& Entity : mEntities) {
        auto& transform = gCoordinator.GetComponent<Transform>(Entity);
        auto& physics = gCoordinator.GetComponent<Physics>(Entity);
        auto& collision = gCoordinator.GetComponent<CollisionComponent>(Entity);
		// The affects of gravity should only activate if the entity is dynamic.
		// if(Collision.Type == _CollisionType::DYNAMIC)
		// The velocity.x is pushed left by Drag and Friction
		physics.Velocity.x -= DeltaTime * physics.Velocity.x;
		transform.Position.x += DeltaTime * physics.Velocity.x;
		physics.Velocity.y -= DeltaTime * physics.Velocity.y;
		transform.Position.y += DeltaTime * physics.Velocity.y;
		// std::cout << transform.Velocity.x << std::endl;

		// These restrict any movement to the regions inside the boxes and the screen.
		//Top
		if (transform.Position.y < 0) transform.Position.y = 0;
		//Bottom
		if (transform.Position.y > 1080 - collision.Size.y) transform.Position.y = 1080 - collision.Size.y;
	}
}

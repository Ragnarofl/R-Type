/*
** EPITECH PROJECT, 2020
** B-CPP-501-MPL-5-1-rtype-balthazard.grego
** File description:
** EntityManager
*/

#ifndef ENTITYMANAGER_HPP_
#define ENTITYMANAGER_HPP_

#include <cstdint>
#include <iostream>
#include <array>
#include <queue>
#include <assert.h>
#include <bitset>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>

// A simple type alias
using Entity = std::uint32_t;

// Used to define the size of arrays later on
const Entity MAX_ENTITIES = 5000;

// A simple type alias
using ComponentType = std::uint8_t;

// Used to define the size of arrays later on
const ComponentType MAX_COMPONENTS = 32;

// A simple type alias
using Signature = std::bitset<MAX_COMPONENTS>;

class EntityManager 
{
	public:
		EntityManager();
		~EntityManager();

		Entity CreateEntity();
		void DestroyEntity(Entity entity);
		void SetSignature(Entity entity, Signature signature);
		const Signature GetSignature(Entity entity) const;
		

	private:
		// Queue of unused entity IDs
		std::queue<Entity> mAvailableEntities{};

		// Array of signatures where the index corresponds to the entity ID
		std::array<Signature, MAX_ENTITIES> mSignatures{};

		// Total living entities - used to keep limits on how many exist
		uint32_t mLivingEntityCount{};
};

#endif /* !ENTITYMANAGER_HPP_ */

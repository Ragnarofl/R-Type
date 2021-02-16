/*
** EPITECH PROJECT, 2020
** B-CPP-501-MPL-5-1-rtype-balthazard.grego
** File description:
** SystemManager
*/

#ifndef SYSTEMMANAGER_HPP_
#define SYSTEMMANAGER_HPP_

#include <memory>
#include <unordered_map>
#include "System.hpp"
#include "EntityManager.hpp"

class SystemManager
{
    public:
        template<typename T>
        std::shared_ptr<T> RegisterSystem()
        {
            const char* typeName = typeid(T).name();

            assert(mSystems.find(typeName) == mSystems.end() && "Registering system more than once.");

            // Create a pointer to the system and return it so it can be used externally
            auto system = std::make_shared<T>();
            mSystems.insert({typeName, system});
            return system;
        }

        template<typename T>
        void SetSignature(Signature signature)
        {
            const char* typeName = typeid(T).name();

            assert(mSystems.find(typeName) != mSystems.end() && "System used before registered.");

            // Set the signature for this system
            mSignatures.insert({typeName, signature});
        }

        void EntityDestroyed(Entity entity);
        void EntitySignatureChanged(Entity entity, Signature entitySignature);

    private:
        // Map from system type string pointer to a signature
        std::unordered_map<const char*, Signature> mSignatures{};

        // Map from system type string pointer to a system pointer
        std::unordered_map<const char*, std::shared_ptr<System>> mSystems{};
};
#endif /* !SYSTEMMANAGER_HPP_ */

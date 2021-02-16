/*
** EPITECH PROJECT, 2020
** B-CPP-501-MPL-5-1-rtype-balthazard.grego
** File description:
** IComponentArray
*/

#ifndef ICOMPONENTARRAY_HPP_
#define ICOMPONENTARRAY_HPP_

#include "EntityManager.hpp"

class IComponentArray
{
    public:
	    virtual ~IComponentArray() = default;
	    virtual void EntityDestroyed(Entity entity) = 0;
};

#endif /* !ICOMPONENTARRAY_HPP_ */

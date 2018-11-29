#pragma once

#include <string>
#include <map>

#include "entity.h"
#include "../resourcemanager/resourcemanager.h"

class EntityManager {
public:
    EntityManager(ResourceManger* resourceManager);

    

    virtual ~EntityManager();
private:
    std::map<unsigned short int, Entity> m_activeEntities;
    ResourceManger* resourceManger;
};

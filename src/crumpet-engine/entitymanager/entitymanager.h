#ifndef _ENTITYMANAGER_ENTITYMANAGER_H_
#define _ENTITYMANAGER_ENTITYMANAGER_H_

#include <string>
#include <map>

#include "entity.h"

class EntityManager {
public:
    EntityManager(ResourceManger* resourceManager);
    
    int registerEntity(Entity* entity);

    virtual ~EntityManager();
private:
    std::map<unsigned short int, Entity*> m_activeEntities;
    ResourceManger* resourceManger;
};

#endif

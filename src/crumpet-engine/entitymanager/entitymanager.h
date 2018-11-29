#pragma once

#include <string>
#include <iostream>
#include <map>
#include <vector>

#include "entity.h"

class EntityManager {
public:
    EntityManager():

    virtual ~EntityManager();
private:
    std::map<std::string, Entity> m_activeEntities;
};

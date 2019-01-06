#ifndef _ENTITYMANAGER_BASE_H_
#define _ENTITYMANAGER_BASE_H_

#include <string>
#include "../math.h"

#include "../resourcemanager/resourcemanager.h"

class EntityBase {
public:
    EntityBase();

    Texture* texture;

    virtual ~EntityBase();
private:
};

#endif

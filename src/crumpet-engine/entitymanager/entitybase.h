#pragma once

#include <string>

class EntityBase {
public:
    EntityBase();

    std::string texture;

    virtual ~EntityBase();
};

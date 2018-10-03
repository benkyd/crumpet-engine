#pragma once

#include <vector>
#include "camera.h"

class GameWorld {
public:
	GameWorld();
	virtual ~GameWorld();
private:
	std::vector<Camera*> m_cameras;
};

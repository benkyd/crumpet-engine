#pragma once

#include <vector>
#include <SDL.h>
#include "mathHelper.h"

class Camera {
public:
	Camera();
	Vec2* Pos;
	virtual ~Camera();
private:
	SDL_Rect* m_veiw;
};

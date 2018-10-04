#pragma once

#include <vector>
#include <SDL.h>
#include "mathHelper.h"

struct AspectRatio {
	int w, h;
	AspectRatio(int w, int h) : w(w), h(h) {}
};

class Camera {
public:
	Camera() {
		this->Zoom = 1.0f;
		this->Pos = new Vec2(0, 0);
		this->Rotation = 1.0f;
		this->Aspectratio = new AspectRatio(16, 9);
	}
	Vec2* Pos;
	float Zoom;
	float Rotation;
	AspectRatio* Aspectratio;

	virtual ~Camera();
private:
	SDL_Rect* m_veiw;
};

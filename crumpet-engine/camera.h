#pragma once

#include <vector>
#include "mathHelper.h"
#include "rect.h"

class Camera {
public:
	Camera(int screenWidth, int screenHeight);
	void TranslateView(Vec2* offset);
	void TranslateViewX(int x);
	void TranslateViewY(int y);
	void SetSize(Vec2* size);

	void SetCenter(Vec2* point);

	Rect GetRect();
	int GetX();
	int GetY();
	int GetW();
	int GetH();

	//TODO: zoom zooms everything, regardless of position or size
	//it should zoom relative to objects in the active game scene
	// float Zoom = 1;

	virtual ~Camera();
private:
	Rect* m_view;
};

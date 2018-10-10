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

	virtual ~Camera();
private:
	Rect* m_view;
};

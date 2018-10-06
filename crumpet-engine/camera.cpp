#include "camera.h"

Camera::Camera(int screenWidth, int screenHeight) {
	Rect* res = new Rect(0, 0, screenWidth, screenHeight);
	m_view = res;
}

void Camera::TranslateView(Vec2* offset) {
	m_view->Translate(offset);
}

void Camera::TranslateViewX(int x) {
	m_view->TranslateX(x);
}

void Camera::TranslateViewY(int y) {
	m_view->TranslateY(y);
}

void Camera::SetSize(Vec2* size) {
	m_view->SetSize(size);
}

void Camera::SetCenter(Vec2* point) {
	m_view->x = (point->x - m_view->CenterX());
	m_view->y = (point->y - m_view->CenterY());
}

int Camera::GetX() {
	return m_view->x;
}

int Camera::GetY() {
	return m_view->y;
}

int Camera::GetW() {
	return m_view->w;
}

int Camera::GetH() {
	return m_view->h;
}

Camera::~Camera() {

}

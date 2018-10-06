#pragma once

const float DEG2RAD = 0.01745329251994329576923690768f;
const float RAD2DEG = 57.2957795130823208767981548141f;

inline float ToRadian(const float Degree) {
	return (Degree * DEG2RAD);
}

inline float ToDegree(const float Radian) {
	return (Radian * RAD2DEG);
}

struct Vec4 {
	int x, y, z, w;
	Vec4(int x, int y, int z, int w) : x(x), y(y), z(z), w(w) {}
};

struct Vec4f {
	float x, y, z, w;
	Vec4f(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}
};

struct Vec3 {
	int x, y, z;
	Vec3(int x, int y, int z) : x(x), y(y), z(z) {}
};

struct Vec3f {
	float x, y, z;
	Vec3f(float x, float y, float z) : x(x), y(y), z(z) {}
};

struct Vec2 {
	int x, y;
	Vec2(int x, int y) : x(x), y(y) {}
};

struct Vec2f {
	float x, y;
	Vec2f(float x, float y) : x(x), y(y) {}
};

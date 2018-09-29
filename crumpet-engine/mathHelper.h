#pragma once

struct Vec4 {
	Vec4(int x, int y, int z, int w) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	int x, y, z, w;
};

struct Vec4f {
	Vec4f(float x, float y, float z, float w) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	float x, y, z, w;
};

struct Vec3 {
	Vec3(int x, int y, int z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	int x, y, z;
};

struct Vec3f {
	Vec3f(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	float x, y, z;
};

struct Vec2 {
	Vec2(int x, int y) {
		this->x = x;
		this->y = y;
	}

	int x, y;
};

struct Vec2f {
	Vec2f(float x, float y) {
		this->x = x;
		this->y = y;
	}

	float x, y;
};

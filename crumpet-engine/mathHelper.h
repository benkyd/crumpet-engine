#pragma once

struct Vec3 {
	Vec3(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	float x;
	float y;
	float z;
};

struct Vec2 {
	Vec2(float x, float y) {
		this->x = x;
		this->y = y;
	}

	float x;
	float y;
};

/* struct Vec2SInt16 {
	Vec2SInt16(Sint16 x, Sint16 y) {
		this->x = x;
		this->y = y;
	}

	Sint16 x;
	Sint16 y;
};

struct Vec2UInt16 {
	Vec2UInt16(Uint16 x, Uint16 y) {
		this->x = x;
		this->y = y;
	}

	Uint16 x;
	Uint16 y;
};

struct RectVect {
	RectVect(Vec2SInt16 pos, Vec2UInt16 size)
		: pos(1, 1),
		  size(1, 1) {
		this->pos = pos;
		this->size = size;
	}

	Vec2SInt16 pos;
	Vec2UInt16 size;
}; */

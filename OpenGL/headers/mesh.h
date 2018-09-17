#pragma once

#include <iostream>
#include <GL/glew.h>

class Mesh {
public:
	Mesh(GLfloat *vertices, unsigned int numVerticies);
	void Draw();
	virtual ~Mesh();
private:
	enum {
		POSITION_VB,
		NUM_BUFFERS
	};

	unsigned int m_VAO;
	unsigned int m_VBO[NUM_BUFFERS];

	unsigned int m_drawCount;
};

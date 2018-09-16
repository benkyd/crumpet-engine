#pragma once

#include <iostream>
#include <vector>
#include <glm/glm.hpp>
#include <GL/glew.h>

class Mesh {
public:
	Mesh(GLfloat *vertices, unsigned int *indices, unsigned int numVerticies);
	void Draw();
	virtual ~Mesh();
private:
	enum {
		POSITION_VB,
		NUM_BUFFERS,
		TEXCOORD_VB
	};

	unsigned int m_VAO;
	unsigned int m_VBO;
	unsigned int m_EBO;

	unsigned int m_drawCount;
};

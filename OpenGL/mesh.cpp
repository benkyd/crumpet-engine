#include "mesh.h"

Mesh::Mesh(GLfloat *vertices, unsigned int *indices, unsigned int numVerticies) {
	m_drawCount = numVerticies;

	glGenVertexArrays(1, &m_VAO);
	glBindVertexArray(m_VAO);

	glGenBuffers(NUM_BUFFERS, m_VBO);
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO[POSITION_VB]);
	glBufferData(GL_ARRAY_BUFFER, numVerticies * sizeof(vertices[0]), vertices, GL_STATIC_DRAW);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	std::cout << "Mesh loaded successfully" << std::endl;
}

void Mesh::Draw() {
	glBindVertexArray(m_VAO);
	glDrawArrays(GL_TRIANGLES, 0, m_drawCount);
	glBindVertexArray(0);
}

Mesh::~Mesh() {
	glDeleteVertexArrays(1, &m_VAO);
}

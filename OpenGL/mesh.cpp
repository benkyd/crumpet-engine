#include "headers/mesh.h"

Mesh::Mesh(GLfloat *vertices, unsigned int numVerticies) {
	m_drawCount = numVerticies;

	glGenVertexArrays(1, &m_VAO);
	glBindVertexArray(m_VAO);

	glGenBuffers(NUM_BUFFERS, m_VBO);
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO[POSITION_VB]);
	glBufferData(GL_ARRAY_BUFFER, numVerticies * sizeof(vertices[0]), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
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

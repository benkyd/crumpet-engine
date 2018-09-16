#include <iostream>
#include <GL/glew.h>

#include "display.h"
#include "mesh.h"
#include "shader.h"

#undef main

int main(int argc, char** argv) {
	Display display(800, 600, "Crumpet Engine");
	glClearColor(0.1f, 0.45f, 0.9f, 1.0f);

	GLfloat vertices[] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f,  0.5f, 0.0f
	};

	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));
	Shader shader;

	while(!display.isClosed()) {
		glClear(GL_COLOR_BUFFER_BIT);

		shader.Bind();
		mesh.Draw();

		display.Update();
	}

	return 0;
}

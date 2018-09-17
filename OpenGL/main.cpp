#include <iostream>
#include <GL/glew.h>

#include "display.h"
#include "mesh.h"
#include "shader.h"
#include "texture.h"

#undef main

int main(int argc, char** argv) {
	Display display(600, 600, "Crumpet Engine");
	glClearColor(0.1f, 0.45f, 0.9f, 1.0f);

	GLfloat vertices[] = {
		// positions         // colors          // texture coords
		0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,  1.0f, 1.0f,   // top right
		0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,  1.0f, 0.0f,   // bottom right
		-0.5f,-0.5f, 0.0f,   0.0f, 0.0f, 1.0f,  0.0f, 0.0f,   // bottom left
		
		0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,  1.0f, 1.0f,   // top right
		-0.5f,-0.5f, 0.0f,   0.0f, 0.0f, 1.0f,  0.0f, 0.0f,   // bottom left
		-0.5f, 0.5f, 0.0f,   1.0f, 1.0f, 0.0f,  0.0f, 1.0f    // top left 
	
		// 0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // bottom right
		//-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // bottom left
		// 0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // top 
	};

	unsigned int indices[] = {
		0, 1, 3, // first triangle
		1, 2, 3  // second triangle
	};

	enum class ShaderMode {
		SHADER_TEXURE,
		SHADER_COLOUR,
		SHADER_GRADIENT,
		SHADER_TEXGRADIENT
	};

	ShaderMode mode = ShaderMode::SHADER_COLOUR;

	Mesh mesh(vertices, indices, sizeof(vertices) / sizeof(vertices[0]));
	Texture chanceCube("C:/Users/Ben/Desktop/crumpet-engine/resources/textures/chance-cube.jpg");

	Shader shader("C:/Users/Ben/Desktop/crumpet-engine/resources/shaders/simple2d");


	unsigned int ticks = SDL_GetTicks();
	unsigned int frames = 0;
	while(!display.isClosed()) {
		glClear(GL_COLOR_BUFFER_BIT);

		switch(mode) {
		case ShaderMode::SHADER_TEXURE:
			break;
		case ShaderMode::SHADER_COLOUR:
			break;
		case ShaderMode::SHADER_GRADIENT:
			break;
		case ShaderMode::SHADER_TEXGRADIENT:
			break;
		default:
			break;
		}

		shader.Bind();
		
		chanceCube.Bind(0);
		mesh.Draw();


		display.Update();
		frames++;
	}

	display.~Display();
	return 0;
}

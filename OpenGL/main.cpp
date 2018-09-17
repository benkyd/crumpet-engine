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

	// std::string resourceFolder = "C:/Users/Ben/Desktop/crumpet-engine/"; // Laptop
	std::string resourceFolder = "E:/Games/Practicing/OpenGL/"; // PC

	
	Shader texShader(resourceFolder + "resources/shaders/tex");
	Shader colourShader(resourceFolder + "resources/shaders/col");
	Shader gradientShader(resourceFolder + "resources/shaders/gradient");
	Shader texGradientShader(resourceFolder + "resources/shaders/texGrad");
	
	Texture chanceCube(resourceFolder + "resources/textures/chance-cube.jpg");

	SDL_Event event;
	while(!display.isClosed()) {
		glClear(GL_COLOR_BUFFER_BIT);

		switch(mode) {
		case ShaderMode::SHADER_TEXURE:
			chanceCube.Bind(0);
			texShader.Bind();
			break;
		case ShaderMode::SHADER_COLOUR:
			colourShader.Bind();
			break;
		case ShaderMode::SHADER_GRADIENT:
			gradientShader.Bind();
			break;
		case ShaderMode::SHADER_TEXGRADIENT:
			chanceCube.Bind(0);
			texGradientShader.Bind();
			break;
		}

		mesh.Draw();

		while (SDL_PollEvent(&event) != 0) {
			if (event.type == SDL_KEYDOWN) {
				if (mode == ShaderMode::SHADER_TEXURE) mode = ShaderMode::SHADER_COLOUR;
				else if (mode == ShaderMode::SHADER_COLOUR) mode = ShaderMode::SHADER_GRADIENT;
				else if (mode == ShaderMode::SHADER_GRADIENT) mode = ShaderMode::SHADER_TEXGRADIENT;
				else if (mode == ShaderMode::SHADER_TEXGRADIENT) mode = ShaderMode::SHADER_TEXURE;
				if (event.key.keysym.sym == SDLK_ESCAPE) {
					display.~Display();
				}
			}
		}


		display.Update();
	}

	display.~Display();
	return 0;
}

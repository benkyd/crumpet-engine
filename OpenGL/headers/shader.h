#pragma once

#include <string>
#include <iostream>
#include <GL/glew.h>

class Shader {
public:
	Shader();
	void Bind();
	virtual ~Shader();
private:
	static const unsigned int NUM_SHADERS = 2;
	GLuint CreateShader(const std::string& text, GLenum shaderType);

	std::string LoadFile(std::string path);

	GLuint m_program;
	GLuint m_shaders[NUM_SHADERS];
	// 0 = vertex, 1 = fragment
};


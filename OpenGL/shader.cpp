#include "headers/shader.h"

const char *vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
const char *fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.25f, 1.0f, 0.49f, 1.0f);\n"
"}\n\0";

Shader::Shader() {
	m_program = glCreateProgram();
	m_shaders[0] = CreateShader(vertexShaderSource, GL_VERTEX_SHADER);
	m_shaders[1] = CreateShader(fragmentShaderSource, GL_FRAGMENT_SHADER);

	for (unsigned int i = 0; i < NUM_SHADERS; i++) {
		glAttachShader(m_program, m_shaders[i]);
		std::cout << "Shader successfully attatched" << std::endl;
	}

	glLinkProgram(m_program);

	int success;
	char infoLog[512];
	glGetProgramiv(m_program, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(m_program, 512, NULL, infoLog);
		std::cout << "Shader program linking failed" << infoLog << std::endl;
	}
	else {
		std::cout << "Shader(s) successfully linked" << std::endl;
		std::cout << "Shader program successfully loadedd" << std::endl;
	}
}

GLuint Shader::CreateShader(const std::string& text, GLenum shaderType) {
	GLuint shader = glCreateShader(shaderType);

	if (shader == 0) {
		std::cout << "Error creating shader" << std::endl;
	}

	const GLchar* sourceString[1];
	sourceString[0] = text.c_str();

	glShaderSource(shader, 1, sourceString, NULL);
	glCompileShader(shader);

	int success;
	char infoLog[512];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		std::cout << "Shader compilation failed" << infoLog << std::endl;
	}
	else {
		std::cout << "Shader successfully compiled" << std::endl;
	}

	return shader;
}

void Shader::Bind() {
	glUseProgram(m_program);
}

Shader::~Shader() {
	for (unsigned int i = 0; i < NUM_SHADERS; i++) {
		glDetachShader(m_program, m_shaders[i]);
		glDeleteShader(m_shaders[i]);
	}

	glDeleteProgram(m_program);
}

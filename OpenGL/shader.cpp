#include "shader.h"

Shader::Shader(std::string path) {
	std::string vertexPath = path + "_vertex.glsl";
	std::string fragmentPath = path + "_fragment.glsl";

	m_program = glCreateProgram();
	m_shaders[0] = CreateShader(LoadFile(vertexPath), GL_VERTEX_SHADER);
	m_shaders[1] = CreateShader(LoadFile(fragmentPath), GL_FRAGMENT_SHADER);

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

std::string Shader::LoadFile(std::string path) {
	std::ifstream file;
	file.open((path).c_str());

	std::string output;
	std::string line;

	if (file.is_open()) {
		while (file.good()) {
			getline(file, line);
			output.append(line + "\n");
		}
	}
	else {
		std::cout << "Unable to load shader: " << path << std::endl;
	}

	std::cout << "Successfully loaded " + path << std::endl;
	return output;
}

Shader::~Shader() {
	for (unsigned int i = 0; i < NUM_SHADERS; i++) {
		glDetachShader(m_program, m_shaders[i]);
		glDeleteShader(m_shaders[i]);
	}

	glDeleteProgram(m_program);
}

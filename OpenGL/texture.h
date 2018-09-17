#pragma once

#include <string>
#include <GL/glew.h>

class Texture {
public:
	Texture(std::string fileName);

	void Bind(unsigned int unit);

	virtual ~Texture();
private:
	GLuint m_texture;
};


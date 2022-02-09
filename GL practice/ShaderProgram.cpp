#include "ShaderProgram.h"
using namespace std;

ShaderProgram::ShaderProgram()
{
	GLint success;
	GLchar infoLog[512];

	const char* vertexShaderSource =
		"#version 330 core\n"
		"layout(location = 0) in vec4 aPos;"
		"layout(location = 1) in vec4 inColor;"
		"uniform mat4 mat;"
		"out vec4 color;"
		"void main()"
		"{"
		"	vec4 pos = mat * aPos;"
		"	gl_Position = vec4(pos.x, pos.y, pos.z, 1.0f);"
		"	color = inColor;"
		"}";

	GLuint vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "Shader Compile Error (Vertex Shader):\n" << infoLog << std::endl;
	}

	const char* fragmentShaderSource =
		"#version 330 core\n"
		"in vec4 color;"
		"out vec4 FragColor;"
		"void main()"
		"{"
		"	FragColor = color;"
		"}";

	GLuint fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "Shader Compile Error (Fragment Shader):\n" << infoLog << std::endl;
	}

	shaderProgram = glCreateProgram();

	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	glUseProgram(shaderProgram);

	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "Program Link Error:\n" << infoLog << std::endl;
	}
}

GLuint ShaderProgram::getShaderProgram()
{
	return shaderProgram;
}

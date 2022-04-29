#include "ShaderProgram.h"
using namespace std;

ShaderProgram::ShaderProgram()
{
	GLint success;
	GLchar infoLog[512];

	const char* vertexShaderSource =
		"#version 330 core\n"
		"layout(location = 0) in vec4 aPos;"
		"out vec4 color;"
		"uniform mat4 mv;"
		"uniform mat4 p;"
		"void main()"
		"{"
		"	gl_Position = p * mv * aPos;"
		"	color = vec4(aPos.x / 20.0f + 0.5f, 0.8f, aPos.y / 20.0f + 0.5f, 1.0f);"
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
		"out vec4 FragColor;"
		"in vec4 color;"
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

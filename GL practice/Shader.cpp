#include <fstream>
#include "Shader.h"

Shader::Shader(string vertex, string fragment)
{
	string lines = "";
	GLint success;
	GLchar infoLog[512];

	const char* vertexShaderSource = nullptr;
	ifstream vertexFile(vertex.data());
	if (vertexFile.is_open())
	{
		string line;
		while (getline(vertexFile, line))
			lines += line + "\n";
		vertexShaderSource = lines.c_str();
		vertexFile.close();
	}

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

	lines = "";
	const char* fragmentShaderSource = nullptr;
	ifstream fragmentFile(fragment.data());
	if (fragmentFile.is_open())
	{
		string line;
		while (getline(fragmentFile, line))
			lines += line + "\n";
		fragmentShaderSource = lines.c_str();
		fragmentFile.close();
	}

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

	program = glCreateProgram();

	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);
	glLinkProgram(program);

	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(program, 512, NULL, infoLog);
		std::cout << "Program Link Error:\n" << infoLog << std::endl;
	}

	c_param = glGetUniformLocation(program, "c");
	m_param = glGetUniformLocation(program, "m");
	pro_param = glGetUniformLocation(program, "p");
}

GLuint Shader::getCparam()
{
	return c_param;
}

GLuint Shader::getMparam()
{
	return m_param;
}

GLuint Shader::getPROparam()
{
	return pro_param;
}

GLuint Shader::getProgram()
{
	return program;
}
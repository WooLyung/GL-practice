#define GLEW_STATIC
#pragma comment(lib, "glew32s.lib")
#include <gl/glew.h>
#include <gl/glut.h>
#include <math.h>
#include <iostream>
#include "GLUTWindow.h"
using namespace std;

#define LEVEL 5
GLfloat* pos_buffer_data = nullptr;
GLfloat* color_buffer_data = nullptr;
int index = 0;

void addTriangle(
	float x1, float y1, float z1,
	float x2, float y2, float z2,
	float x3, float y3, float z3,
	int color)
{
	pos_buffer_data[index * 9] = x1;
	pos_buffer_data[index * 9 + 1] = y1;
	pos_buffer_data[index * 9 + 2] = z1;
	pos_buffer_data[index * 9 + 3] = x2;
	pos_buffer_data[index * 9 + 4] = y2;
	pos_buffer_data[index * 9 + 5] = z2;
	pos_buffer_data[index * 9 + 6] = x3;
	pos_buffer_data[index * 9 + 7] = y3;
	pos_buffer_data[index * 9 + 8] = z3;

	color_buffer_data[index * 9] = 1 - (z1 + 1.0f) * 0.2f - color * 0.2f;
	color_buffer_data[index * 9 + 1] = 1 - (z1 + 1.0f) * 0.2f - color * 0.2f;
	color_buffer_data[index * 9 + 2] = 1 - (z1 + 1.0f) * 0.2f - color * 0.2f;
	color_buffer_data[index * 9 + 3] = 1 - (z2 + 1.0f) * 0.2f - color * 0.2f;
	color_buffer_data[index * 9 + 4] = 1 - (z2 + 1.0f) * 0.2f - color * 0.2f;
	color_buffer_data[index * 9 + 5] = 1 - (z2 + 1.0f) * 0.2f - color * 0.2f;
	color_buffer_data[index * 9 + 6] = 1 - (z3 + 1.0f) * 0.2f - color * 0.2f;
	color_buffer_data[index * 9 + 7] = 1 - (z3 + 1.0f) * 0.2f - color * 0.2f;
	color_buffer_data[index * 9 + 8] = 1 - (z3 + 1.0f) * 0.2f - color * 0.2f;

	index++;
}

void addTetrahedron(
	float x1, float y1, float z1,
	float x2, float y2, float z2,
	float x3, float y3, float z3,
	float x4, float y4, float z4,
	int level)
{
	if (level == LEVEL)
	{
		addTriangle(x1, y1, z1, x2, y2, z2, x3, y3, z3, 1);
		addTriangle(x4, y4, z4, x2, y2, z2, x3, y3, z3, 2);
		addTriangle(x1, y1, z1, x2, y2, z2, x4, y4, z4, 3);
		addTriangle(x1, y1, z1, x4, y4, z4, x3, y3, z3, 4);
		return;
	}

	addTetrahedron(x1, y1, z1, (x1 + x2) * 0.5f, (y1 + y2) * 0.5f, (z1 + z2) * 0.5f, (x1 + x3) * 0.5f, (y1 + y3) * 0.5f, (z1 + z3) * 0.5f, (x1 + x4) * 0.5f, (y1 + y4) * 0.5f, (z1 + z4) * 0.5f, level + 1);
	addTetrahedron((x1 + x2) * 0.5f, (y1 + y2) * 0.5f, (z1 + z2) * 0.5f, x2, y2, z2, (x3 + x2) * 0.5f, (y3 + y2) * 0.5f, (z3 + z2) * 0.5f, (x4 + x2) * 0.5f, (y4 + y2) * 0.5f, (z4 + z2) * 0.5f, level + 1);
	addTetrahedron((x1 + x3) * 0.5f, (y1 + y3) * 0.5f, (z1 + z3) * 0.5f, (x3 + x2) * 0.5f, (y3 + y2) * 0.5f, (z3 + z2) * 0.5f, x3, y3, z3, (x4 + x3) * 0.5f, (y4 + y3) * 0.5f, (z4 + z3) * 0.5f, level + 1);
	addTetrahedron((x1 + x4) * 0.5f, (y1 + y4) * 0.5f, (z1 + z4) * 0.5f, (x4 + x2) * 0.5f, (y4 + y2) * 0.5f, (z4 + z2) * 0.5f, (x4 + x3) * 0.5f, (y4 + y3) * 0.5f, (z4 + z3) * 0.5f, x4, y4, z4, level + 1);
}

void shaderInit()
{
	GLint success;
	GLchar infoLog[512];

	const char* vertexShaderSource =
		"#version 330 core\n"
		"layout(location = 0) in vec3 aPos;"
		"layout(location = 1) in vec3 inColor;"
		"out vec4 color;"
		"void main()"
		"{"
		"	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0f);"
		"	color = vec4(inColor.r, inColor.g, inColor.b, 1.0f);"
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

	GLuint shaderProgram;
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

void init()
{
	glEnable(GL_DEPTH_TEST);

	shaderInit();

	GLuint abuffer;
	glGenVertexArrays(1, &abuffer);
	glBindVertexArray(abuffer);

	pos_buffer_data = new GLfloat[9 * pow(4, LEVEL)];
	color_buffer_data = new GLfloat[9 * pow(4, LEVEL)];
	addTetrahedron(0.0f, 1.0f, 0.0f, 0.0f, 0.0f, -1.0f, -1.0f, -1.0f, 1.0f, 1.0f, -1.0f, 1.0f, 1);

	GLuint* buffer = new GLuint[2];
	glGenBuffers(2, buffer);

	glBindBuffer(GL_ARRAY_BUFFER, buffer[0]);
	glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(GLfloat) * pow(4, LEVEL), pos_buffer_data, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, buffer[1]);
	glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(GLfloat) * pow(4, LEVEL), color_buffer_data, GL_STATIC_DRAW);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glDrawArrays(GL_TRIANGLES, 0, 9 * pow(4, LEVEL));
	glFlush();
}

int main(int argc, char** argv)
{
	GLUTWindow* window = new GLUTWindow(argc, argv, display);
	glewInit();
	init();
	window->Start();
}